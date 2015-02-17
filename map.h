/*
** map for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 09:14:56 PM CET botton vivien
** Last update Fri 25 Mar 2011 09:14:56 PM CET botton vivien
*/

#ifndef _MAP_
#define _MAP_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "block.h"

#define BUF_SIZE 128

struct s_gui;

typedef struct s_map
{
  size_t	x;
  size_t	y;
  t_block	***block;
  SDL_Surface	*screen;
  SDL_Surface	*background;
  SDL_Surface	*landscape;
  SDL_Surface	*heart;
} t_map;

typedef struct s_ressource
{
  e_block	type;
  SDL_Surface	*ressource;
}		t_ressource;

/* map.c */
t_map		*create_map(struct s_gui *gui);
void		create_surface(t_map *map);

/* load_ressource.c */
void		load_textures();
void		pasteTexture(t_map *map, e_block type, int x, int y);
void		free_textures();
void		clean_block(t_map *map, int x, int y);

#endif /* _MAP_ */
