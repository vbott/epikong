/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Fri Mar 25 22:33:23 CET 2011 cerisier mickael
** Last update Fri Mar 25 22:33:23 CET 2011 cerisier mickael
*/

#include "character.h"

void		jump(t_character *cha, t_map *map)
{
  if (cha->y - 1 < map->y && map->block[cha->y - 1][cha->x]->type != WALL)
    cha->y--;
}

void		jump_right(t_character *cha, t_map *map)
{
  if (cha->y - 1 < map->y && cha->x + 1 < map->x &&
      map->block[cha->y - 1][cha->x + 1]->type != WALL)
  {
    cha->x++;
    if (!is_traversable(map, cha->x, cha->y))
      cha->direction = NOMOVE;
    cha->y--;
  }
  else
  {
    if (cha->x + 1 && map->block[cha->y][cha->x + 1]->type != WALL)
      cha->x++;
    cha->direction = NOMOVE;
  }
}

void		jump_left(t_character *cha, t_map *map)
{
  if (cha->y - 1 < map->y && cha->x - 1 < map->x &&
      map->block[cha->y - 1][cha->x - 1]->type != WALL)
  {
    cha->x--;
    if (!is_traversable(map, cha->x, cha->y))
      cha->direction = NOMOVE;
    cha->y--;
  }
  else
  {
    if (cha->x - 1 < map->x && map->block[cha->y][cha->x - 1]->type != WALL)
      cha->x--;
    cha->direction = NOMOVE;
  }
}
