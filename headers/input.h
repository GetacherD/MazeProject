#ifndef INPUTS
#define INPUTS
int checkCollide(Point p, int **map, int size);
int collideUp(App *app);
int collideLeft(App *app);
int collideRight(App *app);
int collideDown(App *app);
void move(App *app);
int MoveLeft(App *app);
int MoveRight(App *app);
int MoveDown(App *app);
int  MoveUp(App *app);
int stop(App *app);
int keyL(App *app);
int keyR(App *app);
int keyU(App *app);
int keyD(App *app);
#endif

