/*
** events_up for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Sat 26 Mar 2011 03:58:51 PM CET botton vivien
** Last update Sat 26 Mar 2011 03:58:51 PM CET botton vivien
*/

#include "gui.h"

void	event_centered(t_gui *gui, t_map *map, t_character *character)
{
  static int call = 1;

  (void)(map);
  (void)(gui);
  if (call == 2)
  {
    if (character->newdirection == LJUMP || character->newdirection == LJUMP)
      character->newdirection = JUMP;
    else
      character->newdirection = NOMOVE;
    call = 0;
  }
  call++;
}

void		event_up_up(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == UP)
    character->newdirection = NOMOVE;
  (void)(gui);
  (void)(map);
}

void		event_down_up(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == DOWN)
    character->newdirection = NOMOVE;
  (void)(gui);
  (void)(map);
}

void		event_left_up(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == LEFT)
    character->newdirection = NOMOVE;
  else if (character->newdirection == LJUMP)
    character->newdirection = JUMP;
  (void)(gui);
  (void)(map);
}

void		event_right_up(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == RIGHT)
    character->newdirection = NOMOVE;
  else if (character->newdirection == RJUMP)
    character->newdirection = JUMP;
  (void)(gui);
  (void)(map);
}

void            event_space_up(t_gui *gui, t_map *map, t_character *character)
{
  if (character->newdirection == JUMP)
   character->newdirection = NOMOVE;
  else if (character->newdirection == RJUMP)
   character->newdirection = RIGHT;
  else if (character->newdirection == LJUMP)
   character->newdirection = LEFT;
  (void)(gui);
  (void)(map);
}
