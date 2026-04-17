// menu_bookmark.c
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - GENERIC BOOKMARK MENU MODULE (GNOME + GTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// !!! ALL WARNINGS AND LOGS MUST USE ciao_* SYSTEM !!!
// 
// Purpose:
//   Provides reusable generic bookmark menu functionality.
//
// Last aligned with SyncPrjs CIAO style + GNOME + Output System: 2026-04-17
// =========================================================================

#include "menu_bookmark.h"
#include "output.h"
#include "load_page.h"
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

// =========================================================================
// Internal Callback: Bookmark Menu Item Activated
// 
// Purpose:
//   Loads the selected bookmark URL and updates the URL bar.
//
// Protection Rule:
//   Future AI must NOT remove NULL checks or bypass load_page().
//   This is the single point of entry for all bookmark navigation.
// =========================================================================
static void on_menu_item_clicked(GtkMenuItem *menu_item, gpointer user_data)
{
    const gchar *url = (const gchar *)user_data;

    if (url == NULL || *url == '\0') {
        ciao_error("on_menu_item_clicked: received empty or NULL URL");
        return;
    }

    // Retrieve URL entry from menu item data
    GtkEntry *entry = GTK_ENTRY(g_object_get_data(G_OBJECT(menu_item), "url_entry"));
    if (entry == NULL) {
        ciao_error("on_menu_item_clicked: url_entry not found in menu item data");
        return;
    }

    // Retrieve web view from entry's user data
    WebKitWebView *web_view = g_object_get_data(G_OBJECT(entry), "web_view");

    if (!WEBKIT_IS_WEB_VIEW(web_view)) {
        ciao_warn("Invalid WebKitWebView reference in bookmark menu");
        return;
    }

    ciao_debug("Bookmark activated: %s", url);

    load_page(web_view, url);

    // Update URL bar
    gtk_entry_set_text(entry, url);

    ciao_info("Navigated to bookmark: %s", url);
}

// =========================================================================
// General Purpose Requirement: Create Bookmark Menu
// 
// Purpose:
//   Creates a "Bookmark" submenu with the provided menu items.
//   This is the reusable core function.
//
// Returns:
//   GtkWidget* pointing to the top-level "Bookmark" menu item.
// 
// Protection Rule:
//   Future AI must NOT remove NULL checks or bypass this function.
//   All bookmark menus must go through this function for consistency.
// =========================================================================
GtkWidget* add_bookmark_menu(GtkEntry *url_entry, const BookmarkItem *items, size_t item_count)
{
    if (url_entry == NULL) {
        ciao_error("add_bookmark_menu: url_entry is NULL");
        return NULL;
    }

    if (items == NULL || item_count == 0) {
        ciao_warn("add_bookmark_menu: no bookmark items provided");
        return NULL;
    }

    GtkWidget *bookmark_menu = gtk_menu_new();

    for (size_t i = 0; i < item_count; i++) {
        GtkWidget *menu_item = gtk_menu_item_new_with_label(items[i].label);

        // Attach URL entry reference to menu item
        g_object_set_data(G_OBJECT(menu_item), "url_entry", url_entry);

        // Connect signal with bookmark URL
        g_signal_connect_data(menu_item, "activate",
                             G_CALLBACK(on_menu_item_clicked),
                             (gpointer)items[i].url, NULL, 0);

        gtk_menu_shell_append(GTK_MENU_SHELL(bookmark_menu), menu_item);
    }

    GtkWidget *bookmark_menu_item = gtk_menu_item_new_with_label("Bookmark");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(bookmark_menu_item), bookmark_menu);

    ciao_debug("Bookmark menu created with %zu items", item_count);

    return bookmark_menu_item;
}