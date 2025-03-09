# Project Title: <em>Hot-Reloadable</em> Graphics Simulations using Raylib
## Programmer: Chaitanya Dubakula
#### Video Demo: https://youtu.be/r0Qm7iD3AW4
#### Description:
A collection of simulations written and built purely in C using raylib. Fully
hot-reloadable, meaning that the simulations can be reloaded without restarting,
using a custom framework written in a single header library.

Each simulation is compiled into a shared library, which is then loaded by the
main program at run-time.

Simply run the following to build the project:
```console
$make nob && ./nob
```

Once the project is built successfully, you can use the following commands to
run any of the simulations:
```console
$./nob run ./build/liblife.so
$./nob run ./build/libbezier.so
$./nob run ./build/libimager.so
```

You can also clear the working directory of the project using the following:
```console
$./nob clean
```

While any of the simulations are running, you can run the following to re-compile their source code:
```console
$./nob reload life
$./nob reload bezier
$./nob reload imager
```
Make sure to press 'R' in the simulation window to reload the simulation.

The following command will re-compile rebuild raylib:
```console
$./nob reload raylib
```

The following command will re-compile all of the simulations:
```console
$./nob reload
```

#### Simulations:
1. **Game of Life** - A zero-player game that simulates the life and death of cells in a grid.
#### Controls:
- **Space** - Pause/Resume the simulation
- **R** - Reload the simulation
- **C** - Clear the grid
- **G** - Randomize the grid
- **Mouse Click** - Toggle cell state
- **P** - Create an empty 5x5 square
- **O** - Toggle cell states in a 5x5 square
- **I** - Toggle cell states in a 9x9 square
- **Esc** - Exit the simulation

2. **Bezier Curves** - A simulation that demonstrates the use of Bezier curves.
   Also implements a drag and drop feature to move the control points.
#### Controls:
- **R** - Reload the simulation and clear the screen
- **Mouse Click** - Add a control point
- **Mouse Drag** - Move a control point

3. **Imager** - A simulation that demonstrates the use of raylib's image drawing functions.
#### Controls:
- **R** - Reload the simulation and clear the screen
- **C** - Clear the screen
- **G** - Take a screenshot
- **Mouse Click** - Console log positional information of the mouse and camera position
- **WASD** - Move the camera
- **Z/F** - Zoom in/out
- **Esc** - Exit the simulation
- **QEOP** - To manipulate Global flow speed

#### Dependencies:
- [raylib](https://github.com/raysan5/raylib)
- [nob](https://github.com/Tsoding/musializer/blob/master/nob.h)
