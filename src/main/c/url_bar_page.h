// url_bar_page.h
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - URL BAR PAGE UPDATE MODULE (GNOME + WebKitGTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// 
// Last reviewed & aligned with CIAO 18 Principles: April 2026
// =========================================================================

#ifndef URL_BAR_PAGE_H
#define URL_BAR_PAGE_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

// =========================================================================
// Public API - URL Bar Page Update Module
// 
// Purpose:
//   Provides callbacks for updating the URL bar based on WebKitWebView
//   navigation events (notify::uri and load-changed).
//
// Design Rules:
//   - "notify::uri" is the primary real-time update mechanism.
//   - "load-changed" serves as a secondary fallback for full page loads.
// 
// Protection Rule:
//   Future AI must NOT expose or modify the internal callback functions
//   directly. All page-related URL bar updates must be connected through
//   the implementation in url_bar_page.c.
// =========================================================================

// Forward declarations for signal callbacks
// (These are connected in url_bar_user_agent.c)
void on_uri_changed(GObject *object, GParamSpec *pspec, gpointer user_data);
void on_load_changed(WebKitWebView *web_view, WebKitLoadEvent load_event, gpointer user_data);

#endif // URL_BAR_PAGE_H