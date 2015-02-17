/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sun Mar 27 10:23:26 CEST 2011 cerisier mickael
** Last update Sun Mar 27 10:23:26 CEST 2011 cerisier mickael
*/

#include "animation.h"

void		animation_right(t_map *map, t_character *character,
				SDL_Rect *pos)
{
  character->oldx += 0.33333;
  draw_anim(map, character, pos, &character->right);
}

void		animation_left(t_map *map, t_character *character,
			       SDL_Rect *pos)
{
  character->oldx -= 0.33333;
  draw_anim(map, character, pos, &character->left);
}

void		animation_up(t_map *map, t_character *character, SDL_Rect *pos)
{
  character->oldy -= 0.33333;
  draw_anim(map, character, pos, &character->up);
}

void		animation_down(t_map *map, t_character *character,
			       SDL_Rect *pos)
{
  character->oldy += 0.33333;
  draw_anim(map, character, pos, &character->up);
}
