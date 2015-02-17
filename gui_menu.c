/*
** gui_menu.c for epikong in /home/audrade/work/epikong
** 
** Made by cailleux carole
** Login   <caille_c@epitech.net>
** 
** Started on  Sun Mar 27 01:30:11 2011 cailleux carole
** Last update Sun Mar 27 01:30:11 2011 cailleux carole
*/

#include <SDL/SDL_ttf.h>
#include "xfunctions.h"
#include "gui.h"

const t_menu		gl_menu[] = {
  {"maps/stage1.map", "Lode Runner level"},
  {"maps/stage2.map", "Hello Kitty level"},
  {"maps/stage3.map", "Map of the Loutre"},
  {"maps/stage4.map", "Gargamel's place"},
  {"maps/stage5.map", "Poney level"},
  {NULL, NULL}
};

static const t_event		gl_event[] = {
  {SDL_QUIT, 0, menu_quit},
  {SDL_KEYDOWN, SDLK_ESCAPE, menu_quit},
  {SDL_JOYHATMOTION, SDL_HAT_UP, menu_up},
  {SDL_KEYDOWN, SDLK_UP, menu_up},
  {SDL_JOYHATMOTION, SDL_HAT_DOWN, menu_down},
  {SDL_KEYDOWN, SDLK_DOWN, menu_down},
  {SDL_JOYBUTTONUP, 0, menu_enter},
  {SDL_KEYDOWN, SDLK_RETURN, menu_enter},
  {0, 0, NULL}
};

static void			loop_actions(t_gui *this)
{
  SDL_Event     ev;
  size_t        i;

  while (this->quit == 1 && SDL_WaitEvent(&ev))
    {
      for (i = 0 ; gl_event[i].func ; ++i)
	{
	  if (ev.type == gl_event[i].type)
	  {
	   if ((ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
			   && ev.key.keysym.sym == gl_event[i].key)
	     gl_event[i].func(this, NULL, NULL);
	   else if ((ev.type == SDL_JOYBUTTONDOWN || ev.type == SDL_JOYBUTTONUP)
		 	&& ev.jbutton.button == gl_event[i].key)
	     gl_event[i].func(this, NULL, NULL);
	   else if (ev.type == SDL_JOYHATMOTION && ev.jhat.value == gl_event[i].key)
	     gl_event[i].func(this, NULL, NULL);
	   else if (!gl_event[i].key)
	     gl_event[i].func(this, NULL, NULL);
	  }
	}
    }
}

void		quit_menu(t_gui *gui)
{
  if (gui->music)
    Mix_FreeMusic(gui->music);
  if (gui->joy)
    SDL_JoystickClose(gui->joy);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
}

void		show_menu(t_gui *gui)
{
  int		i;
  SDL_Surface	*text;
  SDL_Rect	pos;
  SDL_Color	color;

  xttf_init();
  pos.x = 150;
  pos.y = 150;
  color.r = 100;
  color.g = 200;
  color.b = 120;
  gui->font = xttf_openfont("fonts/DF.ttf", 65);
  for (i = 0 ; gl_menu[i].name ; i++)
    {
      text = TTF_RenderText_Blended(gui->font, gl_menu[i].name, color);
      xsdl_blitsurface(text, NULL, gui->screen, &pos);
      SDL_FreeSurface(text);
      pos.y += 100;
    }
  SDL_Flip(gui->screen);
  draw_cursor(gui, 0, 0);
  loop_actions(gui);
  TTF_CloseFont(gui->font);
  quit_menu(gui);
}

