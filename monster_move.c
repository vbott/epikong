/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Fri Mar 25 22:53:47 CET 2011 cerisier mickael
** Last update Fri Mar 25 22:53:47 CET 2011 cerisier mickael
*/

#include "character.h"

void		monster_moveleft(t_character *cha, t_map *map)
{
  size_t	x;

  x = cha->x - 1;
  if (x >= map->x || map->block[cha->y][x]->type == WALL ||
      (cha->y + 1 < map->y && map->block[cha->y + 1][x]->type != WALL &&
       map->block[cha->y + 1][x]->type != LADDER))
  {
    if (cha->direction == RIGHT)
    {
      cha->direction = NOMOVE;
      cha->newdirection = NOMOVE;
    }
    else
    {
      monster_moveright(cha, map);
      cha->newdirection = RIGHT;
      cha->direction = RIGHT;
    }
  }
  else
    cha->x--;
}

void		monster_moveright(t_character *cha, t_map *map)
{
  size_t	x;

  x = cha->x + 1;
  if (x >= map->x || map->block[cha->y][x]->type == WALL ||
      (cha->y + 1 < map->y && map->block[cha->y + 1][x]->type != WALL &&
       map->block[cha->y + 1][x]->type != LADDER))
  {
    if (cha->direction == LEFT)
    {
      cha->direction = NOMOVE;
      cha->newdirection = NOMOVE;
    }
    else
    {
      monster_moveleft(cha, map);
      cha->newdirection = LEFT;
      cha->direction = LEFT;
    }
  }
  else
    cha->x++;
}
