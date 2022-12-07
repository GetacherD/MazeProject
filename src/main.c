#include "../headers/main.h"
/**
 * main - entry point
 * @argc: number of args
 * @argv: command line args
 * Return: 0 on success else -1
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	App app;

	init(&app, argv);
	app.keys = SDL_GetKeyboardState(NULL);
	initTexture(&app);
	initPlayers(&app);
	while (true)
	{
		doInput(&app);
		drawFloorCeil(&app);
		drawWall(&app);
		drawMap(&app);
		drawRay(&app);
		drawPlayer(&app);
		SDL_RenderPresent(app.ren);
		SDL_Delay(16);
	}
	safeExit(&app);
	return (0);
}
