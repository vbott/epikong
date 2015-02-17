/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 00:31:04 CET 2011 cerisier mickael
** Last update Sat Mar 26 00:31:04 CET 2011 cerisier mickael
*/

#include "character.h"

static t_move		gl_move[] = {
	{NOMOVE, 10, NULL, FACE, 0, 0},
	{UP, 1, move_up, NOMOVE, 1, 0},
	{RIGHT, 1, move_right, NOMOVE, 1, 0},
	{DOWN, 1, move_down, NOMOVE, 1, 0},
	{LEFT, 1, move_left, NOMOVE, 1, 0},
	{JUMP, 2, jump, FALL, 1, 1},
	{RJUMP, 1, jump_right, RJUMPCONT, 1, 0},
	{LJUMP, 1, jump_left, LJUMPCONT, 1, 0},
	{FALL, -1, fall, FALL, 1, 1},
	{RFALL, 1, fall_right, NOMOVE, 1, 1},
	{LFALL, 1, fall_left, NOMOVE, 1, 1},
	{RJUMPCONT, 1, move_right, RFALL, 1, 1},
	{LJUMPCONT, 1, move_left, LFALL, 1, 1},
	{FACE, 0, NULL, FACE, 0, 0}
};

static void	handle_collision(t_character *monster, t_character *player)
{
  if (monster->y == player->y && player->live >= 1)
   {
     if (monster->x == player->x)
       player->live--;
     else if (monster->x - 1 == player->x &&
	      monster->direction == LEFT && player->direction == RIGHT)
	player->live--;
     else if (monster->x + 1 == player->x &&
	      monster->direction == RIGHT && player->direction == LEFT)
	player->live--;
    }
}

inline int	is_traversable(t_map *map, size_t x, size_t y)
{
  return (map->block[y][x]->type != WALL && map->block[y][x]->type != LADDER);
}

static void	change_direction(t_character *c, t_map *map)
{
  if (c->nbdirect == 0)
  {
    c->nbdirect = gl_move[c->direction].nbnext;
    c->direction = gl_move[c->direction].next;
    c->nbdirect *= gl_move[c->direction].nb;
  }
  if ((c->nbdirect == 0 && gl_move[c->direction].next == NOMOVE) ||
      ((c->direction == NOMOVE || c->direction == FACE)
       && c->newdirection != NOMOVE))
  {
    c->direction = c->newdirection;
    c->nbdirect = gl_move[c->direction].nb;
  }
  if (c->newdirection == UP && map->block[c->y][c->x]->type == LADDER)
  {
    c->direction = c->newdirection;
    c->nbdirect = gl_move[c->direction].nb;
  }
  else if (c->y + 1 >= map->y || (is_traversable(map, c->x, c->y + 1) &&
	   !gl_move[c->direction].blocking))
  {
    c->direction = FALL;
    c->nbdirect = gl_move[c->direction].nb;
  }
  change_down(c, map);
}

void		move(t_character *c, t_character *player, t_map *map)
{
  c->oldx = (float)c->x;
  c->oldy = (float)c->y;
  take_object(c, map);
  change_direction(c, map);
  if (map->block[c->y][c->x]->type == PORTAL)
    take_portal(c, map);
  if (c->nbdirect)
  {
    if (gl_move[c->direction].func)
      gl_move[c->direction].func(c, map);
    if (c->nbdirect > 0)
      c->nbdirect--;
  }
  if (player != c)
    handle_collision(c, player);
}
