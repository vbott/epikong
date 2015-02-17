/*
** xfunctions.c for kong in /home/audrade/work/epikong
** 
** Made by cailleux carole
** Login   <caille_c@epitech.net>
** 
** Started on  Fri Mar 25 21:43:33 2011 cailleux carole
** Last update Fri Mar 25 21:43:33 2011 cailleux carole
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SDL/SDL_image.h>

FILE		*xfopen(const char *pathname, const char *flags)
{
  FILE		*fd;

  fd = fopen(pathname, flags);
  if (fd == NULL)
    perror(pathname);
  return (fd);
}

void		*xmalloc(size_t size)
{
  void		*ret;

  ret = malloc(size);
  if (ret == NULL)
  {
    perror("malloc()");
    exit(errno);
  }
  return (ret);
}

void			xsdl_blitsurface(SDL_Surface *src, SDL_Rect *srcrect,
					 SDL_Surface *dst, SDL_Rect *dstrect)
{
  if (SDL_BlitSurface(src, srcrect, dst, dstrect) == -1)
    {
      fprintf(stderr, "SDL_BlitSurface failed.\n");
      exit(EXIT_FAILURE);
    }
}

void			xsdl_flip(SDL_Surface *screen)
{
  if (SDL_Flip(screen) == -1)
    {
      fprintf(stderr, "SDL_Flip failed.\n");
      exit(EXIT_FAILURE);
    }
}

SDL_Surface		*ximg_load(const char *file)
{
  SDL_Surface		*res;

  if ((res = IMG_Load(file)) == NULL)
    {
      fprintf(stderr, "Img Load failed.\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}
