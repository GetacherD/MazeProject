#include "../headers/main.h"

/**
 * doKeyDown - handle key down event
 * @e: event struct
 * @app: common data struct
 */
void doKeyDown(SDL_Event e, App *app)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_a:
		app->teta += 1;
		if (app->teta > 360)
			app->teta = app->teta - 360;
		break;
	case SDLK_d:
		app->teta -= 1;
		if (app->teta < 0)
			app->teta = app->teta + 360;
		break;
	case SDLK_DOWN:
		keyD(app);
		break;
	case SDLK_UP:
		keyU(app);
		break;
	case SDLK_LEFT:
		keyL(app);
		break;
	case SDLK_RIGHT:
		keyR(app);
		break;

	default:
		break;
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
		case SDL_KEYDOWN:
			doKeyDown(e, app);
			break;
		default:
			break;
		}
	}
}
