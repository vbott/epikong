/*
** events_volume for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Sun 27 Mar 2011 05:27:59 PM CEST botton vivien
** Last update Sun 27 Mar 2011 05:27:59 PM CEST botton vivien
*/

#include "gui.h"

void            event_volume_up(t_gui *gui, t_map *map, t_character *chr)
{
  (void)(map);
  (void)(chr);
  if (gui->sound)
   {
      gui->volume += MIX_MAX_VOLUME / 10;
      if (gui->volume > MIX_MAX_VOLUME)
        gui->volume = MIX_MAX_VOLUME;
      Mix_VolumeMusic(gui->volume);
   }
}

void            event_volume_down(t_gui *gui, t_map *map, t_character *chr)
{
  (void)(map);
  (void)(chr);
  if (gui->sound)
   {
      gui->volume -= MIX_MAX_VOLUME / 10;
      if (gui->volume < MIX_MAX_VOLUME / 10)
        gui->volume = MIX_MAX_VOLUME / 10;
      Mix_VolumeMusic(gui->volume);
   }
}
