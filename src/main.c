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
	char **env;

	env = (char **)malloc(sizeof(char *) * 5);
	env[0] = getenv("WALLV");
	env[1] = getenv("WALLH");
	env[2] = getenv("FLOOR");
	env[3] = getenv("CEIL");
	init(&app, argv);
	app.keys = SDL_GetKeyboardState(NULL);
	initTexture(&app, env);
	initPlayers(&app);
	while (true)
	{
		doInput(&app);
		drawFloorCeil(&app);
		drawWall(&app);
		drawMap(&app);
		drawRay(&app);
		drawPlayer(&app);
		if (app.rain)
			rain(&app);
		SDL_RenderPresent(app.ren);
		SDL_Delay(16);
	}
	free(env);
	safeExit(&app);
	return (0);
}
