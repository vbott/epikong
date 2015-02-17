/*
** xfunctions_sdl.c for epikong in /home/audrade/work/epikong
** 
** Made by cailleux carole
** Login   <caille_c@epitech.net>
** 
** Started on  Sat Mar 26 23:43:48 2011 cailleux carole
** Last update Sat Mar 26 23:43:48 2011 cailleux carole
*/

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

SDL_Surface		*xsdl_setvideomode(int width, int height, int bitsperpixel,
					   Uint32 flags)
{
  SDL_Surface		*res;

  if ((res = SDL_SetVideoMode(width, height,
			      bitsperpixel, flags)) == NULL)
    {
      fprintf(stderr, "SDL_SetVideoMode failed.\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

void			xsdl_pushevent(SDL_Event *event)
{
  if (SDL_PushEvent(event) == -1)
    {
      fprintf(stderr, "SDL_PushEvent failed.\n");
      exit(EXIT_FAILURE);
    }
}

SDL_TimerID		xsdl_addtimer(Uint32 interval,
				      SDL_NewTimerCallback callback, void* param)
{
  SDL_TimerID		res;

  if ((res = SDL_AddTimer(interval, callback, param)) == NULL)
    {
      fprintf(stderr, "SDL_AddTimer failure.\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

int			xttf_init()
{
  int			res;

  if ((res = TTF_Init()) == -1)
    {
      fprintf(stderr, "TTF_Init error :%s\n", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  return (res);
}

TTF_Font		*xttf_openfont(const char *file, int ptsize)
{
  TTF_Font		*res;

  if ((res = TTF_OpenFont(file, ptsize)) == NULL)
    {
      fprintf(stderr, "TTF_OpenFont error\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}
