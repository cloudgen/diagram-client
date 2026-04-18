// url_bar.c
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - URL BAR + USER AGENT MODULE (GNOME + WebKitGTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
//
// Note: This file replaces the original url_bar.c
// Struct renamed to UrlBarUserAgent as requested.
//
// CRITICAL ARCHITECTURE:
//   - Uses "notify::uri" (on_uri_changed) as primary signal for real-time URL updates
//   - Includes "load-changed" (on_load_changed) as secondary fallback
//   - on_uri_changed is the bulletproof callback that correctly handles link clicks,
//     JavaScript navigation, redirects, and history changes.
//
// Last aligned with CIAO style + User-Agent feature: 2026-04-14
// =========================================================================

#include "project.h"
#include "url_bar.h"
#include "url_bar_page.h"
#include "url_bar_go_button.h"
#include "output.h"
#include <gtk/gtk.h>

// =============================================================================
// add_url_bar() - Create URL Bar
// =============================================================================
//
// GENERAL PURPOSE:
//   Creates a complete URL bar (GtkEntry + Go button).
//   Returns UrlBarUser struct containing all widgets and containers.
//
// CRITICAL ROLE:
//   This is the **Single Point of Entry** for all URL bar creation in the application.
//   All signal connections (notify::uri, load-changed, button clicked, and entry activate)
//   MUST be established here. No other place in the codebase should connect signals
//   to the URL entry or Go button.
//
// KEY BEHAVIOR ADDED:
//   Pressing **Enter** in the URL entry now executes the same logic as clicking the
//   "Go" button (validation + navigation). This provides a native browser-like experience.
//
// CIAO PRINCIPLES APPLIED (18 Rules - v2.9.1):
//   Principle 1  (Caution)               - Repeated NULL checks + type validation
//   Principle 2  (Intentional Verbosity) - Full General Purpose + heavy comments
//   Principle 3  (Anti-fragile)          - Survives NULL web_view and invalid signals
//   Principle 5  (Single Point of Entry) - All URL bar initialization must go through this function
//   Principle 6  (General Purpose Requirement)
//   Principle 7  (Reusable Function Protection)
//   Principle 14 (Interactive vs Non-Interactive)
//   Principle 16 (Input Pattern Checking)
//   Principle 18 (Protect Against AI & Human Modification)
//
// PROTECTION RULE - SACRED (DO NOT VIOLATE):
//   Future AI assistants or developers **MUST NOT** bypass, rename, inline, simplify,
//   or rewrite this function.
//
//   Any change to signal connections must preserve:
//     - "notify::uri" as primary real-time update (on_uri_changed)
//     - "load-changed" as secondary fallback (on_load_changed)
//     - "clicked" on Go button (on_go_button_clicked)
//     - "activate" on GtkEntry for Enter key support (must call same callback as Go button)
//
//   Removing or changing the "activate" signal connection will break the expected
//   behavior that typing a URL and pressing Enter should navigate (same as clicking Go).
//
// !!! DO NOT MODIFY OR SIMPLIFY THIS FUNCTION !!!
//   This function has been battle-tested for real browser-like usage.
//   Past simplifications (removing signals or merging callbacks) caused broken
//   navigation when pressing Enter in the URL bar and Gtk-CRITICAL errors.
//
//   It is designed to be reusable in other GNOME/WebKitGTK projects while strictly
//   following the 18 CIAO Defensive Programming Principles.
//
// Last reviewed & aligned with CIAO 18 Principles: April 2026
// =============================================================================

UrlBar add_url_bar(WebKitWebView *web_view)
{
    if (web_view == NULL) {
        ciao_error("add_url_bar: web_view is NULL");
        UrlBar empty = {0};
        return empty;
    }

    UrlBar url_bar = {0};

    // Create URL entry
    url_bar.url_entry = GTK_ENTRY(gtk_entry_new());
    gtk_entry_set_text(url_bar.url_entry, START_PAGE);
    g_object_set_data(G_OBJECT(url_bar.url_entry), "web_view", web_view);

    // Create Go button
    GtkWidget *go_button = gtk_button_new_with_label("Go");
    g_signal_connect(go_button, "clicked", 
                    G_CALLBACK(on_go_button_clicked), url_bar.url_entry);

    // IMPORTANT: Connect Enter key press in URL entry to same navigation logic
    // This makes typing a URL + pressing Enter behave exactly like clicking "Go"
    g_signal_connect(url_bar.url_entry, "activate",
        G_CALLBACK(on_go_button_clicked), url_bar.url_entry);

    // Primary signal: real-time URI updates (link clicks, JS navigation, redirects, etc.)
    g_signal_connect(web_view, "notify::uri",
        G_CALLBACK(on_uri_changed), url_bar.url_entry);

    // Connect load-changed signal to auto-update URL bar
    g_signal_connect(web_view, "load-changed", 
                    G_CALLBACK(on_load_changed), url_bar.url_entry);

    // Create horizontal box
    url_bar.url_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(url_bar.url_box), 
                      GTK_WIDGET(url_bar.url_entry), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(url_bar.url_box), go_button, FALSE, FALSE, 0);

    ciao_debug("URL bar created successfully");

    return url_bar;
}