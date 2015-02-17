/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Fri Mar 25 21:33:03 CET 2011 cerisier mickael
** Last update Fri Mar 25 21:33:03 CET 2011 cerisier mickael
*/

#include "character.h"

void		player_moveup(t_character *cha, t_map *map)
{
  if (map->block[cha->y][cha->x]->type == LADDER && cha->y - 1 < map->y &&
      map->block[cha->y - 1][cha->x]->type != WALL)
    cha->y--;
}

void		player_movedown(t_character *cha, t_map *map)
{
  if (cha->y + 1 < map->y && map->block[cha->y + 1][cha->x]->type == LADDER)
    cha->y++;
}

void		player_moveleft(t_character *cha, t_map *map)
{
  if (cha->x - 1 < map->x && map->block[cha->y][cha->x - 1]->type != WALL)
  {
    cha->x--;
    if (cha->y - 1 < map->y && !is_traversable(map, cha->x, cha->y + 1))
    {
      cha->direction = NOMOVE;
      cha->nbdirect = 10;
    }
  }
}

void		player_moveright(t_character *cha, t_map *map)
{
  if (cha->x + 1 < map->x && map->block[cha->y][cha->x + 1]->type != WALL)
  {
    cha->x++;
    if (cha->y - 1 < map->y && !is_traversable(map, cha->x, cha->y + 1))
    {
      cha->direction = NOMOVE;
      cha->nbdirect = 10;
    }
  }
}
