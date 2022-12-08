#ifndef _STRUCTS_
#define _STRUCTS_
#include <SDL2/SDL.h>
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
 * @player: player texture
 * @teta: player view angle
 * @enemy: enemy tetxture
 * @fire: fired tetxture
 * @fired: is bullet fired ?
 * @rain: is rain active
 * @p: player location
 * @left: move left?1 else 0
 * @right: move right? 1 else 0
 * @up: move up ? 1 else 0
 * @down: move down ? 1 else 0
 * @map: game map
 * @map_size: game map size
 * @keys: keyboards state array
 */
typedef struct App
{
	SDL_Renderer *ren;
	SDL_Window *win;
	const Uint8 *keys;
	SDL_Texture *ceil;
	SDL_Texture *floor;
	SDL_Texture *wallV;
	SDL_Texture *wallH;
	SDL_Texture *player;
	SDL_Texture *enemy;
	SDL_Texture *fire;
	double teta;
	Point p;
	int **map;
	int fired;
	int rain;
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
