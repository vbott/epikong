/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Fri Mar 25 22:06:43 CET 2011 cerisier mickael
** Last update Fri Mar 25 22:06:43 CET 2011 cerisier mickael
*/

#ifndef		_CHARACTER_H_
#define		_CHARACTER_H_

#include <unistd.h>
#include "weapon.h"
#include "map.h"

typedef enum	e_move
{
  NOMOVE = 0,
  UP,
  RIGHT,
  DOWN,
  LEFT,
  JUMP,
  RJUMP,
  LJUMP,
  FALL,
  RFALL,
  LFALL,
  RJUMPCONT,
  LJUMPCONT,
  FACE
}		e_move;

typedef struct  s_listsprite
{
  size_t		x;
  size_t		y;
  struct s_listsprite	*next;
}		t_listsprite;

typedef struct	s_character
{
  size_t		x;
  size_t		y;
  float			oldx;
  float			oldy;
  size_t		live;
  e_move		direction;
  e_move		newdirection;
  int			nbdirect;
  int			key;
  e_block		type;
  t_weapon		*weapon;
  SDL_Surface		*sprites;
  t_listsprite		*right;
  t_listsprite		*left;
  t_listsprite		*up;
  t_listsprite		*face;
  struct s_character	*next;
  void			(*moveup)(struct s_character*, t_map *);
  void			(*movedown)(struct s_character*, t_map*);
  void			(*moveleft)(struct s_character*, t_map*);
  void			(*moveright)(struct s_character*, t_map *);
}		t_character;

typedef struct	s_move
{
  e_move	type;
  int		nb;
  void		(*func)(t_character *, t_map *);
  e_move	next;
  int		nbnext;
  int		blocking;
}		t_move;

typedef struct	s_charcreate
{
  e_block	type;
  void		(*func)(t_character *);
}		t_charcreate;

typedef struct	s_object
{
  e_block	type;
  void		(*func)(t_character*, t_map*);
}		t_object;

/* create_character.c */
t_character	*create_character(size_t, size_t, e_block);

/* change_direction.c */
void		change_down(t_character*, t_map*);

/* character.c */
int		is_traversable(t_map*, size_t, size_t);
void		move(t_character*, t_character*, t_map*);

/* character_move.c */
void		move_up(t_character*, t_map*);
void		move_down(t_character*, t_map*);
void		move_right(t_character*, t_map*);
void		move_left(t_character*, t_map*);

/* character_jump.c */
void		jump(t_character*, t_map*);
void		jump_right(t_character*, t_map*);
void		jump_left(t_character*, t_map*);

/* character_fall.c */
void		fall(t_character*, t_map*);
void		fall_right(t_character*, t_map*);
void		fall_left(t_character*, t_map*);

/* player_move.c */
void		player_moveup(t_character*, t_map*);
void		player_movedown(t_character*, t_map*);
void		player_moveleft(t_character*, t_map*);
void		player_moveright(t_character*, t_map*);

/* monster_move.c */
void		monster_moveleft(t_character*, t_map*);
void		monster_moveright(t_character*, t_map*);

/* take_object.c */
void		object_out(t_character *c, t_map *map);
void		object_live(t_character *c, t_map *map);
void		object_key(t_character *c, t_map *map);
void		take_portal(t_character *c, t_map *map);
void		take_object(t_character*, t_map*);

#endif		/* _CHARACTER_H_ */
