#include "../headers/main.h"

/**
 * keyL - perform left key press event
 * @app: common data struct
 * Return: 0
 */
int keyL(App *app)
{
	if (collideUp(app) && collideLeft(app))
		return (0);
	if (collideLeft(app))
		return (MoveUp(app));
	if (collideUp(app))
		return (MoveLeft(app));
	if (collideDown(app))
		return (MoveLeft(app));
	if (collideRight(app))
		return (MoveLeft(app));
	return (MoveLeft(app));

}
/**
 * keyR - perform right key press event
 * @app: common data struct
 * Return: 0
 */
int keyR(App *app)
{
	if (collideDown(app) && collideRight(app))
		return (0);
	if (collideLeft(app))
		return (MoveRight(app));
	if (collideDown(app))
		return (MoveRight(app));
	if (collideRight(app))
		return (MoveDown(app));
	if (collideUp(app))
		return (MoveRight(app));
	return (MoveRight(app));

}
/**
 * keyU - perform up key press event
 * @app: common data struct
 * Return: 0
 */
int keyU(App *app)
{
	if (collideUp(app) && collideRight(app))
		return (0);
	if (collideUp(app))
		return (MoveRight(app));
	if (collideLeft(app))
		return (MoveUp(app));
	if (collideDown(app))
		return (MoveUp(app));
	if (collideRight(app))
		return (MoveUp(app));
	return (MoveUp(app));

}
/**
 * keyD - perform down key press event
 * @app: common data struct
 * Return: 0
 */
int keyD(App *app)
{
	if (collideDown(app) && collideLeft(app))
		return (0);
	if (collideUp(app))
		return (MoveDown(app));
	if (collideLeft(app))
		return (MoveDown(app));
	if (collideDown(app))
		return (MoveLeft(app));
	if (collideRight(app))
		return (MoveDown(app));
	return (MoveDown(app));
}
