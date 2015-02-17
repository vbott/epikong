/*
** gui for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 09:51:06 PM CET botton vivien
** Last update Fri 25 Mar 2011 09:51:06 PM CET botton vivien
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "xfunctions.h"
#include "gui.h"

static const t_event	gl_event[] = {
	{SDL_QUIT, 0, event_quit},
	{SDL_KEYDOWN, SDLK_ESCAPE, event_quit},
	{SDL_KEYDOWN, SDLK_UP, event_up},
	{SDL_JOYHATMOTION, SDL_HAT_UP, event_up},
	{SDL_KEYDOWN, SDLK_DOWN, event_down},
	{SDL_JOYHATMOTION, SDL_HAT_DOWN, event_down},
	{SDL_KEYDOWN, SDLK_RIGHT, event_right},
	{SDL_JOYHATMOTION, SDL_HAT_RIGHT, event_right},
	{SDL_KEYDOWN, SDLK_LEFT, event_left},
	{SDL_JOYHATMOTION, SDL_HAT_LEFT, event_left},
	{SDL_KEYDOWN, SDLK_SPACE, event_space},
	{SDL_JOYBUTTONDOWN, 0, event_space},
	{SDL_KEYDOWN, SDLK_PLUS, event_speed_up},
	{SDL_JOYBUTTONDOWN, 5, event_speed_up},
	{SDL_KEYDOWN, SDLK_KP_PLUS, event_speed_up},
	{SDL_KEYDOWN, SDLK_MINUS, event_slow_down},
	{SDL_JOYBUTTONDOWN, 4, event_slow_down},
	{SDL_KEYDOWN, SDLK_KP_MINUS, event_slow_down},
	{SDL_KEYDOWN, SDLK_F11, event_fullscreen},
	{SDL_KEYDOWN, SDLK_p, event_pause},
	{SDL_JOYBUTTONDOWN, 6, event_pause},
	{SDL_KEYDOWN, SDLK_s, event_sound},
	{SDL_JOYBUTTONDOWN, 10, event_sound},
	{SDL_KEYDOWN, SDLK_KP_DIVIDE, event_volume_up},
	{SDL_KEYDOWN, SDLK_KP_MULTIPLY, event_volume_down},
	{SDL_KEYUP, SDLK_UP, event_up_up},
	{SDL_KEYUP, SDLK_DOWN, event_down_up},
	{SDL_KEYUP, SDLK_RIGHT, event_right_up},
	{SDL_KEYUP, SDLK_LEFT, event_left_up},
	{SDL_JOYHATMOTION, SDL_HAT_CENTERED, event_centered},
	{SDL_KEYUP, SDLK_SPACE, event_space_up},
	{SDL_JOYBUTTONUP, 0, event_space_up},
	{SDL_USEREVENT, EPIKONG_MOVE, event_move},
	{SDL_USEREVENT, EPIKONG_ANIMATION, event_animation},
	{SDL_USEREVENT, EPIKONG_PAUSE, event_pause},
	{SDL_USEREVENT, EPIKONG_END, event_end},
	{SDL_USEREVENT, EPIKONG_LOOSE, event_loose},
	{0, 0, NULL}
};

t_gui		*create_gui()
{
  t_gui		*tmp;

  tmp = xmalloc(sizeof(*tmp));
  tmp->sdl_flags = VIDEO;
  tmp->quit = 1;
  tmp->pause_timer = 0;
  tmp->timer_time = TIMER;
  tmp->init = init;
  tmp->pos = 0;
  tmp->init(tmp);
  tmp->music = Mix_LoadMUS("sounds/music.ogg");
  if (!tmp->music)
	printf("Mix_LoadMUS(\"sounds/music.ogg\"): %s\n", Mix_GetError());
  tmp->sound = (tmp->music) ? 1 : 0;
  tmp->joy = (SDL_NumJoysticks()) ? SDL_JoystickOpen(0) : NULL;
  tmp->screen = SDL_SetVideoMode(800, 800, 32, tmp->sdl_flags);
  Mix_PlayMusic(tmp->music, -1);
  tmp->volume = MIX_MAX_VOLUME / 4;
  Mix_VolumeMusic(tmp->volume);
  SDL_WM_SetCaption("Epikong", NULL);
  srand(time(NULL));
  return (tmp);
}

Uint32 		animation_timer(Uint32 interval, void *param)
{
  static int 	iter = 0;
  SDL_Event 	event;
  SDL_UserEvent userevent;
  t_gui		*gui;

  gui = (t_gui*)(param);
  (void)(interval);
  if (gui->pause_timer)
    return (gui->timer_time);
  userevent.type = SDL_USEREVENT;
  userevent.data1 = NULL;
  userevent.data2 = NULL;
  event.type = SDL_USEREVENT;
  if (iter % 3 == 0)
    {
      userevent.code = EPIKONG_MOVE;
      event.user = userevent;
      xsdl_pushevent(&event);
      iter = 0;
    }
  userevent.code = EPIKONG_ANIMATION;
  event.user = userevent;
  xsdl_pushevent(&event);
  --iter;
  return (gui->timer_time);
}

void		init(t_gui *this)
{
 (void)(this);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO
	      | SDL_INIT_JOYSTICK) == -1)
    exit(EXIT_FAILURE);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
			  MIX_DEFAULT_CHANNELS, 4096) == -1)
    exit(EXIT_FAILURE);
}

void		start(t_gui *this, t_map *map, t_character *character)
{
  SDL_Event     ev;
  size_t	i;

  this->timer = xsdl_addtimer(this->timer_time, animation_timer, this);
  while (this->quit == 1 && SDL_WaitEvent(&ev))
  {
    for (i = 0 ; gl_event[i].func ; ++i)
    {
      if (ev.type == gl_event[i].type)
	 {
 	   if (ev.type == SDL_USEREVENT &&
	       (size_t)ev.user.code == gl_event[i].key)
	     gl_event[i].func(this, map, character);
	   else if ((ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
			   && ev.key.keysym.sym == gl_event[i].key)
	     gl_event[i].func(this, map, character);
	   else if ((ev.type == SDL_JOYBUTTONDOWN || ev.type == SDL_JOYBUTTONUP)
		 	&& ev.jbutton.button == gl_event[i].key)
	     gl_event[i].func(this, map, character);
	   else if (ev.type == SDL_JOYHATMOTION && ev.jhat.value == gl_event[i].key)
	     gl_event[i].func(this, map, character);
	   else if (!gl_event[i].key)
	     gl_event[i].func(this, map, character);
	 }
     }
  }
}

