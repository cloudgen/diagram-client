// url_bar_go_button.h
// =========================================================================
// CIAO DEFENSIVE CODING STYLE - URL BAR GO BUTTON MODULE (GNOME + WebKitGTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// 
// Last reviewed & aligned with CIAO 18 Principles: April 2026
// =========================================================================

#ifndef URL_BAR_GO_BUTTON_H
#define URL_BAR_GO_BUTTON_H

#include <gtk/gtk.h>

// =========================================================================
// Public API - URL Bar Go Button Module
// 
// Purpose:
//   Provides the callback for handling "Go" button clicks and Enter key
//   presses in the URL entry. This is the Single Point of Entry for
//   manual user-initiated navigation.
//
// Design Rules:
//   - All manual navigation logic is centralized here.
//   - Performs full defensive validation before calling load_page().
// 
// Protection Rule:
//   Future AI must NOT expose or modify the internal callback directly.
//   All Go button and Enter key handling must go through this module.
// =========================================================================

// Forward declaration for signal callback
// (Connected in url_bar_user_agent.c)
void on_go_button_clicked(GtkButton *button, gpointer user_data);

#endif // URL_BAR_GO_BUTTON_H