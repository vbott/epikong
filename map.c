/*
** map for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 09:17:27 PM CET botton vivien
** Last update Fri 25 Mar 2011 09:17:27 PM CET botton vivien
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include "xfunctions.h"
#include "gui.h"
#include "block.h"
#include "character.h"
#include "gui.h"

extern t_ressource		gl_ressource[];

void			create_surface(t_map *map)
{
  SDL_Rect		pos;
  SDL_Surface		*black;
  size_t		x;
  size_t		y;

  map->background = ximg_load("pictures/bg.png");
  map->landscape = ximg_load("pictures/bg.png");
  load_textures();
  for (y = 0 ; y < map->y ; y++)
    for (x = 0 ; x < map->x ; x++)
      if (gl_ressource[map->block[y][x]->type].ressource)
	pasteTexture(map, map->block[y][x]->type, x, y);
  black = SDL_CreateRGBSurface(SDL_HWSURFACE, map->x * 32, 32, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = map->y * 32;
  pos.w = map->x * 32;
  pos.h = 32;
  xsdl_blitsurface(black, NULL, map->background, &pos);
  xsdl_blitsurface(map->background, NULL, map->screen, NULL);
  SDL_FreeSurface(black);
  free_textures();
  xsdl_flip(map->screen);
}

t_map	  *create_map(t_gui *gui)
{
  t_map	  *tmp;

  tmp = xmalloc(sizeof(*tmp));
  tmp->x = 0;
  tmp->y = 0;
  tmp->background = NULL;
  tmp->landscape = NULL;
  tmp->block = NULL;
  tmp->screen = gui->screen;
  tmp->heart = ximg_load("pictures/life.png");
  return (tmp);
}

int		get_nb_lines(FILE *fd)
{
  int		res;
  char		line[BUF_SIZE];

  res = 0;
  while (fgets(line, BUF_SIZE, fd))
    res++;
  fseek(fd, 0, SEEK_SET);
  return (res);
}

void		fill_map(t_map *map, char *line, size_t *max_x, size_t *y)
{
  size_t	x;

  if (!*max_x)
    *max_x = strlen(line) - 1;
  x = 0;
  map->block[*y] = xmalloc(sizeof(t_block) * (*max_x + 1));
  while (line[x])
    {
      map->block[*y][x] = create_block(get_type_by_letter(line[x]), x, *y,
				       get_life_by_letter(line[x]));
      x++;
    }
  map->block[*y][x] = NULL;
  if (x - 1 != *max_x)
    {
      perror("Incorrect map");
      exit(EXIT_FAILURE);
    }
  (*y)++;
}

int		load_file(t_map *map, const char *path,
			  t_character **characters, t_gui *g)
{
  size_t	max_x;
  size_t	y;
  FILE		*fd;
  char		line[BUF_SIZE];

  y = 0;
  max_x = 0;
  if ((fd = xfopen(path, "r")) == NULL)
    return (-1);
  map->block = xmalloc(sizeof(t_block) * (get_nb_lines(fd) + 1));
  while (fgets(line, BUF_SIZE, fd))
    fill_map(map, line, &max_x, &y);
  map->block[y] = NULL;
  fclose(fd);
  if (!y)
    return (-1);
  map->x = max_x;
  map->y = y;
  load_players(map, characters);
  if (max_x > 45 || y > 35 || !(*characters) || (*characters)->type != INGAME)
    return (-1);
  SDL_FreeSurface(map->screen);
  map->screen = xsdl_setvideomode(32 * max_x, 32 * (y + 1), 32, g->sdl_flags);
  create_surface(map);
  return (0);
}
