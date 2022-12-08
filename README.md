<!-- markdownlint-configure-file {
  "MD013": {
    "code_blocks": false,
    "tables": false
  },
  "MD033": false,
  "MD041": false
} -->

<div align="center">

# Maze



Maze is a **SDL 3D Game**, done as final project for alx foundation course



[Getting started](#getting-started) •

[Configuration](#configuration) •
[How to Play](#key Bindings) •


</div>

## Getting started


To install/run  Maze

Add SDL_image  to your img folder at same level as src and header

run this command in your command prompt:

```sh
gcc src/*.c -lSDL2 -Limg/SDL_img -Iimg/SDL_img -lSDL_image -lm -o out # compile
./out map.data # run the program

```




> **Note**
> Maze only runs in SDL2*



## Configuration

### map file

When calling `./output mapfile`

mapfile must be file that contain 0 for no wall and 1 for wall
each 0 and 1 must be separated by exactly 1 space and exactly one new line
no space after new  line

it must be square in size

1 1 1 1 1 1

1 0 0 1 0 1

1 0 0 0 1 1

1 1 0 0 1 1

1 0 0 1 0 1

1 1 1 1 1 1

## Key Bindings

### Game rules
press a to rotate ccw
press d to rotate cw
press up/down/left/right to move up/down/left/right
press f to fire

[src]: https://github.com/GetacherD/MazeProject