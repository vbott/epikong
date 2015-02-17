/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 21:21:18 CET 2011 cerisier mickael
** Last update Sat Mar 26 21:21:18 CET 2011 cerisier mickael
*/

#include "gui.h"
#include "character.h"

static const t_object	gl_object[] = {
	{OUTGAME, object_out},
	{LIVE, object_live},
	{KEY, object_key},
	{NONE, NULL}
};

void		object_out(t_character *c, t_map *map)
{
  (void)map;
  if (c->key)
    push_event(EPIKONG_END);
}

void		object_live(t_character *c, t_map *map)
{
  c->live += map->block[c->y][c->x]->data;
  map->block[c->y][c->x]->type = NONE;
  clean_block(map, c->x, c->y);
}

void		object_key(t_character *c, t_map *map)
{
  if (c->type == INGAME)
  {
    c->key++;
    map->block[c->y][c->x]->type = NONE;
    clean_block(map, c->x, c->y);
  }
}

void		take_portal(t_character *c, t_map *map)
{
  size_t	x;
  size_t	y;
  t_block	*other;
  t_block	*tmp;
  t_block	*block;

  if (c->direction != UP)
    return ;
  other = NULL;
  block = map->block[c->y][c->x];
  for (y = 0; y < map->y; y++)
    for (x = 0; x < map->x; x++)
    {
      tmp = map->block[y][x];
      if (tmp->type == PORTAL && tmp->data == block->data && block != tmp)
      {
	other = tmp;
	break ;
      }
    }
  if (other == NULL)
    return ;
  c->direction = FACE;
  c->x = other->x;
  c->y = other->y;
}

void		take_object(t_character *c, t_map *map)
{
  size_t	i;

  for (i = 0; gl_object[i].type != NONE; i++)
  {
    if (c->x < map->x && c->y < map->y &&
	map->block[c->y][c->x]->type == gl_object[i].type)
    {
      gl_object[i].func(c, map);
      break ;
    }
  }
}
