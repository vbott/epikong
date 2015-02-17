/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 13:14:31 CET 2011 cerisier mickael
** Last update Sat Mar 26 13:14:31 CET 2011 cerisier mickael
*/

#include "character.h"

inline void	move_up(t_character *character, t_map *map)
{
  if (character->moveup != NULL)
    character->moveup(character, map);
}

inline void	move_down(t_character *character, t_map *map)
{
  if (character->movedown != NULL)
    character->movedown(character, map);
}

inline void	move_right(t_character *character, t_map *map)
{
  if (character->moveright != NULL)
    character->moveright(character, map);
}

inline void	move_left(t_character *character, t_map *map)
{
  if (character->moveleft != NULL)
    character->moveleft(character, map);
}
