/*
** menu_actions.c for kong in /home/audrade/work/epikong
** 
** Made by cailleux carole
** Login   <caille_c@epitech.net>
** 
** Started on  Sun Mar 27 07:16:04 2011 cailleux carole
** Last update Sun Mar 27 07:16:04 2011 cailleux carole
*/

#include <stdlib.h>
#include "xfunctions.h"
#include "gui.h"

extern t_menu gl_menu[];

void		draw_cursor(t_gui *gui, int pos_new, int old_pos)
{
  SDL_Rect      pos;
  SDL_Color     color;
  SDL_Surface   *text;
  SDL_Surface	*black;

  pos.x = 100;
  pos.y = 150 + old_pos * 100;
  color.r = 100;
  color.g = 200;
  color.b = 120;
  black = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, 100, 32, 0, 0, 0, 0);
  xsdl_blitsurface(black, NULL, gui->screen, &pos);
  SDL_FreeSurface(black);
  pos.y = 150 + pos_new * 100;
  text = TTF_RenderText_Blended(gui->font, ">", color);
  xsdl_blitsurface(text, NULL, gui->screen, &pos);
  SDL_FreeSurface(text);
  SDL_Flip(gui->screen);
}

void		menu_quit(t_gui *gui, t_map *map, t_character *character)
{
  (void)(map);
  (void)(character);
  gui->quit = 0;
}

void		menu_down(t_gui *this, t_map *map, t_character *character)
{
  int		oldpos;

  oldpos = this->pos;
  (void)(map);
  (void)(character);
  this->pos = (this->pos < 4) ? this->pos + 1 : 0;
  draw_cursor(this, this->pos, oldpos);
}

void		menu_up(t_gui *this, t_map *map, t_character *character)
{
  int		oldpos;

  oldpos = this->pos;
  (void)(map);
  (void)(character);
  this->pos = (this->pos) ? this->pos - 1 : 4;
  draw_cursor(this, this->pos, oldpos);
}

void		menu_enter(t_gui *this, t_map *map, t_character *characters)
{
  int		i;

  for (i = this->pos; i < 5; ++i)
  {
    map = create_map(this);
    if (load_file(map, gl_menu[i].path, &characters, this) == -1)
    {
     fprintf(stderr, "Incorrect file : %s\n", gl_menu[i].path);
     exit(EXIT_FAILURE);
    }
   this->quit = 1;
   start(this, map, characters);
   if (this->quit == 2)
    i--;
   if (this->quit == 3)
    break;
  }
  if (i == 5)
    puts("Vous avez gagne !");
}
