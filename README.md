# diagram-client

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/Version-1.0.3-blue.svg)](https://github.com/cloudgen/diagram-client/releases)
[![CIAO](https://img.shields.io/badge/Philosophy-CIAO%20(Caution%20%E2%80%A2%20Intentional%20%E2%80%A2%20Anti--fragile%20%E2%80%A2%20Over--engineered)-purple.svg)](https://github.com/cloudgen/ciao)
[![GTK](https://img.shields.io/badge/UI-GTK%203-brightgreen.svg)](https://gtk.org)
[![WebKit2](https://img.shields.io/badge/Engine-WebKit2GTK-orange.svg)](https://webkitgtk.org)

**diagram-client** is a lightweight, native GNOME desktop application that provides a focused wrapper around **diagrams.net** (formerly draw.io) using **WebKit2GTK**.

It offers a clean, distraction-free window with persistent cookies (so you stay logged in), a smart URL bar that supports the **Enter** key, quick bookmarks, and User-Agent spoofing — all while staying much lighter than Electron-based alternatives.

This project is built according to the strict **[CIAO](https://github.com/cloudgen/ciao)** defensive programming philosophy.

---

## Features

- Embedded WebKit2GTK web view with persistent SQLite cookie storage (`~/.app/diagramclient/cookies/`)
- Smart URL bar with real-time synchronization and **Enter key support**
- User-Agent spoofing menu (Google Chrome as default, plus Firefox, Safari, Edge)
- Quick bookmarks for common diagrams.net pages
- Clean GNOME-style menu bar (File → Bookmark / User Agent / Exit, About → Show Version)
- Defensive, heavily commented codebase designed to resist accidental breakage
- Multi-build-system support (Meson recommended, plus Make, Gradle, Ant, and raw GCC)
- Fully compatible with **SyncPrjs** project synchronization

---

## The CIAO Defensive Programming Philosophy

This project strictly follows the **[CIAO](https://github.com/cloudgen/ciao)** methodology — **Caution • Intentionality • Anti-fragility • Over-engineering** — a set of 18 defensive programming principles created to produce robust, long-lived software that resists both human and AI-induced regressions.

### Why CIAO Was Applied Here

- **Anti-fragile architecture**: Critical paths (URL navigation, signal handling, output system) use multiple defensive checks, fallback mechanisms, and "Single Source of Truth" patterns so the app continues to work even when WebKitGTK or GTK evolves.
- **Protection against simplification**: Every important function contains explicit "Protection Rule" and "DO NOT MODIFY" comments. This guards against well-meaning but harmful "cleanups" — a common issue when AI assistants or future maintainers try to remove "redundant" NULL checks or merge callbacks.
- **Intentional verbosity**: Functions are deliberately detailed with "General Purpose Requirement" blocks, explaining *why* the code exists and what must never be changed. This makes the codebase self-documenting and safer over years.
- **Resistance to linker and runtime errors**: Splitting callbacks across files while maintaining proper linkage (and documenting why `static` must not be added) prevents the recurring build failures seen during refactoring.
- **Long-term maintainability**: Centralized output system (`ciao_*` functions), cookie handling, and version metadata reduce scattered logic and make future extensions safer.

You can explore the full **[18 CIAO Principles](https://github.com/cloudgen/ciao)** and see real-world application examples in the official repository:

→ **[https://github.com/cloudgen/ciao](https://github.com/cloudgen/ciao)**

Many patterns in this project (defensive callbacks, cross-file signal protection, output centralization, and "Protect Against AI & Human Modification") come directly from applying these rules.

---

## Project Background & Credits

- **Author**: Cloudgen Wong ([@cloudgen](https://github.com/cloudgen)) – Hong Kong
- **Philosophy**: Built with strict **CIAO (Caution • Intentional • Anti-fragile • Over-engineered)** principles.  
  See `CIAO-PRINCIPLES.md` in the repository and the official [CIAO repo](https://github.com/cloudgen/ciao).
- **Similar Project**:  
  **[youtube-client](https://github.com/cloudgen/youtube-client)** — Same CIAO architecture and multi-build-system approach.
- **Original Inspiration**: Heavily influenced by Wilgat’s family of “*-client” projects.
- **SyncPrjs Compatibility**: Fully works with **[SyncPrjs](https://github.com/Wilgat/SyncPrjs)** by Wilgat.

---

## Quick Start

### 1. Install dependencies (Ubuntu/Debian)

```bash
sudo apt install meson ninja-build libgtk-3-dev libwebkit2gtk-4.1-dev
```

### 2. Build (Meson + Ninja recommended)

```bash
meson setup builddir
meson compile -C builddir
```

### 3. Run

```bash
./builddir/diagram-client
```

Other build methods are supported via `./build.sh` (Meson, Make, Gradle, Ant, etc.). See the `docs/` folder for detailed guides.

---

## Usage

- Enter a URL in the address bar and press **Enter** (or click **Go**)
- Use **File → Bookmark** for quick navigation
- Use **File → User Agent** to spoof different browser identities
- Cookies and sessions persist automatically between runs
- **About → Show Version** displays version information

---

## Build Methods

Detailed instructions for all supported build systems are in the [`docs/`](docs/) directory:

- [`docs/build-methods.md`](docs/build-methods.md) — Overview
- [`docs/meson-steps.md`](docs/meson-steps.md) — Meson + Ninja (recommended)
- [`docs/basic-steps.md`](docs/basic-steps.md) — Simple GCC
- And more...

---

## Project Structure

## Project Structure

```bash
.
├── build.sh                  # Unified build wrapper script
├── build.xml                 # Ant build file
├── CHANGELOG.md
├── CIAO-PRINCIPLES.md        # Local summary of CIAO rules applied
├── LICENSE.md
├── meson.build               # Meson build definition (recommended)
├── project.ini
├── project.sh
├── README.md
├── SECURITY.md
├── docs/                     # Detailed build and usage guides
│   ├── ant-steps.md
│   ├── basic-steps.md
│   ├── build-methods.md
│   ├── gnu-make-steps.md
│   ├── gradle-steps.md
│   └── meson-steps.md
├── src/
│   └── main/
│       └── c/                # All source code (CIAO modular style)
│           ├── cookies.c
│           ├── cookies.h
│           ├── dialog_version.c
│           ├── dialog_version.h
│           ├── load_page.c
│           ├── load_page.h
│           ├── main.c
│           ├── menu_bookmark.c
│           ├── menu_bookmark.h
│           ├── menu_bookmark_diagram.c
│           ├── menu_bookmark_diagram.h
│           ├── menu_exit.c
│           ├── menu_exit.h
│           ├── menu_user_agent.c
│           ├── menu_user_agent.h
│           ├── output.c
│           ├── output.h
│           ├── project.h     # Single Source of Truth: version, UAs, paths, etc.
│           ├── url_bar_go_button.c
│           ├── url_bar_go_button.h
│           ├── url_bar_page.c
│           ├── url_bar_page.h
│           ├── url_bar_user_agent.c
│           └── url_bar_user_agent.h
└── target/                   # Build output directory (generated)
    └── debug/
        └── diagram-client    # The final executable
```

### Key Design Notes (CIAO Style)

- **`src/main/c/`** — All C sources and headers are kept together in one flat directory for simplicity while maintaining modularity through separate files (each with clear responsibility and protection rules).
- **`project.h`** — The **Single Source of Truth** for project metadata (name, version, default URLs, User-Agent strings, storage paths). No constants are duplicated elsewhere.
- **`target/`** — Generated build artifacts (not committed to version control). Meson/Ninja places the executable here by default in debug builds.
- **Headers & Sources** — Every module has a matching `.h` / `.c` pair following the defensive CIAO pattern (public API in header, implementation + protection comments in `.c`).
- Build system files at root support multiple tools (Meson is preferred for modern GTK development).

This structure keeps the project clean, easy to navigate, and aligned with the **CIAO principles** of intentionality and anti-fragility.

---

## Technologies

- **C11** with strict defensive style
- **GTK+ 3** — Native GNOME UI
- **WebKit2GTK 4.1** — Modern web rendering + cookie persistence
- **CIAO** — Defensive programming principles

---

## Related Projects

- **[youtube-client](https://github.com/cloudgen/youtube-client)** — Same CIAO-based lightweight native client architecture
- Wilgat’s original client projects (pix-client, etc.)
- **[SyncPrjs](https://github.com/Wilgat/SyncPrjs)** — Project synchronization tool

---

**Last updated:** April 2026

Made with ❤️, extreme caution, and deliberate over-engineering.

Happy native diagramming!

---
