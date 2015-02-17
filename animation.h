/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sun Mar 27 08:35:45 CEST 2011 cerisier mickael
** Last update Sun Mar 27 08:35:45 CEST 2011 cerisier mickael
*/

#ifndef		_ANIMATION_H_
#define 	_ANIMATION_H_

#include "gui.h"

typedef struct	s_animation
{
  e_move	dir;
  void		(*func)(t_map*, t_character*, SDL_Rect*);
}		t_animation;

/* animation.c */
void		draw_hearts(t_map *map, t_character *character);
void		draw_anim(t_map *map, t_character *character,
			  SDL_Rect *pos, t_listsprite **list);
void		animation(t_map *map, t_character *character);

/* animation_move.c */
void		animation_right(t_map*, t_character*, SDL_Rect*);
void		animation_left(t_map*, t_character*, SDL_Rect*);
void		animation_up(t_map*, t_character*, SDL_Rect*);
void		animation_down(t_map*, t_character*, SDL_Rect*);

/* animation_jump.c */
void		animation_fall(t_map*, t_character*, SDL_Rect*);
void		animation_face(t_map*, t_character*, SDL_Rect*);
void		animation_jump(t_map*, t_character*, SDL_Rect*);
void		animation_ljump(t_map*, t_character*, SDL_Rect*);
void		animation_rjump(t_map*, t_character*, SDL_Rect*);

/* animation_fall.c */
void		animation_lfall(t_map*, t_character*, SDL_Rect*);
void		animation_rfall(t_map*, t_character*, SDL_Rect*);

#endif		/* _ANIMATION_H_ */

