# Cub3D Parser

A **Cub3D raycasting project parser** and basic renderer built in C using the MiniLibX (mlx) graphics library.  
This project parses `.cub` map files, validates map data and textures, and sets up the data structures required for a raycasting engine similar to the classic Wolfenstein 3D style.

---

## Features

- Parses `.cub` map files with walls, floors, ceilings, and doors
- Validates map integrity and textures
- Handles player spawn position and movement input
- Supports rendering basics for walls and minimap (raycasting core not included here)
- Uses MiniLibX for window and image handling
- Modularized parsing utilities for better maintainability

---

## Repository Structure

```

.
├── src/
│   ├── components/
│   │   └── parsing/            # Parsing logic and map utilities
│   ├── lib/
│   │   ├── mlx/                # MiniLibX library
│   │   ├── libft/              # Libft helper functions
│   │   └── gnl/                # Get Next Line utilities
│   ├── main/                   # Main entry point
│   ├── include/                # Header files including cub3d.h
│   └── malloc/                 # Custom malloc implementation
├── obj/                        # Object files (build output)
├── Makefile                   # Build instructions
└── README.md                  # This file

````

---

## Build Instructions

Ensure you have all required dependencies installed (X11, Xext, libbsd, math library, etc.) and a compatible compiler (`cc`).

To build the project:

```bash
make
````

This will compile the parser, the MiniLibX library, and the Libft library, then link everything into the executable named:

```
cub3D_Parser
```

### Cleaning build files

```bash
make clean       # removes object files
make fclean      # removes object files and executable
make re          # cleans and rebuilds the project
```

---

## Usage

Run the compiled parser with a `.cub` map file as an argument:

```bash
./cub3D_Parser path/to/map.cub
```

The parser will:

* Read and validate the map file format and contents
* Extract texture paths and RGB colors for floors and ceilings
* Initialize the player starting position and direction
* Prepare the map data for the raycasting renderer (to be implemented or extended)

---

## Notes

* This repository focuses on the **parsing stage** of Cub3D, including map validation and setup.
* The rendering loop, raycasting engine, and input handling are planned or may be implemented separately.
* MiniLibX is included as a submodule/library under `src/lib/.mlx`.
* Libft and GNL are used as utility libraries.

---

## License

This project is released under the MIT License.

---

## Acknowledgments

* MiniLibX by 42 school for graphics handling
* Libft for standard utility functions
* Get Next Line (GNL) for line-by-line file reading

---

Feel free to contribute or report issues!
