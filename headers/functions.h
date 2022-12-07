#ifndef _PROTO_
#define _PROTO_
void safeExit(App *app);
void quit(App *app);
void drawFloorCeil(App *app);
void drawMap(App *app);
void drawRay(App *app);
void drawPlayer(App *app);
double min(double x, double y);
void doInput(App *app);
void init(App *app, char **argv);
void drawWall(App *app);
void initTexture(App *app);
void initPlayers(App *app);
int  positionPlayer(App *app);
void drawRay(App *app);
SideLen len(Point p, double teta, int **map, int size_map);
int checkCollide(Point p, int **map, int size);
void freeArr(int **, int);
void drawMap(App *app);
Map loadMap(char *filename);
void print_map(int **map, int size);
void free_map(int **map, int rows);
#endif
