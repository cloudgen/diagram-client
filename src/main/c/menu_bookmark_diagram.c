// menu_bookmark_diagram.c
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - DIAGRAM BOOKMARK MENU MODULE (GNOME + GTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// !!! ALL WARNINGS AND LOGS MUST USE ciao_* SYSTEM !!!
// 
// Last aligned with SyncPrjs CIAO style + GNOME + Output System: 2026-04-12
// =========================================================================

#include "menu_bookmark_diagram.h"
#include "menu_bookmark.h"
#include "output.h"
#include "project.h"
#include <gtk/gtk.h>

// =========================================================================
// General Purpose Requirement: Create Diagram.net Bookmark Menu
// 
// Purpose:
//   Creates a "Bookmark" submenu with predefined diagram.net related links.
//
// Returns:
//   GtkWidget* pointing to the top-level "Bookmark" menu item.
// 
// Protection Rule:
//   Future AI must NOT hardcode menu items here. Use add_bookmark_menu().
// =========================================================================
GtkWidget* add_bookmark_menu_diagram(GtkEntry *url_entry)
{
    if (url_entry == NULL) {
        ciao_error("add_bookmark_menu_diagram: url_entry is NULL");
        return NULL;
    }

    // Define diagram-specific bookmarks (Single Source of Truth for this project)
    static const BookmarkItem diagram_bookmarks[] = {
        { "Start Page",     START_PAGE }
        // Add more diagram.net specific bookmarks here in the future
    };

    size_t item_count = sizeof(diagram_bookmarks) / sizeof(diagram_bookmarks[0]);

    return add_bookmark_menu(url_entry, diagram_bookmarks, item_count);
}