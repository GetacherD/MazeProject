#include "../headers/main.h"

/**
 * doKeyDown - handle key down event
 * @app: common data struct
 */
void doKeyDown(App *app)
{
	if (app->keys[SDL_SCANCODE_DOWN])
		keyD(app);
	if (app->keys[SDL_SCANCODE_LEFT])
		keyL(app);
	if (app->keys[SDL_SCANCODE_RIGHT])
		keyR(app);
	if (app->keys[SDL_SCANCODE_UP])
		keyU(app);
	if (app->keys[SDL_SCANCODE_A])
	{
		app->teta += 1;
		if (app->teta > 360)
			app->teta = app->teta - 360;
	}
	if (app->keys[SDL_SCANCODE_D])
	{
		app->teta -= 1;
		if (app->teta < 0)
			app->teta = app->teta + 360;
	}
}
/**
 * doInput - process all inputs
 * @app: common data struct
 */
void doInput(App *app)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			exit(0);
			break;
		default:
			break;
		}
		doKeyDown(app);
	}
}
