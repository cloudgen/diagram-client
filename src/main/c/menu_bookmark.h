// menu_bookmark.h
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - GENERIC BOOKMARK MENU MODULE (GNOME + GTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// 
// Last aligned with SyncPrjs CIAO style + GNOME + Output System: 2026-04-17
// =========================================================================

#ifndef MENU_BOOKMARK_H
#define MENU_BOOKMARK_H

#include <gtk/gtk.h>

// =========================================================================
// Bookmark Item Structure
// 
// Purpose:
//   Simple struct to hold label + URL pairs. Used to make bookmark menus
//   data-driven and reusable across different projects.
// 
// Protection Rule:
//   Future AI must NOT add fields or change this struct without updating
//   all call sites. This is the Single Source of Truth for bookmark data.
// =========================================================================
typedef struct {
    const char *label;
    const char *url;
} BookmarkItem;

// =========================================================================
// Public API - Generic Bookmark Menu Module
// 
// Purpose:
//   Provides a reusable bookmark submenu that can be used by any module.
//   Takes an array of BookmarkItem and creates the menu dynamically.
//
// Design Rules:
//   - Only the public function add_bookmark_menu() is exposed.
//   - Internal callback (on_menu_item_clicked) is hidden in .c file.
//   - Uses g_object_set_data for clean GTK context passing.
// 
// Protection Rule:
//   Future AI must NOT expose internal functions or change the public
//   function signature. All bookmark menu creation must go through
//   this function to maintain consistency and defensive checks.
// =========================================================================

// =========================================================================
// Create and return a Bookmark menu item with submenu
// 
// Parameters:
//   url_entry   : The main URL bar (GtkEntry) used to pass context to menu items
//   items       : Array of BookmarkItem structures
//   item_count  : Number of items in the array
// 
// Returns:
//   GtkWidget* - The top-level "Bookmark" menu item (with submenu attached)
// 
// Protection:
//   Performs NULL checks and logs via ciao_* output system.
//   All navigation goes through load_page().
// =========================================================================
GtkWidget* add_bookmark_menu(GtkEntry *url_entry, const BookmarkItem *items, size_t item_count);

#endif // MENU_BOOKMARK_H