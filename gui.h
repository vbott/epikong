/*
** gui for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 09:44:43 PM CET botton vivien
** Last update Fri 25 Mar 2011 09:44:43 PM CET botton vivien
*/

#ifndef		_GUI_
#define		_GUI_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "map.h"
#include "character.h"

#define EPIKONG_MOVE 1
#define EPIKONG_ANIMATION 2
#define EPIKONG_PAUSE 3
#define EPIKONG_END 4
#define EPIKONG_LOOSE 5

#define VIDEO (SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ASYNCBLIT)

#define	TIMER 60

typedef struct	s_menu
{
  char		*path;
  char		*name;
}		t_menu;

typedef	struct	s_gui
{
  int		sdl_flags;
  Mix_Music 	*music;
  SDL_Surface	*screen;
  TTF_Font      *font;
  SDL_Joystick  *joy;
  SDL_TimerID	timer;
  int		pause_timer;
  int		timer_time;
  int		sound;
  int		volume;
  int		quit;
  int		pos;

  void		(*init)(struct s_gui*);
}		t_gui;

typedef struct	s_event
{
  int		type;
  size_t	key;
  void		(*func)(t_gui *, t_map *, t_character *);
}		t_event;

Uint32		animation_timer(Uint32 interval, void *param);

void		event_quit(t_gui *, t_map *, t_character *);
void		event_up(t_gui *, t_map *, t_character *);
void		event_down(t_gui *, t_map *, t_character *);
void		event_left(t_gui *, t_map *, t_character *);
void		event_right(t_gui *, t_map *, t_character *);
void		event_space(t_gui *, t_map *, t_character *);

void		event_up_up(t_gui *, t_map *, t_character *);
void		event_down_up(t_gui *, t_map *, t_character *);
void		event_left_up(t_gui *, t_map *, t_character *);
void		event_right_up(t_gui *, t_map *, t_character *);
void		event_space_up(t_gui *, t_map *, t_character *);
void		event_centered(t_gui *, t_map *, t_character *);

/* event_volume.c */
void            event_volume_up(t_gui *, t_map *, t_character *);
void            event_volume_down(t_gui *, t_map *, t_character *);

void		draw_cursor(t_gui *gui, int pos_new, int old_pos);
void		menu_quit(t_gui *gui, t_map *map, t_character *character);
void		menu_down(t_gui *gui, t_map *map, t_character *character);
void		menu_up(t_gui *gui, t_map *map, t_character *character);
void		menu_enter(t_gui *gui, t_map *map, t_character *character);

/* gui_menu.c */
void		show_menu(t_gui *gui);

void		event_fullscreen(t_gui *, t_map *, t_character *);
void		event_move(t_gui *, t_map *, t_character *);
void		event_animation(t_gui *, t_map *, t_character *);
void		event_pause(t_gui *, t_map *, t_character *);
void            event_sound(t_gui *gui, t_map *map, t_character *character);

void		event_end(t_gui *, t_map *, t_character *);
void		event_loose(t_gui *, t_map *, t_character *);

void            event_speed_up(t_gui *, t_map *, t_character *);
void            event_slow_down(t_gui *, t_map *, t_character *);

t_gui		*create_gui();
void		init(t_gui *);
void		start(t_gui *, t_map *, t_character *);

void		push_event(int code);

int		load_file(t_map *map, const char *path,
	       	t_character **characters, t_gui *gui);

/* load_players.c */
void		load_players(t_map *map, t_character **characters);

#endif		/* _GUI_ */
