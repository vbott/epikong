/*
** event_quit for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Sun 27 Mar 2011 11:13:03 AM CEST botton vivien
** Last update Sun 27 Mar 2011 11:13:03 AM CEST botton vivien
*/

#include <stdio.h>
#include "gui.h"

static void	destroy_player(t_character *player)
{
  SDL_FreeSurface(player->sprites);
}

static void	destroy_map_players(t_map *map, t_character *character)
{
  size_t	x;
  size_t	y;
  t_character	*prev;

  SDL_FreeSurface(map->landscape);
  SDL_FreeSurface(map->background);
  SDL_FreeSurface(map->heart);
  for (y = 0; y < map->y; ++y)
    {
      for (x = 0; x < map->x; ++x)
	free(map->block[y][x]);
      free(map->block[y]);
    }
  free(map->block[y]);
  free(map->block);
  free(map);
  while (character)
   {
     prev = character;
     destroy_player(character);
     character = character->next;
     free(prev);
   }
}

void		event_quit(t_gui *gui, t_map *map, t_character *character)
{
  gui->quit = 3;
  destroy_map_players(map, character);
  SDL_RemoveTimer(gui->timer);
}

void		event_end(t_gui *gui, t_map *map, t_character *character)
{
  gui->quit = 0;
  destroy_map_players(map, character);
  SDL_RemoveTimer(gui->timer);
}

void		event_loose(t_gui *gui, t_map *map, t_character *character)
{
  gui->quit = 2;
  destroy_map_players(map, character);
  SDL_RemoveTimer(gui->timer);
}
