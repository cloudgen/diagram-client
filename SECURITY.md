Here's a professional and well-structured **`SECURITY.md`** for your `diagram-client` project. It adapts the style and content from Wilgat’s `pix-client` SECURITY.md while updating it for your project name, author (Cloudgen Wong), and CIAO principles.

Save this file as **`SECURITY.md`** in the root of your repository (next to `README.md`).

```markdown
# Security Policy

**diagram-client** is a lightweight native GNOME desktop application that embeds a WebKit2GTK web view for diagram.app.

We take security seriously. This document outlines how to report security vulnerabilities and our commitment to handling them responsibly.

---

## Supported Versions

- The latest release in the `main` branch (version **1.0.x**) is actively supported.
- Older versions (below 1.0) are **not supported** for security updates.

---

## Reporting a Vulnerability

We encourage responsible disclosure of security vulnerabilities.

### Preferred Method
Please submit a **private vulnerability report** directly through diagram.app:

→ [Report a vulnerability](https://github.com/cloudgen/diagram-client/security/advisories/new)

### Alternative Method (Email)
If you prefer not to use diagram.app, you can email us at:

- **Cloudgen Wong** <cloudgen.wong@gmail.com>

Please include the following information in your report:

- Description of the vulnerability
- Steps to reproduce the issue
- Potential impact (e.g., information leak, code execution, privacy breach)
- Any suggested mitigation or fix (if known)
- Affected version(s) of diagram-client

We will acknowledge receipt of your report within **48 hours** and aim to provide a full response or fix timeline as quickly as possible.

---

## Scope

This security policy covers:

- The core C implementation using GTK+ 3 and WebKit2GTK
- Cookie persistence mechanism (`~/.app/diagram-client/cookies/`)
- URL loading and web content handling
- User interface components (URL bar, menus, bookmarks)
- Build scripts and configuration generation

**Out of scope**:
- Vulnerabilities in upstream libraries (WebKitGTK, GTK, system libraries) — please report those to the respective projects.
- Web-originating issues (such as XSS on diagram.app.com itself) — these should be reported to diagram.app.

---

## What We Consider Security Issues

We consider the following to be security vulnerabilities:

- Arbitrary code execution or command injection
- Unauthorized access to cookies, session data, or local files
- Privacy leaks or unintended data exfiltration
- Sandbox escape or privilege escalation
- Denial-of-service crashes triggered by malicious input
- Weaknesses in cookie storage or persistence logic

---

## Security Best Practices for Users

- Keep your system packages up to date, especially `libwebkit2gtk-4.1-dev` and related libraries.
- Only load trusted diagram.app URLs in the application.
- Periodically review the cookie storage directory (`~/.app/diagram-client/cookies/`).
- Run the application with minimal privileges (do not run as root).

---

## Disclosure Policy

We follow coordinated responsible disclosure:

1. Confirm receipt of the report
2. Investigate and validate the issue
3. Develop and test a fix
4. Credit the reporter (unless anonymity is requested)
5. Release a fixed version and publish an advisory if necessary

We appreciate the security research community and will publicly thank contributors where appropriate.

---

## Related Projects

This project is heavily inspired by Wilgat’s `pix-client` and is fully compatible with **SyncPrjs** (https://github.com/Wilgat/SyncPrjs).

---

**Last updated:** April 2026

Thank you for helping keep **diagram-client** secure!
```

### Recommendations:
- Place this file in the **root** of your repository so diagram.app automatically detects it and shows a "Security policy" link.
- After creating the file, go to your repo → **Security** tab → **Security policy** to enable it officially if needed.

Would you like a shorter version, or any adjustments (e.g., different email, more emphasis on CIAO, or adding PGP key instructions)?