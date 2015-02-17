/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sat Mar 26 20:54:34 CET 2011 cerisier mickael
** Last update Sat Mar 26 20:54:34 CET 2011 cerisier mickael
*/

#include <stdlib.h>
#include "character.h"
#include "xfunctions.h"

static void	create_listsprite(size_t y, t_listsprite **list)
{
  size_t	x;
  t_listsprite	*tmp;
  t_listsprite	*last;
  t_listsprite	*first;

  last = NULL;
  first = NULL;
  for (x = 0; x < 3; x++)
  {
    tmp = xmalloc(sizeof(*tmp));
    tmp->x = x * 32;
    tmp->y = y;
    tmp->next = NULL;
    if (!first)
      first = tmp;
    else
      last->next = tmp;
    last = tmp;
  }
  last->next = first;
  *list = first->next;
}

static void	create_sprite(t_character *character, const char *path)
{
  character->sprites = ximg_load(path);
  create_listsprite(32, &character->left);
  create_listsprite(64, &character->right);
  create_listsprite(96, &character->up);
  character->face = xmalloc(sizeof(*(character->face)));
  character->face->x = 32;
  character->face->y = 0;
  character->face->next = character->face;
}

static void	create_player(t_character *character)
{
  character->direction = NOMOVE;
  character->newdirection = NOMOVE;
  character->nbdirect = 0;
  character->live = 3;
  character->moveup = player_moveup;
  character->movedown = player_movedown;
  character->moveleft = player_moveleft;
  character->moveright = player_moveright;
  create_sprite(character, "pictures/chara.png");
}

static void	create_monster(t_character *character)
{
  e_move	tmp;

  tmp = (rand() % 2) ? RIGHT : LEFT;
  character->direction = tmp;
  character->newdirection = tmp;
  character->nbdirect = 1;
  character->live = 1;
  character->moveup = NULL;
  character->movedown = NULL;
  character->moveleft = monster_moveleft;
  character->moveright = monster_moveright;
  create_sprite(character, "pictures/monster.png");
}

static t_charcreate	gl_charcreate[] = {
	{INGAME, create_player},
	{MONSTER, create_monster},
	{0, NULL}
};

t_character	*create_character(size_t x, size_t y, e_block type)
{
  size_t	i;
  t_character	*tmp;

  if (type != INGAME && type != MONSTER)
    return (NULL);
  tmp = xmalloc(sizeof(*tmp));
  tmp->x = x;
  tmp->y = y;
  tmp->oldx = (float)x;
  tmp->oldy = (float)y;
  tmp->key = 0;
  tmp->type = type;
  tmp->next = NULL;
  i = 0;
  while (gl_charcreate[i].func != NULL && gl_charcreate[i].type != type)
    i++;
  if (gl_charcreate[i].func != NULL)
    gl_charcreate[i].func(tmp);
  else
  {
    free(tmp);
    tmp = NULL;
  }
  return (tmp);
}
