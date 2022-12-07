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
	if (app->win == NULL)
		safeExit(app);
	app->ren = SDL_CreateRenderer(app->win, -1, SDL_RENDERER_ACCELERATED);
	if (app->ren == NULL)
		safeExit(app);
	m = loadMap(argv[1]);
	app->map = m.map;
	if (app->map == NULL)
		safeExit(app);
	app->map_size = m.size;
	app->up = 0;
	app->left = 0;
	app->right = 0.1;
	app->down = 0;
	app->fired = 0;
	if (!positionPlayer(app))
	{
		printf("Un able to place player on map\n");
		exit(0);
	}
}
/**
 * initTexture - initialize required textures for wall & floor
 * @app: common data struct
 */
void initTexture(App *app)
{
	SDL_Texture *wvtmp, *whtmp, *enemy;
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
	if (app->ceil == NULL || app->floor == NULL || app->wallV == NULL ||
	    app->wallH == NULL)
		safeExit(app);
}
/**
 * initPlayers - initialize required textures for player and enemy
 * @app: common data struct
 */
void initPlayers(App *app)
{
	SDL_Surface *pl, *en, *fr;

	pl = IMG_Load("img/player.gif");
	en = IMG_Load("img/enemy.gif");
	fr = IMG_Load("img/explode.png");
	SDL_SetColorKey(pl, SDL_TRUE, SDL_MapRGB(pl->format, 220, 88, 220));
	app->player = SDL_CreateTextureFromSurface(app->ren, pl);
	SDL_SetColorKey(en, SDL_TRUE, SDL_MapRGB(en->format, 152, 0, 136));
	app->enemy = SDL_CreateTextureFromSurface(app->ren, en);
	SDL_SetSurfaceBlendMode(fr, SDL_BLENDMODE_MOD);
	app->fire = SDL_CreateTextureFromSurface(app->ren, fr);
	SDL_FreeSurface(pl);
	SDL_FreeSurface(en);
	if (app->player == NULL || app->enemy == NULL)
		safeExit(app);
}

/**
 * safeExit - exit app if any thing wrong happen safely
 * @app: common data struct
 */
void safeExit(App *app)
{
	if (app->ceil)
		SDL_DestroyTexture(app->ceil);
	if (app->floor)
		SDL_DestroyTexture(app->floor);
	if (app->wallV)
		SDL_DestroyTexture(app->wallV);
	if (app->wallH)
		SDL_DestroyTexture(app->wallH);
	if (app->ren)
		SDL_DestroyRenderer(app->ren);
	if (app->win)
		SDL_DestroyWindow(app->win);
	if (app->map)
		free_map(app->map, app->map_size);
	if (app->fire)
		SDL_Destroy(app->fire);
	if (app->player)
		SDL_Destroy(app->player);
	if (app->enemy)
		SDL_Destroy(app->enemy)
	SDL_Quit();
	printf("Error Occur: %s\nUsage: ./prog mapfile", SDL_GetError());
	exit(0);
}
