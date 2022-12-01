#include "../headers/main.h"

/**
 * positionPlayer - place player on map
 * @app: common data struct
 * Return: 1 if success in placing else 0
 */

int positionPlayer(App *app)
{
	int i, j;

	app->p.x = 1.5;
	app->p.y = 1.5;
	for (i = 0; i < app->map_size; i++)
	{
		for (j = 0; j < app->map_size; j++)
		{
			if (app->map[i][j] == 0)
			{
				app->p.x = j + 0.5;
				app->p.y = i + 0.5;
				return (1);
			}
		}
	}
	return (0);
}
/**
 * init - initialize SDL
 * @app: common data struct
 * @argv: command line args
 */
void init(App *app, char **argv)
{
	Map m;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error: %s\n", SDL_GetError());
		exit(-1);
	}
	app->win = SDL_CreateWindow("Maze Game",
				    SDL_WINDOWPOS_CENTERED,
				    SDL_WINDOWPOS_CENTERED,
				    SCW, SCH,
				    SDL_WINDOW_SHOWN);
	app->ren = SDL_CreateRenderer(app->win, -1, SDL_RENDERER_ACCELERATED);
	m = loadMap(argv[1]);
	app->map = m.map;
	app->map_size = m.size;
	app->up = 0;
	app->left = 0;
	app->right = 0.1;
	app->down = 0;
	if (!positionPlayer(app))
	{
		printf("Un able to place player on map\n");
		exit(0);
	}
}
/**
 * initTexture - initialize required textures
 * @app: common data struct
 */
void initTexture(App *app)
{
	SDL_Texture *wvtmp, *whtmp;
	SDL_Surface *wv, *wh;

	wv = IMG_Load("img/wallv.jpg");
	wh = IMG_Load("img/wallh.jpg");
	app->floor = SDL_CreateTexture(app->ren,
				       SDL_PIXELFORMAT_RGBA8888,
				       SDL_TEXTUREACCESS_TARGET, SCW, SCH / 2);
	app->ceil = SDL_CreateTexture(app->ren,
				      SDL_PIXELFORMAT_RGBA8888,
				      SDL_TEXTUREACCESS_TARGET, SCW, SCH / 2);
	app->wallH = SDL_CreateTexture(app->ren,
				       SDL_PIXELFORMAT_RGBA8888,
				       SDL_TEXTUREACCESS_TARGET, SCW, SCH);
	app->wallV = SDL_CreateTexture(app->ren,
				       SDL_PIXELFORMAT_RGBA8888,
				       SDL_TEXTUREACCESS_TARGET, SCW, SCH);
	wvtmp = SDL_CreateTextureFromSurface(app->ren, wv);
	whtmp = SDL_CreateTextureFromSurface(app->ren, wh);
	SDL_SetRenderTarget(app->ren, app->wallV);
	SDL_RenderCopy(app->ren, wvtmp, NULL, NULL);
	SDL_DestroyTexture(wvtmp);
	SDL_SetRenderTarget(app->ren, app->wallH);
	SDL_RenderCopy(app->ren, whtmp, NULL, NULL);
	SDL_DestroyTexture(whtmp);
	SDL_SetRenderTarget(app->ren, app->floor);
	SDL_SetRenderDrawColor(app->ren, 0, 0, 200, 0);
	SDL_RenderClear(app->ren);
	SDL_SetRenderTarget(app->ren, app->ceil);
	SDL_SetRenderDrawColor(app->ren, 200, 120, 25, 255);
	SDL_RenderClear(app->ren);
	SDL_SetRenderTarget(app->ren, NULL);
	SDL_FreeSurface(wv);
	SDL_FreeSurface(wh);
}
