# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed
- Simplified the URL bar by removing User-Agent display and spoofing functionality.
- User-Agent spoofing menu and advanced URL bar features have been moved to the more complete **[youtube-client](https://github.com/cloudgen/youtube-client)** project (which shares the same CIAO architecture).
- Updated `main.c`, `url_bar.c`, and related modules to use the simpler URL bar implementation.
- Removed `url_bar_user_agent.c`, `url_bar_user_agent.h`, `menu_user_agent.c`, and `menu_user_agent.h`.

### Documentation
- Updated README.md to clearly indicate the removal of User-Agent features and redirect to youtube-client.

---

## [1.0.4] - 2026-04-18

### Added
- Strong defensive protection comments ("SACRED", "Protection Rule", "DO NOT MODIFY") across URL bar callbacks (`on_go_button_clicked`, `on_uri_changed`, `on_load_changed`, `add_url_bar`) to guard against accidental simplification by AI or future maintainers.
- Flexible callback architecture using `url_bar_callbacks.h` for better cross-file signal handling while maintaining external linkage.
- Improved real-time URL bar synchronization with `notify::uri` as the primary signal and `load-changed` as a reliable fallback.
- Enter key support in the URL bar (now behaves exactly like clicking the "Go" button).

### Changed
- Bumped version to 1.0.4.
- Enhanced CIAO compliance in URL bar module (18 defensive principles applied).
- Updated menu structure in `main.c` (removed User-Agent submenu reference in preparation for simplification).
- Refined output messages and debug logging for clarity.

### Fixed
- Potential Gtk-CRITICAL assertions related to signal handling and entry validation.
- Edge cases in URL bar updates during internal page navigation, JavaScript redirects, and link clicks.

---

## [1.0.0] - 2026-04-12

### Added
- Initial release of **diagram-client** — a lightweight native GNOME/WebKitGTK wrapper for **diagrams.net** (formerly draw.io).
- Persistent cookie storage using SQLite (`~/.app/diagramclient/cookies/`).
- Basic URL bar with "Go" button and real-time synchronization.
- Quick bookmark menu for common diagrams.net pages.
- Clean GNOME-style menu bar (File → Bookmark / Exit, About → Show Version).
- Centralized defensive output system (`ciao_*` functions with `--quiet`, `--json`, and `DEBUG=1` support).
- Full **CIAO Defensive Programming Style** applied across the entire codebase.

### Features
- Modern GTK+ 3 + WebKit2GTK 4.1 integration
- No Electron bloat — significantly lower resource usage
- Session persistence (cookies survive application restarts)
- Multi-build-system support (Meson recommended)

---

## How to Maintain This File

When making a new release:
1. Move the `[Unreleased]` section content into a new version header with today's date.
2. Add a fresh `[Unreleased]` section at the top.
3. Use these categories (in recommended order): **Added**, **Changed**, **Improved**, **Deprecated**, **Removed**, **Fixed**, **Security**.

---

**Project**: [cloudgen/diagram-client](https://github.com/cloudgen/diagram-client)  
**Philosophy**: Built with strict **CIAO** (Caution • Intentionality • Anti-fragility • Over-engineering) principles

**Last updated:** 2026-04-18

Made with ❤️ and extreme caution.