# Console Tetris in C

> Basic Programming – University of Tehran – Department of Electrical & Computer Engineering

![Language](https://img.shields.io/badge/Language-C-blue) ![Tool](https://img.shields.io/badge/Tool-GCC%20%7C%20Make-orange) ![Interface](https://img.shields.io/badge/Interface-Windows%20Console%20%7C%20POSIX%20Terminal-lightgrey) ![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## Overview

This repository contains the source code for **Console Tetris in C**, a terminal-based implementation of the Tetris game using C and keyboard-driven console input. It was developed as the *Second Project* for the *Basic Programming* course at the University of Tehran.

The project implements a single-player falling-block game with a fixed board, keyboard controls, shape generation, horizontal movement, rotation, scoring, row deletion, next-shape preview, pause/restart/exit flow, and game-over detection. The cleaned repository separates the **console compatibility layer**, **game logic declarations**, **game implementation**, and executable entry point while preserving the original gameplay model.

The original submission was Windows-console oriented. This refactored version keeps the Win32/`conio.h` path for Windows and adds a lightweight POSIX terminal layer so the code can be compiled and smoke-tested with GCC in Linux-style environments.

## Project Objectives

- ✅ Implement a terminal-based Tetris-style game in C.
- ✅ Represent the game board and active blocks using arrays.
- ✅ Support keyboard-based movement, rotation, speed-up, pause, restart, and exit controls.
- ✅ Detect filled rows, update the score, and remove completed rows.
- ✅ Detect game-over state when new blocks reach the top of the board.
- ✅ Provide a clean build system and basic logic-level verification for GitHub publication.

## System Architecture & Modules

The project is organized into three implementation layers.

### 1️⃣ Console Compatibility Layer

The `src/console.c` module abstracts terminal operations such as screen clearing, keyboard polling, single-character input, sleep timing, and console color handling. On Windows, it uses Win32/`conio.h` behavior. On POSIX terminals, it uses `termios`, `select()`, ANSI screen clearing, and `nanosleep()`.

### 2️⃣ Game Logic Module

The `src/tetris.c` module contains the main gameplay logic, including board generation, tetromino creation, movement, rotation, collision checks, row-completion detection, score deletion, next-shape preview, and game-over detection.

The implemented shape set includes the original four shapes used by the submitted project: **O**, **I**, **Z**, and **T**.

### 3️⃣ Executable Entry Point

The `src/main.c` file coordinates the game loop. It initializes the console, displays the start screen, updates falling blocks, handles user input, applies scoring, and manages restart or exit behavior without recursively calling `main()`.

## Controls

| Key | Action |
| --- | --- |
| `A` / `a` | Move the active shape left |
| `D` / `d` | Move the active shape right |
| `S` / `s` | Increase falling speed |
| `Space` | Rotate the active shape |
| `P` / `p` | Pause the game |
| `Esc` | Open the exit/restart flow |
| `Enter` | Start or restart the game |

## Repository Structure

The project is organized as follows:

```text
TETRIS/
├── include/              # Header files and public function declarations
│   ├── console.h         # Console abstraction interface
│   └── tetris.h          # Game constants and gameplay function declarations
├── src/                  # C source files
│   ├── console.c         # Windows/POSIX console compatibility layer
│   ├── main.c            # Executable game loop and input handling
│   └── tetris.c          # Core Tetris board, shape, score, and render logic
├── tests/                # Logic-level smoke tests
│   └── test_tetris_logic.c
├── .gitattributes        # Line-ending normalization rules
├── .gitignore            # Ignored build, binary, editor, and OS artifacts
├── Makefile              # Build and test commands
└── README.md             # Project documentation
```

## Build & Run

The project was verified with GCC and `make` in a Linux environment.

```bash
make clean
make
./build/tetris
```

On Windows, the code keeps the Win32/`conio.h` branch. A MinGW-style GCC environment is recommended for using the provided `Makefile`.

## Testing

Run the logic-level smoke test with:

```bash
make test
```

The test checks board initialization, shape generation, board updating, basic movement, row-completion detection, and row deletion.

Expected output:

```text
All Tetris logic smoke tests passed.
```

## Notes

- The formal project statement was not included in the submitted ZIP, so the documented requirements are inferred from the source code, original README, and project context.
- The project is a compact first-year programming game and intentionally does not implement the full seven-piece modern Tetris shape set.
- Windows console colors are preserved through the Windows branch. On POSIX terminals, color commands are treated as no-ops for portability.
- No license file is included. Add a license before distributing or reusing the code beyond portfolio publication.

## Author

* **[Meraj Rastegar](https://github.com/mragetsars)**
