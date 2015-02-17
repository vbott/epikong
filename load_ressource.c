/*
** load_ressource.c for epikong  in /home/audrade/work/epikong
** 
** Made by cailleux carole
** Login   <caille_c@epitech.net>
** 
** Started on  Sat Mar 26 20:44:56 2011 cailleux carole
** Last update Sat Mar 26 20:44:56 2011 cailleux carole
*/

#include <SDL/SDL_image.h>
#include "block.h"
#include "map.h"
#include "xfunctions.h"

t_ressource		gl_ressource[] = {
  {NONE, NULL},
  {WALL, NULL},
  {LADDER, NULL},
  {MONSTER, NULL},
  {OUTGAME, NULL},
  {INGAME, NULL},
  {LIVE, NULL},
  {KEY, NULL},
  {PORTAL, NULL},
  {WEAPON, NULL},
  {(e_block)10, NULL},
  {(e_block)11, NULL}
};

void			load_textures()
{
  gl_ressource[1].ressource = ximg_load("pictures/bottom.bmp");
  gl_ressource[2].ressource = ximg_load("pictures/ladder.png");
  gl_ressource[4].ressource = ximg_load("pictures/out.png");
  gl_ressource[6].ressource = ximg_load("pictures/life.png");
  gl_ressource[7].ressource = ximg_load("pictures/key.png");
  gl_ressource[8].ressource = ximg_load("pictures/portal.png");
  gl_ressource[10].ressource = ximg_load("pictures/ladder_top.png");
  gl_ressource[11].ressource = ximg_load("pictures/ladder_bottom.png");
}

void			pasteTexture(t_map *map, e_block type, int x, int y)
{
  SDL_Rect		pos;

  pos.x = x * 32;
  pos.y = y * 32;
  if (type == LADDER)
    {
      if (y > 0 && map->block[y - 1][x]->type != LADDER)
        xsdl_blitsurface(gl_ressource[10].ressource,
		       	NULL, map->background, &pos);
      else if (map->block[y + 1] && map->block[y + 1][x]->type != LADDER)
        xsdl_blitsurface(gl_ressource[11].ressource,
		       	NULL, map->background, &pos);
      else
        xsdl_blitsurface(gl_ressource[type].ressource,
		       	NULL, map->background, &pos);
    }
  else
    xsdl_blitsurface(gl_ressource[type].ressource,
		    NULL, map->background, &pos);
}

void			free_textures()
{
  int			i;

  for (i = 0 ; i < 12 ; i++)
    SDL_FreeSurface(gl_ressource[i].ressource);
}

void			clean_block(t_map *map, int x, int y)
{
  SDL_Rect		pos;

  pos.x = x * 32;
  pos.y = y * 32;
  pos.w = 32;
  pos.h = 32;
  xsdl_blitsurface(map->landscape, &pos, map->background, &pos);
  xsdl_blitsurface(map->background, &pos, map->screen, &pos);
  xsdl_flip(map->screen);
}
