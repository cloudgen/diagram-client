# =============================================================================
# meson.build - Meson build definition for diagram-client (CIAO style)
# =============================================================================
#
# This follows CIAO defensive coding principles:
#   - All source files are explicitly listed (Single Source of Truth)
#   - Proper dependency handling for GTK+ 3 + WebKit2GTK
#   - No reliance on wildcard globbing (anti-fragile)
#   - Clear separation of concerns
#
# Usage:
#   meson setup builddir
#   meson compile -C builddir
#   meson install -C builddir
#
# Last updated: 2026-04-17
# =============================================================================

project('diagram-client',
    'c',
    version: '',          # Matches your project.h VERSION
    license: 'MIT',
    default_options: [
        'warning_level=3',
        'buildtype=debugoptimized',
        'c_std=c11'
    ]
)

# Dependencies
gtk_dep = dependency('gtk+-3.0', required: true)
webkit_dep = dependency('webkit2gtk-4.1', required: true)

dependencies = [gtk_dep, webkit_dep]

# === ALL SOURCE FILES (must include every .c file that defines a function) ===
src_files = files(
    'src/main/c/main.c',
    'src/main/c/output.c',
    'src/main/c/cookies.c',
    'src/main/c/dialog_version.c',
    'src/main/c/load_page.c',
    'src/main/c/menu_exit.c',
    'src/main/c/menu_bookmark.c',
    'src/main/c/menu_bookmark_diagram.c',
    'src/main/c/menu_user_agent.c',
    'src/main/c/url_bar_go_button.c',
    'src/main/c/url_bar_page.c',
    'src/main/c/url_bar_user_agent.c'
)

# Build the executable
executable('diagram-client',
    sources: src_files,
    dependencies: dependencies,
    install: true,
    install_dir: get_option('bindir')
)

# Optional: nice install message
meson.add_install_script('sh', '-c', 
    'echo "diagram-client installed successfully to ${MESON_INSTALL_PREFIX}/bin/diagram-client"'
)