/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 13:24:27 CET 2011 cerisier mickael
** Last update Sat Mar 26 13:24:27 CET 2011 cerisier mickael
*/

#include "character.h"

void		fall(t_character *c, t_map *map)
{
  int		i;

  for (i = 1; i < -c->nbdirect; i++)
  {
    if (c->y + i >= map->y)
      break ;
    else if (map->block[c->y + i][c->x]->type == WALL ||
	     map->block[c->y + i][c->x]->type == LADDER)
      break ;
  }
  if (-c->nbdirect + i > 4 || c->y + i >= map->y)
    c->live = 0;
  c->y += i;
  if (c->y >= map->y || map->block[c->y][c->x]->type == WALL ||
		        map->block[c->y][c->x]->type == LADDER)
  {
    c->direction = FACE;
    c->y--;
  }
  else if (c->y + 1 < map->y && (map->block[c->y + 1][c->x]->type == WALL ||
			         map->block[c->y + 1][c->x]->type == LADDER))
    c->direction = FACE;
  c->nbdirect *= 2;
}

void		fall_right(t_character *c, t_map *map)
{
  if (c->y + 1 < map->y)
  {
    if (c->x + 1 < map->x && map->block[c->y + 1][c->x + 1]->type != WALL)
    {
      c->y++;
      c->x++;
    }
    else
    {
      c->direction = FALL;
      c->nbdirect = -1;
      c->y++;
    }
  }
  else
    c->live = 0;
}

void		fall_left(t_character *c, t_map *map)
{
  if (c->y + 1 < map->y)
  {
    if (c->x - 1 < map->x && map->block[c->y + 1][c->x - 1]->type != WALL)
    {
      c->y++;
      c->x--;
    }
    else
    {
      c->direction = FALL;
      c->nbdirect = -1;
      c->y++;
    }
  }
  else
    c->live = 0;
}
