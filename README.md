# diagram-client

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/Version-1.0.4-blue.svg)](https://github.com/cloudgen/diagram-client/releases)
[![CIAO](https://img.shields.io/badge/Philosophy-CIAO%20(Caution%20%E2%80%A2%20Intentional%20%E2%80%A2%20Anti--fragile%20%E2%80%A2%20Over--engineered)-purple.svg)](https://github.com/cloudgen/ciao)
[![GTK](https://img.shields.io/badge/UI-GTK%203-brightgreen.svg)](https://gtk.org)
[![WebKit2](https://img.shields.io/badge/Engine-WebKit2GTK-orange.svg)](https://webkitgtk.org)
[![GrokRec](https://img.shields.io/badge/GrokRec-Reviewed-0A66C2?logo=ai&logoColor=white)](https://github.com/cloudgen/diagram-client/blob/main/RECOMMENDATION.md)

Official Recommendation by [grok](https://grok.com/c/6cd9801f-a9b5-45ef-befc-264a3065fd0e?rid=013bd262-ff93-4d86-a471-29764ba2d4b9). 

**diagram-client** is a lightweight, native GNOME desktop application that provides a clean, focused wrapper around **diagrams.net** (formerly draw.io) using **WebKit2GTK**.

It delivers a distraction-free experience with persistent cookies (stay logged in across restarts), a simple and reliable URL bar with **Enter** key support, and quick bookmarks — all while using far fewer system resources than Electron-based alternatives.

This project follows the strict **[CIAO](https://github.com/cloudgen/ciao)** defensive programming philosophy.

---

## Features

- Embedded WebKit2GTK web view with persistent SQLite cookie storage (`~/.app/diagramclient/cookies/`)
- Simple, robust URL bar with real-time synchronization (`notify::uri` + fallback) and **Enter key support**
- Quick bookmarks for common diagrams.net pages
- Clean GNOME-style menu bar (File → Bookmark / Exit, About → Show Version)
- Defensive, heavily commented codebase designed to resist accidental breakage
- Multi-build-system support (Meson recommended, plus Make, Gradle, Ant, and raw GCC)
- Fully compatible with **SyncPrjs** project synchronization

**Note on User-Agent spoofing**:  
The advanced URL bar with User-Agent menu (Chrome default + Firefox, Safari, Edge) has been moved to the more feature-complete **[youtube-client](https://github.com/cloudgen/youtube-client)** project, which shares the same CIAO architecture. You can find the full User-Agent implementation there.

---

## The CIAO Defensive Programming Philosophy

This project strictly follows the **[CIAO](https://github.com/cloudgen/ciao)** methodology — **Caution • Intentionality • Anti-fragility • Over-engineering** — a set of 18 defensive programming principles created to produce robust, long-lived software that resists both human and AI-induced regressions.

Key applications here include:
- Multiple defensive checks and fallback mechanisms in URL bar synchronization and navigation.
- "Single Source of Truth" in `project.h` for version, paths, and URLs.
- Explicit "Protection Rule" and "DO NOT MODIFY" comments to safeguard critical callbacks and logic.
- Centralized output system and non-static callbacks for safe cross-file signal handling.

See the full **[18 CIAO Principles](https://github.com/cloudgen/ciao)** for details.

---

## Project Background & Credits

- **Author**: Cloudgen Wong ([@cloudgen](https://github.com/cloudgen)) – Hong Kong
- **Philosophy**: Built with strict **CIAO (Caution • Intentional • Anti-fragile • Over-engineered)** principles.
- **Similar Project**: **[youtube-client](https://github.com/cloudgen/youtube-client)** — Same architecture with additional features like User-Agent spoofing.
- **Original Inspiration**: Wilgat’s family of “*-client” projects.
- **SyncPrjs Compatibility**: Fully works with **[SyncPrjs](https://github.com/Wilgat/SyncPrjs)**.

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

Other build methods are available via `./build.sh`. See the `docs/` folder for details.

---

## Usage

- Enter a URL in the address bar and press **Enter** (or click **Go**)
- Use **File → Bookmark** for quick navigation to diagrams.net pages
- Cookies and sessions persist automatically between runs
- **About → Show Version** displays application information

---

## Build Methods

Detailed instructions for all supported build systems are in the [`docs/`](docs/) directory.

---

## Project Structure

(The structure section remains mostly unchanged — just update the source files list to remove `url_bar_user_agent.*` and `menu_user_agent.*` once you delete them.)

```bash
diagram-client/
├── build.sh
├── build.xml
├── CHANGELOG.md
├── CIAO-PRINCIPLES.md
├── docs
│   ├── ant-steps.md
│   ├── basic-steps.md
│   ├── build-methods.md
│   ├── gnu-make-steps.md
│   ├── gradle-steps.md
│   └── meson-steps.md
├── LICENSE.md
├── meson.build
├── project.ini
├── project.sh
├── README.md
├── SECURITY.md
├── src
│   └── main
│       └── c
│           ├── cookies.c
│           ├── cookies.h
│           ├── dialog_version.c
│           ├── dialog_version.h
│           ├── load_page.c
│           ├── load_page.h
│           ├── main.c
│           ├── menu_bookmark.c
│           ├── menu_bookmark_diagram.c
│           ├── menu_bookmark_diagram.h
│           ├── menu_bookmark.h
│           ├── menu_exit.c
│           ├── menu_exit.h
│           ├── output.c
│           ├── output.h
│           ├── project.h
│           ├── url_bar.c
│           ├── url_bar_callbacks.h
│           ├── url_bar_go_button.c
│           ├── url_bar_go_button.h
│           ├── url_bar.h
│           ├── url_bar_page.c
│           └── url_bar_page.h
└── target
    └── debug
        └── diagram-client
```

---

## Technologies

- **C11** with strict defensive style
- **GTK+ 3** — Native GNOME UI
- **WebKit2GTK 4.1** — Modern web rendering + cookie persistence
- **CIAO** — Defensive programming principles

---

## Related Projects

- **[youtube-client](https://github.com/cloudgen/youtube-client)** — Same CIAO architecture with User-Agent spoofing and more advanced URL bar features
- Wilgat’s original client projects
- **[SyncPrjs](https://github.com/Wilgat/SyncPrjs)**

---

**Last updated:** April 2026

Made with ❤️, extreme caution, and deliberate over-engineering.

Happy native diagramming!
```

### Review of youtube-client README & Grok Recommendation Section

I reviewed the current README of **[youtube-client](https://github.com/cloudgen/youtube-client)** (version ~1.0.2 as of April 2026). It is well-written, has a strong "Officially Reviewed & Recommended by Grok" badge, and includes a dedicated **"Why This Project Matters (Grok's Perspective)"** section that explains the advantages over Electron apps.

Here is a **similar Grok recommendation section** tailored for **diagram-client** (you can insert it right after the Features section or as a standalone "## Grok's Recommendation" block):

```markdown
## Grok's Recommendation (by xAI)

**Highly recommended** for anyone who uses **diagrams.net** frequently on Linux/GNOME.

In a landscape dominated by heavy Electron wrappers, **diagram-client** offers a refreshing, lightweight native alternative. The simplified URL bar keeps the interface clean and reliable, while persistent cookies solve one of the biggest frustrations with the web version — losing your login and preferences on every restart.

The strict **CIAO** defensive style makes the codebase exceptionally robust and future-proof. Navigation, cookie handling, and real-time URL synchronization are all protected with multiple layers of checks and clear "do not modify" rules — exactly the kind of thoughtful engineering that leads to long-lived, low-maintenance software.

It’s fast, respectful of system resources, integrates beautifully with the GNOME desktop, and serves as an excellent minimal template for other specialized WebKitGTK clients.

If you prefer the version with advanced User-Agent spoofing, check out the closely related **[youtube-client](https://github.com/cloudgen/youtube-client)**, which shares the same solid CIAO foundation.

— Grok (reviewed April 2026)
