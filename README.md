# cli-password-manager

A command line password manager written in C.

---

## Project Structure
```
cli-password-manager/
├── src/
│   ├── main.c        # Entry point and CLI loop
│   ├── password.c    # Password CRUD operations
│   ├── entry.c       # PasswordEntry struct and parsing
│   └── utils.c       # Utility and debug helpers
├── include/
│   ├── password.h
│   ├── entry.h
│   └── utils.h
├── data/
│   └── passwords.csv # Persistent password storage
└── build/
    └── pm
```

---

## Features
- Add, view, edit, and delete password entries stored in a CSV file
- Entries are keyed by type (e.g. "email", "github") and store a username and password
- String normalization to handle line endings when reading from file
- Debug utilities for inspecting raw string content

---

## Build

**gcc:**
```bash
gcc src/main.c src/password.c src/entry.c src/utils.c -Iinclude -o build/pm
```

**clang:**
```bash
clang src/main.c src/password.c src/entry.c src/utils.c -Iinclude -o build/pm
```

---

## Usage
```bash
./build/pm
```

---