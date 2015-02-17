/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sun Mar 27 10:25:46 CEST 2011 cerisier mickael
** Last update Sun Mar 27 10:25:46 CEST 2011 cerisier mickael
*/

#include "animation.h"

void		animation_fall(t_map *map, t_character *character,
			       SDL_Rect *pos)
{
  character->oldy += 0.33333 * -character->nbdirect;
  if (character->oldy > character->y)
    character->oldy = character->y;
  draw_anim(map, character, pos, &character->face);
}

void		animation_face(t_map *map, t_character *character,
			       SDL_Rect *pos)
{
  draw_anim(map, character, pos, &character->face);
}

void		animation_jump(t_map *map, t_character *character,
			       SDL_Rect *pos)
{
  character->oldy -= 0.33333;
  draw_anim(map, character, pos, &character->face);
}

void		animation_ljump(t_map *map, t_character *character,
			        SDL_Rect *pos)
{
  character->oldy -= 0.33333;
  character->oldx -= 0.33333;
  draw_anim(map, character, pos, &character->left);
}

void		animation_rjump(t_map *map, t_character *character,
			        SDL_Rect *pos)
{
  character->oldy -= 0.33333;
  character->oldx += 0.33333;
  draw_anim(map, character, pos, &character->right);
}
