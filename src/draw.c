#include "../headers/main.h"
/**
 * drawMap - draw map of the game
 * @app: common data struct
 */
void drawMap(App *app)
{
	SDL_Rect Mw;
	int i, j;

	SDL_SetRenderDrawColor(app->ren, 100, 200, 150, 0);
	for (i = 0; i < app->map_size; i++)
	{
		for (j = 0; j < app->map_size; j++)
		{
			if (app->map[i][j])
			{
				Mw.x = j * SCALE;
				Mw.y = i * SCALE;
				Mw.w = SCALE;
				Mw.h = SCALE;
				SDL_RenderFillRect(app->ren, &Mw);
			}
		}
	}
}
/**
 * drawRay - draw ray for player FOV
 * @app: common data struct
 */
void drawRay(App *app)
{
	SideLen ray;
	double x1, y1, x2, y2, ra, modA, raylen;
/*
 * x1, x2, y1, y2 line coordinates in draw plane\
 * ra - ray angle
 * modA - modified angle , make sure 0 < modA < 360
 */
	for (ra = app->teta; ra <= app->teta + 60; ra++)
	{
		modA = ra;
		if (modA > 360)
			modA = modA - 360;
		else if (modA < 0)
			modA = 360 + modA;
		ray =  len(app->p, modA, app->map, app->map_size);
		raylen = SCALE * ray.len;
		x1 = app->p.x * SCALE;
		y1 = app->p.y * SCALE;
		x2 = x1 + raylen * cos(modA * M_PI / 180);
		y2 = y1 - raylen * sin(modA * M_PI / 180);
		if (ray.face)
			SDL_SetRenderDrawColor(app->ren, 255, 0, 0, 0);
		else
			SDL_SetRenderDrawColor(app->ren, 0, 255, 0, 0);
		SDL_RenderDrawLine(app->ren, x1, y1, x2, y2);
	}
}

/**
 * drawFloorCeil - draw floor and ceiling
 * @app: common data struct
 */
void drawFloorCeil(App *app)
{
	SDL_Rect rFloor, rCeil;

	rFloor.x = rCeil.x = 0;
	rFloor.y = 360;
	rCeil.y = 0;
	rFloor.w = rCeil.w = SCW;
	rFloor.h = rCeil.h = SCH / 2;
	SDL_RenderCopy(app->ren, app->floor, NULL, &rFloor);
	SDL_RenderCopy(app->ren, app->ceil, NULL, &rCeil);
}
