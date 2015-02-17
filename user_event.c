/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 22:00:01 CET 2011 cerisier mickael
** Last update Sat Mar 26 22:00:01 CET 2011 cerisier mickael
*/

#include <stdio.h>
#include "xfunctions.h"
#include "gui.h"
#include "animation.h"

void            event_sound(t_gui *gui, t_map *map, t_character *character)
{
  (void)(map);
  (void)(character);
  if (Mix_PausedMusic() == 0 && gui->sound == 1)
   Mix_PauseMusic();
  else if (Mix_PausedMusic() == 1 && gui->sound == 0)
   Mix_ResumeMusic();
  gui->sound = !gui->sound;
}

void            event_move(t_gui *gui, t_map *map, t_character *character)
{
  t_character	*tmp;

  (void)(gui);
  draw_hearts(map, character);
  if (character->live == 0)
    push_event(EPIKONG_LOOSE);
  for (tmp = character; tmp; tmp = tmp->next)
    move(tmp, character, map);
}

void            event_animation(t_gui *gui, t_map *map, t_character *character)
{
  (void)gui;
  for (; character; character = character->next)
    animation(map, character);
}

void		event_fullscreen(t_gui *gui, t_map *map, t_character *character)
{
 SDL_Surface	*old;
 int		mem;

 (void)(character);
 if (gui->sdl_flags & SDL_FULLSCREEN)
   gui->sdl_flags &= ~(SDL_FULLSCREEN);
 else
   gui->sdl_flags |= SDL_FULLSCREEN;
 old = map->screen;
 mem = gui->pause_timer;
 gui->pause_timer = 1;
 map->screen = xsdl_setvideomode(32 * map->x, 32 * (map->y + 1), 32,
		 gui->sdl_flags);
 if (map->screen == NULL)
   map->screen = old;
 else
   SDL_FreeSurface(map->screen);
 create_surface(map);
 gui->pause_timer = mem;
}

void            event_pause(t_gui *gui, t_map *map, t_character *character)
{
  (void)(map);
  (void)(character);
  if (Mix_PausedMusic() == 1 && gui->sound)
    Mix_ResumeMusic();
  else if (Mix_PausedMusic() == 0 && gui->sound)
    Mix_PauseMusic();
  gui->pause_timer = !gui->pause_timer;
}
