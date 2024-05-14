# Cub3d

Cub3d is a 3D game engine project inspired by the famous game Wolfenstein 3D. The goal of this project is to create a simplified version of a ray-casting engine using the C programming language and the MinilibX graphical library. This project is part of the curriculum at 42 School.

## Table of Contents
1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Configuration](#configuration)
5. [Controls](#controls)
6. [Screenshots](#screenshots)
7. [Credits](#credits)

## Features
- Basic 3D rendering using ray-casting
- Textured walls and floor
- Simple sprite rendering
- Mini-map display
- Basic player movement and collision detection

## Installation
1. **Clone the repository:**
   ```sh
   git clone https://github.com/vtrevisa/Cub3d.git
   cd Cub3d
   ```

2. **Install dependencies:**
   Ensure you have the MinilibX library installed. You can find it in the `libs` directory or install it separately.

3. **Compile the project:**
   ```sh
   make
   ```

## Usage
Run the executable with a map file:
```sh
./cub3D maps/map_pdf.cub
```

## Configuration
Map files (.cub) are used to configure the game's environment. A sample configuration is provided in the `maps` directory. The map file should contain the following elements:

- Resolution
- Textures (north, south, east, west, sprite)
- Floor and ceiling colors
- Map layout (1 for walls, 0 for empty spaces, 2 for sprites)

### Example:
```
NO texture_1
SO texture_2
WE texture_3
EA texture_4

F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000002000001
1001000000000000000000001
1111111110110000011100000
1000000000110000011101111
1111011111111101110000001
1111011111111101110101001
1100000011010101110000001
1000200000000000110000001
1000000000000000110000001
1111111111111111111111111
```

## Controls
- **W**: Move forward
- **S**: Move backward
- **A**: Rotate left
- **D**: Rotate right
- **Left Arrow**: See left
- **Right Arrow**: See right
- **ESC**: Exit game

## Screenshots
<img src="https://github.com/vtrevisa/Cub3d/assets/105026221/477f6921-0706-49b6-a896-f134373282e7" alt="Screenshot1" width="400"/>
<img src="https://github.com/vtrevisa/Cub3d/assets/105026221/98c58e85-f723-41d7-b0e1-adfc8ad9eb12" alt="Screenshot1" width="400"/>

## Credits
Cub3d is developed by [vtrevisa](https://github.com/vtrevisa), and [renanbatista](https://github.com/renanbatista) as part of the 42 School curriculum.
