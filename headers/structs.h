#ifndef _STRUCTS_
#define _STRUCTS_

/**
 * struct Map - map of game
 * @size: size of map
 * @map: actual map
 */
typedef struct Map
{
	int size;
	int **map;
} Map;
/**
 * struct Point - (x, y) positions in map
 * @x: position x
 * @y: position y
 */
typedef struct Point
{
	double x;
	double y;
} Point;
/**
 * struct App - global common data holder struct
 * @ren: SD_Renderer object
 * @win: SDL_Window object
 * @ceil: game area ceiling texture
 * @floor: game area floor texture
 * @wallV: vertical wall texture
 * @wallH: horizontal wall texture
 * @teta: player view angle
 * @p: player location
 * @left: move left?1 else 0
 * @right: move right? 1 else 0
 * @up: move up ? 1 else 0
 * @down: move down ? 1 else 0
 * @map: game map
 * @map_size: game map size
 */
typedef struct App
{
	SDL_Renderer *ren;
	SDL_Window *win;
	SDL_Texture *ceil;
	SDL_Texture *floor;
	SDL_Texture *wallV;
	SDL_Texture *wallH;
	double teta;
	Point p;
	int **map;
	int map_size;
	double up;
	double down;
	double left;
	double right;
} App;

/**
 * struct SideLen - minimu length of ray and wall intersect
 * @len: length of ray
 * @face: side of wall vert/ horizontal touched
 */
typedef struct SideLen
{
	double len;
	int face; /* h = 0, v = 1 */
} SideLen;
#endif