/*
** events for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 11:08:43 PM CET botton vivien
** Last update Fri 25 Mar 2011 11:08:43 PM CET botton vivien
*/

#include "gui.h"

void		event_up(t_gui *gui, t_map *map, t_character *character)
{
  character->newdirection = UP;
  (void)(gui);
  (void)(map);
}

void		event_down(t_gui *gui, t_map *map, t_character *character)
{
  character->newdirection = DOWN;
  (void)(gui);
  (void)(map);
}

void		event_left(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == JUMP || character->newdirection == RJUMP)
    character->newdirection = LJUMP;
  else
    character->newdirection = LEFT;
  (void)(gui);
  (void)(map);
}

void		event_right(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == JUMP || character->newdirection == LJUMP)
    character->newdirection = RJUMP;
  else
    character->newdirection = RIGHT;
  (void)(gui);
  (void)(map);
}

void            event_space(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == RIGHT)
    character->newdirection = RJUMP;
  else if (character->newdirection == LEFT)
    character->newdirection = LJUMP;
  else
    character->newdirection = JUMP;
  (void)(gui);
  (void)(map);
}
