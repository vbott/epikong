/*
** event_timer for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Sun 27 Mar 2011 01:38:11 PM CEST botton vivien
** Last update Sun 27 Mar 2011 01:38:11 PM CEST botton vivien
*/

#include "gui.h"

void            event_speed_up(t_gui *gui, t_map *map, t_character *chr)
{
  (void)(map);
  (void)(chr);
  if (gui->timer_time > 20)
    gui->timer_time -= 10;
}
void            event_slow_down(t_gui *gui, t_map *map, t_character *chr)
{
  (void)(map);
  (void)(chr);
   if (gui->timer_time < 200)
     gui->timer_time += 10;
}
