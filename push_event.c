/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 22:02:04 CET 2011 cerisier mickael
** Last update Sat Mar 26 22:02:04 CET 2011 cerisier mickael
*/

#include "gui.h"

void		push_event(int code)
{
  SDL_Event event;
  SDL_UserEvent userevent;

  userevent.type = SDL_USEREVENT;
  userevent.code = code;
  userevent.data1 = NULL;
  userevent.data2 = NULL;
  event.type = SDL_USEREVENT;
  event.user = userevent;
  SDL_PushEvent(&event);
}
