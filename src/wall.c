#include "../headers/main.h"
/**
 * drawWall - draw wall on screen
 * @app: common used variables struct
 */
void drawWall(App *app)
{

	double dirPlayer;
	double ratio, dpp; /* ratio -> ratio of distance to projection plane to
			    * ray length projected on to projetion plane
			    * dpp -> distance to projection plane
			    */
	SideLen ray;
	double sw, ra, ia;/* sw ->slice width
			   * ra -> ray angle
			   * ia -> included andgle between any ray
			   * and center of Field of view angle
			   */
	SDL_Rect wallSlice;

	dirPlayer = app->teta + 30;
	if (dirPlayer > 360)
		dirPlayer = dirPlayer - 360;
	else if (dirPlayer < 0)
		dirPlayer = 360  + dirPlayer;
	dpp = len(app->p, dirPlayer, app->map, app->map_size).len;
	for (sw = SCW; sw >= START; sw--)
	{
		ra = app->teta + (sw - START) * 60 / (SCW - START);
		if (ra > 360)
			ra = ra - 360;
		else if (ra < 0)
			ra = ra + 360;
		ray = len(app->p, ra, app->map, app->map_size);
		ia = (30 - (sw - START) * 60 / (SCW - START)) * M_PI / 180;
		ratio = dpp / (ray.len * cos(ia));
		wallSlice.x = SCW - sw;
		wallSlice.y = SCH / 2 - WALLHEIGHT_SCALE * ratio;
		wallSlice.w = 1;
		wallSlice.h = 2 * WALLHEIGHT_SCALE * ratio;
		if (ray.face == 1)
			SDL_RenderCopy(app->ren, app->wallV, &wallSlice, &wallSlice);
		else
			SDL_RenderCopy(app->ren, app->wallH, &wallSlice, &wallSlice);
	}
}
