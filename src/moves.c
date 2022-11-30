#include "../headers/main.h"

/**
 * move - move player
 * @app: common data struct
 */
void move(App *app)
{
	app->p.x += app->right;
	app->p.x -= app->left;
	app->p.y += app->down;
	app->p.y -= app->up;
}
/**
 * MoveLeft - move player left(-x)
 * @app: common data struct
 * Return: 0
 */
int MoveLeft(App *app)
{
	app->left = 0.1;
	app->right = 0;
	app->up = 0;
	app->down = 0;
	move(app);
	return (0);
}
/**
 * MoveRight - move player right(+x)
 * @app: common data struct
 * Return: 0
 */
int MoveRight(App *app)
{
	app->left = 0;
	app->right = 0.1;
	app->up = 0;
	app->down = 0;
	move(app);
	return (0);
}
/**
 * MoveDown - move player down(+y)
 * @app: common data struct
 * Return: 0
 */
int MoveDown(App *app)
{
	app->left = 0;
	app->right = 0;
	app->up = 0;
	app->down = 0.1;
	move(app);
	return (0);
}
/**
 * MoveUp - move player up(-y)
 * @app: common data struct
 * Return: 0
 */
int  MoveUp(App *app)
{
	app->left = 0;
	app->right = 0;
	app->up = 0.1;
	app->down = 0;
	move(app);
	return (0);
}
