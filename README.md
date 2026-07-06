# Tetris (C Console Game)

> Basic Programming - University of Tehran - Department of Electrical & Computer Engineering

![Language](https://img.shields.io/badge/Language-C-blue) ![Tool](https://img.shields.io/badge/Tool-GCC%20%7C%20Make-orange) ![Interface](https://img.shields.io/badge/Interface-Windows%20Console%20%7C%20POSIX%20Terminal-lightgrey) ![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## Overview

This repository contains **Tetris**, a console-based implementation of the classic falling-block game, developed in C using keyboard-driven terminal input. This project was carried out as the *Second Project* for the *Basic Programming* course at the University of Tehran.

A compact recreation of the core Tetris gameplay loop, built from scratch in C with a fixed board, falling pieces, keyboard controls, row clearing, scoring, next-shape preview, pause/restart flow, and game-over detection. The current repository version also includes a small console-compatibility layer so the game can be built on Linux through a POSIX terminal path while preserving the original Windows console behavior.

![Tetris – C Console Game](files/README.png)

## Features

* Classic falling-block gameplay: guide pieces downward, complete rows, and keep the board from reaching the top.
* Implemented core mechanics:
  * Four original submitted shapes: O, I, Z, and T.
  * Horizontal movement, fast drop, and shape rotation.
  * Row-completion detection, row deletion, and score updates.
  * Next-shape preview and game-over detection.
  * Pause, restart, and exit flow through keyboard commands.
* Array-based board representation suitable for a first-year C programming project.
* Modular C structure separating game logic, console behavior, and the main loop.
* Lightweight smoke tests for core board and gameplay logic.

## Tech Stack

* Language: C11
* Interface: Windows Console / POSIX Terminal
* Build System: Makefile
* Compiler: GCC / MinGW GCC
* OS Compatibility: Linux tested and supported, Windows supported through a preserved Win32 console branch

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/mragetsars/TETRIS.git
cd TETRIS
```

### 2. Build the game

On Linux:

```bash
make clean
make
```

On Windows with MinGW GCC:

```bash
mingw32-make clean
mingw32-make
```

### 3. Run the game

On Linux:

```bash
./build/tetris
```

On Windows:

```bash
.\build\tetris.exe
```

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
├── files/                   # README cover and visual assets
│   └── README.png           # README cover image
├── include/                 # Header files (.h)
│   ├── console.h            # Console abstraction interface
│   └── tetris.h             # Game constants and gameplay declarations
├── src/                     # C implementation files
│   ├── console.c            # Windows/POSIX console compatibility layer
│   ├── main.c               # Game entry point and input loop
│   └── tetris.c             # Core board, shape, score, and render logic
├── tests/                   # Logic-level smoke tests
│   └── test_tetris_logic.c  # Basic verification for gameplay helpers
├── .gitattributes           # Line-ending normalization rules
├── .gitignore               # Ignored build, binary, editor, and OS artifacts
├── Makefile                 # Build and test commands
└── README.md                # Project documentation
```

## Testing

Run the smoke tests with:

```bash
make test
```

Expected output:

```text
All Tetris logic smoke tests passed.
```

## Future Improvements

* Add the full seven-piece modern Tetris shape set.
* Add persistent high-score storage.
* Improve terminal colors and rendering on POSIX terminals.
* Add automated input-driven gameplay tests.
* Add captured gameplay screenshots from Linux and Windows runs.

## Acknowledgments

* Inspired by the classic Tetris game.
* Built using C and terminal-based input/output.
* By **[Meraj Rastegar](https://github.com/mragetsars)**

## About

a console-based implementation of the classic Tetris game, developed in C with keyboard-driven terminal input. This project was carried out as the Second Project for the Basic Programming course at the University of Tehran.
