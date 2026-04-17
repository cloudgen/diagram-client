// menu_bookmark_diagram.h
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - DIAGRAM BOOKMARK MENU MODULE (GNOME + GTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// 
// Last aligned with SyncPrjs CIAO style + GNOME + Output System: 2026-04-17
// =========================================================================

#ifndef MENU_BOOKMARK_DIAGRAM_H
#define MENU_BOOKMARK_DIAGRAM_H

#include <gtk/gtk.h>

// =========================================================================
// Public API - Diagram Bookmark Menu Module
// 
// Purpose:
//   Provides a bookmark submenu with quick links specific to diagram.net
//   (Start Page, Profile Page, etc.).
//
// Design Rules:
//   - Only public function is exposed.
//   - Internal callback and generic logic are in menu_bookmark.c.
//   - Uses data passing via g_object_set_data for clean GTK integration.
// 
// Protection Rule:
//   Future AI must NOT expose internal functions or change the public
//   function signature. All diagram.net menu creation must go through
//   this module.
// =========================================================================

// =========================================================================
// Create and return the Diagram Bookmark menu item with submenu
// 
// Parameters:
//   url_entry : The main URL bar (GtkEntry) used to pass context to menu items
// 
// Returns:
//   GtkWidget* - The top-level "Bookmark" menu item (with submenu attached)
// 
// Protection:
//   Performs NULL check in implementation and logs via ciao_output system.
// =========================================================================
GtkWidget* add_bookmark_menu_diagram(GtkEntry *url_entry);

#endif // MENU_BOOKMARK_DIAGRAM_H