/*
** block for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 08:56:02 PM CET botton vivien
** Last update Fri 25 Mar 2011 08:56:02 PM CET botton vivien
*/

#include <stdlib.h>
#include <unistd.h>
#include "block.h"

static const t_type gl_type[] = {
	{'w', WALL, 0},
	{'s', LADDER, 0},
	{'m', MONSTER, 1},
	{'o', OUTGAME, 0},
	{'i', INGAME, 0},
	{'l', LIVE, 1},
	{'k', KEY, 0},
	{'g', WEAPON, 1},
	{'0', PORTAL, 0},
	{'1', PORTAL, 1},
	{'2', PORTAL, 2},
	{'3', PORTAL, 3},
	{'4', PORTAL, 4},
	{'5', PORTAL, 5},
	{'6', PORTAL, 6},
	{'7', PORTAL, 7},
	{'8', PORTAL, 8},
	{'9', PORTAL, 9}
};

e_block		get_type_by_letter(char c)
{
  size_t	i;

  for (i = 0; i < sizeof(gl_type) / sizeof(t_type); ++i)
  {
    if (gl_type[i].c == c)
      return (gl_type[i].type);
  }
  return (NONE);
}

int		get_life_by_letter(char c)
{
  size_t	i;

  for (i = 0; i < sizeof(gl_type) / sizeof(t_type); ++i)
  {
    if (gl_type[i].c == c)
      return (gl_type[i].data);
  }
  return (0);
}

t_block		*create_block(e_block type, size_t x, size_t y, int data)
{
  t_block	*tmp;

  tmp = malloc(sizeof(*tmp));
  if (!tmp)
    return (NULL);
  tmp->type = type;
  tmp->x = x;
  tmp->y = y;
  tmp->data = data;
  return (tmp);
}
