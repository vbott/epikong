/*
** animation for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Sun 27 Mar 2011 03:10:14 AM CEST botton vivien
** Last update Sun 27 Mar 2011 03:10:14 AM CEST botton vivien
*/

#include "xfunctions.h"
#include "animation.h"
#include "gui.h"

static const t_animation	gl_anim[] = {
	{RIGHT, animation_right},
	{LEFT, animation_left},
	{UP, animation_up},
	{DOWN, animation_down},
	{FALL, animation_fall},
	{FACE, animation_fall},
	{JUMP, animation_jump},
	{LJUMP, animation_ljump},
	{RJUMP, animation_rjump},
	{LJUMPCONT, animation_left},
	{RJUMPCONT, animation_right},
	{LFALL, animation_lfall},
	{RFALL, animation_rfall},
	{NOMOVE, NULL}
};

void		draw_hearts(t_map *map, t_character *character)
{
  SDL_Rect	pos;
  size_t	i;

  pos.x = 0;
  pos.y = map->y * 32;
  pos.w = map->x * 32;
  pos.h = 32;
  xsdl_blitsurface(map->background, &pos, map->screen, &pos);
  for (i = 0; i < character->live; ++i)
   {
     xsdl_blitsurface(map->heart, NULL, map->screen, &pos);
     pos.x += 32;
   }
}

void		draw_anim(t_map *map, t_character *character,
	       		  SDL_Rect *pos, t_listsprite **list)
{
  SDL_Rect	sprite;

  xsdl_blitsurface(map->background, pos, map->screen, pos);
  pos->x = character->oldx * 32;
  pos->y = character->oldy * 32;
  sprite.x = (*list)->x;
  sprite.y = (*list)->y;
  sprite.w = 32;
  sprite.h = 32;
  xsdl_blitsurface(character->sprites, &sprite, map->screen, pos);
  xsdl_flip(map->screen);
  *list = (*list)->next;
}

static e_move	get_direction(t_character *c)
{
    if (c->direction == UP || c->direction == DOWN || c->direction == FACE)
      return (c->direction);
    if (c->oldx == c->x)
      return ((c->oldy > c->y) ? JUMP : FALL);
    if (c->oldy == c->y)
      return ((c->oldx > c->x) ? LEFT : RIGHT);
    if (c->oldx > c->x)
      return ((c->oldy > c->y) ? LJUMP : LFALL);
    return ((c->oldy > c->y) ? RJUMP : RFALL);
}

void		animation(t_map *map, t_character *character)
{
  size_t	i;
  SDL_Rect	pos;
  e_move	direction;

  pos.x = character->oldx * 32;
  pos.y = character->oldy * 32;
  pos.w = 32;
  pos.h = 32;
  if (character->oldx != (float)character->x ||
      character->oldy != (float)character->y)
  {
    direction = get_direction(character);
    for (i = 0; gl_anim[i].func; i++)
    {
      if (gl_anim[i].dir == direction)
	gl_anim[i].func(map, character, &pos);
    }
  }
  else if (character->direction == FACE)
    animation_face(map, character, &pos);
}
