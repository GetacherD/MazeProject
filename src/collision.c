#include "../headers/main.h"

/**
 * checkCollide - check if player collide with wall
 * @p: player position
 * @map: map of game
 * @size: size of map
 * Return: 1 if collide else 0
 */
int checkCollide(Point p, int **map, int size)
{
	if (p.x < 0 || p.x >= size || p.y < 0 || p.y >= size)
		return (1);
	if (map[(int)p.y][(int)p.x])
		return (1);
	return (0);
}
/**
 * collideUp - check if player can move up next
 * @app: common data struct
 * Return: 1 if it will collide else 0
 */
int collideUp(App *app)
{
	Point pd;

	pd.x = app->p.x;
	pd.y = app->p.y - 0.1;
	if (checkCollide(pd, app->map, app->map_size))
	{
		app->left = 0;
		app->right = 0.1;
		app->down = 0;
		app->up = 0;
		return (1);
	}
	return (0);
}
/**
 * collideLeft - check if player can move left next
 * @app: common data struct
 * Return: 1 if it will collide else 0
 */
int collideLeft(App *app)
{
	Point pd;

	pd.x = app->p.x - 0.1;
	pd.y = app->p.y;
	if (checkCollide(pd, app->map, app->map_size))
	{
		app->left = 0;
		app->right = 0;
		app->down = 0;
		app->up = 0.1;
		return (1);
	}
	return (0);
}
/**
 * collideRight - check if player can move right next
 * @app: common data struct
 * Return: 1 if it will collide else 0
 */
int collideRight(App *app)
{
	Point pd;

	pd.x = app->p.x + 0.1;
	pd.y = app->p.y;
	if (checkCollide(pd, app->map, app->map_size))
	{
		app->left = 0;
		app->right = 0;
		app->down = 0.1;
		app->up = 0;
		return (1);
	}
	return (0);
}
/**
 * collideDown - check if player can move down next
 * @app: common data struct
 * Return: 1 if it will collide else 0
 */
int collideDown(App *app)
{
	Point pd;

	pd.x = app->p.x;
	pd.y = app->p.y + 0.1;
	if (checkCollide(pd, app->map, app->map_size))
	{
		app->left = 0.1;
		app->right = 0;
		app->down = 0;
		app->up = 0;
		return (1);
	}
	return (0);
}
