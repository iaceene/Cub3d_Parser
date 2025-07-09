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

  ```bash
  root@e1r10p7 yaajagro/Cub3d_Parser $ ./cub3D_Parser maps/cheese_maze.cub                                           (git)-[main]-
[ 0.0s ] [ ⏳ INIT PARSING ]
[ 0.54s ] [ ⏳ CHECKING FILE EXTENTION ]
[ 0.107s ] [ ✅ VALID EXTENTION ]
[ 0.147s ] [ ⏳ OPENING FILE ]
[ 0.188s ] [ ✅ FILE OPENED WITH SUCCESS ]
[ 0.243s ] [ ⏳ READING FILE ]
[ 0.489s ] [ ✅ DONE READING FILE ]
[ 0.540s ] [ ⏳ INIT PARSE LINES ]
[ 0.613s ] [ ✅ DONE PARSE LINES ]
[ 0.659s ] [ ⏳ ADDING MAP LINES ]
[ 0.728s ] [ ✅ DONE ADDING MAP LINES ]
[ 0.783s ] [ ⏳ CHECKING TEXTURES ]
[ 0.832s ] [ ⏳ CHECKING FILE textures/wall/wall_04.xpm ]
[ 0.948s ] [ ⏳ CHECKING EXTENTION ]
[ 0.1016s ] [ ✅ VALID EXTENTION ]
[ 0.1084s ] [ ✅ FILE EXIST ]
[ 0.1141s ] [ ⏳ CHECKING FILE textures/wall/wall_05.xpm ]
[ 0.1258s ] [ ⏳ CHECKING EXTENTION ]
[ 0.1329s ] [ ✅ VALID EXTENTION ]
[ 0.1397s ] [ ✅ FILE EXIST ]
[ 0.1453s ] [ ⏳ CHECKING FILE textures/wall/wall_03.xpm ]
[ 0.1567s ] [ ⏳ CHECKING EXTENTION ]
[ 0.1630s ] [ ✅ VALID EXTENTION ]
[ 0.1689s ] [ ✅ FILE EXIST ]
[ 0.1738s ] [ ⏳ CHECKING FILE textures/wall/wall_01.xpm ]
[ 0.1840s ] [ ⏳ CHECKING EXTENTION ]
[ 0.1907s ] [ ✅ VALID EXTENTION ]
[ 0.1967s ] [ ✅ FILE EXIST ]
[ 0.2019s ] [ ✅ VALID TEXTURES ]
[ 0.2078s ] [ ⏳ CHECK COLORS ]
[ 0.2142s ] [ ✅ VALID COLORS ]
[ 0.2197s ] [ ⏳ MAP CHECKING ]
[ 0.2256s ] [ ⏳ CHECKING LINE > 111111111111111111111 ]
[ 0.2360s ] [ ✅ VALID LINE ]
[ 0.2409s ] [ ⏳ CHECKING LINE > 10100000N000000000001 ]
[ 0.2514s ] [ ✅ VALID LINE ]
[ 0.2561s ] [ ⏳ CHECKING LINE > 101010101011111110001 ]
[ 0.2710s ] [ ✅ VALID LINE ]
[ 0.2754s ] [ ⏳ CHECKING LINE > 100010100010000010001 ]
[ 0.2843s ] [ ✅ VALID LINE ]
[ 0.2886s ] [ ⏳ CHECKING LINE > 111110101111101011101 ]
[ 0.2973s ] [ ✅ VALID LINE ]
[ 0.3016s ] [ ⏳ CHECKING LINE > 100000101000101000001 ]
[ 0.3104s ] [ ✅ VALID LINE ]
[ 0.3147s ] [ ⏳ CHECKING LINE > 101111101011101111111 ]
[ 0.3233s ] [ ✅ VALID LINE ]
[ 0.3276s ] [ ⏳ CHECKING LINE > 101000001010100000101 ]
[ 0.3362s ] [ ✅ VALID LINE ]
[ 0.3407s ] [ ⏳ CHECKING LINE > 101011111010111110101 ]
[ 0.3489s ] [ ✅ VALID LINE ]
[ 0.3533s ] [ ⏳ CHECKING LINE > 101010001010100010101 ]
[ 0.3616s ] [ ✅ VALID LINE ]
[ 0.3659s ] [ ⏳ CHECKING LINE > 101110101010101010101 ]
[ 0.3744s ] [ ✅ VALID LINE ]
[ 0.3786s ] [ ⏳ CHECKING LINE > 100000101010001010001 ]
[ 0.3868s ] [ ✅ VALID LINE ]
[ 0.3910s ] [ ⏳ CHECKING LINE > 111111101011111011101 ]
[ 0.3993s ] [ ✅ VALID LINE ]
[ 0.4035s ] [ ⏳ CHECKING LINE > 100000101000100010001 ]
[ 0.4120s ] [ ✅ VALID LINE ]
[ 0.4164s ] [ ⏳ CHECKING LINE > 101110101110101110111 ]
[ 0.4249s ] [ ✅ VALID LINE ]
[ 0.4292s ] [ ⏳ CHECKING LINE > 101000100000100010101 ]
[ 0.4380s ] [ ✅ VALID LINE ]
[ 0.4424s ] [ ⏳ CHECKING LINE > 101011111111111010101 ]
[ 0.4509s ] [ ✅ VALID LINE ]
[ 0.4555s ] [ ⏳ CHECKING LINE > 100010000000000010001 ]
[ 0.4641s ] [ ✅ VALID LINE ]
[ 0.4685s ] [ ⏳ CHECKING LINE > 101010111011111111101 ]
[ 0.4771s ] [ ✅ VALID LINE ]
[ 0.4815s ] [ ⏳ CHECKING LINE > 110000001000000000001 ]
[ 0.4901s ] [ ✅ VALID LINE ]
[ 0.4945s ] [ ⏳ CHECKING LINE > 111111111111111111111 ]
[ 0.5028s ] [ ✅ VALID LINE ]
[ 0.5072s ] [ ⏳ CHECKING DEPENDENCIES ]
[ 0.5135s ] [ ✅ CHECKING DEPENDENCIES ]
[ 0.5194s ] [ ✅ VALID MAP ]
  ```

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
