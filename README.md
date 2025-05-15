# Geometry Shapes Project in C++

A student project to implement and test geometric shapes (Circle, Square, Triangle) using C++ and CTurtle for visualization.

---

## 🚀 Features
- **Shapes**: 
  - **Circle**: Calculate circumference, area, translate, resize, and compare equality.
  - **Square**: Calculate perimeter, area, translate, resize, and compare equality.
  - **Triangle**: Calculate perimeter, area, translate, resize, and compare equality.
- **Graphical Visualization**: Draw shapes using CTurtle.
- **Tests**: Pre-written tests to validate implementations (e.g., `testSquare.cpp`).

---

## 📦 Installation

### Prerequisites
- **Compiler**: `g++` with C++23 support.
- **OS**: Tested on Windows (requires `gdi32` and `user32` libraries).
- 
---

## 🛠️ Usage

### Compilation
```bash
g++ -std=c++23 -Iinclude -o test.exe src/shapes/circle.cpp src/draw.cpp src/point.cpp src/shapes/square.cpp src/shapes/triangle.cpp main.cpp -lgdi32 -luser32
