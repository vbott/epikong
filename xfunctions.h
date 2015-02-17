/*
** xerror.h for epikong in /home/audrade/work/epikong
** 
** Made by cailleux carole
** Login   <caille_c@epitech.net>
** 
** Started on  Fri Mar 25 21:46:25 2011 cailleux carole
** Last update Fri Mar 25 21:46:25 2011 cailleux carole
*/

#ifndef			__XFUNCTIONS_H__
# define		__XFUNCTIONS_H__

#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

FILE		*xfopen(const char *pathname, const char *flags);
void		*xmalloc(size_t size);
void		xsdl_blitsurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect);
void		xsdl_flip(SDL_Surface *screen);
SDL_Surface	*ximg_load(const char *file);

/* xfunctions_sdl.c */
SDL_Surface	*xsdl_setvideomode(int width, int height, int bitsperpixel,
				   Uint32 flags);
void		xsdl_pushevent(SDL_Event *event);
SDL_TimerID	xsdl_addtimer(Uint32 interval,
			      SDL_NewTimerCallback callback, void* param);
int		xttf_init();
TTF_Font	*xttf_openfont(const char *file, int ptsize);

#endif			/* __XFUNCTIONS_H__ */
