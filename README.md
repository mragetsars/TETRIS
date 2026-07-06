# Tetris (C Console Game)

> **Basic Programming - University of Tehran - Department of Electrical & Computer Engineering**

![Language](https://img.shields.io/badge/Language-C11-orange) ![Interface](https://img.shields.io/badge/Interface-Terminal-blue) ![Build](https://img.shields.io/badge/Build-Makefile-green) ![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

## 🎮 Overview

This repository contains a console-based implementation of the classic **Tetris** game, developed in **C** using keyboard-driven terminal input. This project was carried out as the *Second Project* for the *Basic Programming* course at the University of Tehran.

A compact recreation of the core **Tetris** gameplay loop, built from scratch in **C11** using a fixed terminal board, falling pieces, row clearing, score tracking, next-shape preview, pause/restart flow, and game-over detection.

This project was developed as part of my academic and personal exploration into **basic game development, procedural programming, terminal rendering, keyboard input handling, and cross-platform console behavior**.

![Tetris – C Console Game](./files/README.png)

## ✨ Features

- Classic **falling-block gameplay**: move and rotate pieces, complete rows, and keep the board from filling up.
- Implemented core mechanics:
  - **O, I, Z, and T shapes** from the original submitted version.
  - **Left/right movement**, speed control, and shape rotation.
  - **Row-completion detection**, row deletion, and score updates.
  - **Next-shape preview** beside the main board.
  - **Pause, restart, and exit flow** through keyboard commands.
- Terminal-based board system with a fixed play area, guide panel, score panel, and preview panel.
- Modular C structure separating gameplay logic, console compatibility, and the main game loop.
- Linux-compatible terminal input layer while preserving the original Windows console behavior.
- Lightweight smoke tests for core board and gameplay helpers.

## 🛠️ Tech Stack

- **Language:** C11
- **Interface:** Linux Terminal / Windows Console
- **Build System:** Makefile
- **Compiler:** GCC / MinGW GCC
- **OS Compatibility:** Linux (tested), should work on Windows with MinGW installed

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/mragetsars/TETRIS.git
cd TETRIS
```

### 2. Install dependencies

For Ubuntu/Linux:

```bash
sudo apt-get update
sudo apt-get install build-essential make
```

For Windows, install **MinGW GCC** and make sure `mingw32-make` is available from the terminal.

### 3. Build and Run the game

On Linux:

```bash
make clean #Clean build files
make
./build/tetris
```

On Windows with MinGW GCC:

```bash
mingw32-make clean
mingw32-make
.\build\tetris.exe
```

## 🎮 Controls

| Key | Action |
| --- | --- |
| `A` / `a` | Move the active shape left |
| `D` / `d` | Move the active shape right |
| `S` / `s` | Increase falling speed |
| `Space` | Rotate the active shape |
| `P` / `p` | Pause the game |
| `Esc` | Open the exit/restart flow |
| `Enter` | Start or restart the game |

## 📁 Repository Structure

The project is organized as follows:

```text
TETRIS/
├── src/                     # C implementation files
│   ├── main.c               # Game entry point and input loop
│   ├── tetris.c             # Core board, shape, score, and render logic
│   └── console.c            # Windows/POSIX console compatibility layer
├── include/                 # Header files (.h)
│   ├── tetris.h             # Game constants and gameplay declarations
│   └── console.h            # Console abstraction interface
├── files/                   # README cover and visual assets
│   ├── README.png           # README cover image
│   └── screenshots/         # README gameplay preview images
│       ├── linux-title-screen.png
│       └── linux-gameplay-screen.png
├── tests/                   # Logic-level smoke tests
│   └── test_tetris_logic.c  # Basic verification for gameplay helpers
├── Makefile                 # Build system configuration
├── .gitignore               # Ignored build, binary, editor, and OS artifacts
├── .gitattributes           # Line-ending normalization rules
└── README.md                # Project documentation
```

## 📸 Screenshots

<p align="center">
  <img src="./files/screenshots/linux-title-screen.png" alt="Linux Title Screen" width="49%">
  <img src="./files/screenshots/linux-gameplay-screen.png" alt="Linux Gameplay Preview" width="49%">
</p>

## 🧪 Testing

Run the smoke tests with:

```bash
make test
```

Expected output:

```text
All Tetris logic smoke tests passed.
```

## 🚧 Future Improvements

- Add the full seven-piece modern Tetris shape set.
- Add persistent high-score storage.
- Improve terminal colors and rendering on POSIX terminals.
- Add menu polish, difficulty levels, and cleaner end-game screens.
- Add automated input-driven gameplay tests.

## 🙏 Acknowledgments

- Inspired by the classic **Tetris** game.
- Built with ❤️ using **C** and terminal-based input/output.
- By **[Meraj Rastegar](https://github.com/mragetsars)**

## About

A console-based implementation of the classic Tetris game, developed in C with keyboard-driven terminal input. This project was carried out as the Second Project for the Basic Programming course at the University of Tehran.
