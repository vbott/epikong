/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sun Mar 27 10:58:23 CEST 2011 cerisier mickael
** Last update Sun Mar 27 10:58:23 CEST 2011 cerisier mickael
*/

#include "animation.h"

void		animation_lfall(t_map *map, t_character *character,
				SDL_Rect *pos)
{
  if (character->oldy != character->y)
    character->oldy += 0.33333;
  if (character->oldx != character->x)
    character->oldx -= 0.33333;
  draw_anim(map, character, pos, &character->left);
}

void		animation_rfall(t_map *map, t_character *character,
				SDL_Rect *pos)
{
  if (character->oldy != character->y)
    character->oldy += 0.33333;
  if (character->oldx != character->x)
    character->oldx += 0.33333;
  draw_anim(map, character, pos, &character->right);
}
