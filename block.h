/*
** block for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 08:50:04 PM CET botton vivien
** Last update Fri 25 Mar 2011 08:50:04 PM CET botton vivien
*/

#ifndef _BLOCK_
#define _BLOCK_

typedef	enum	e_block
{
  NONE,
  WALL,
  LADDER,
  MONSTER,
  OUTGAME,
  INGAME,
  LIVE,
  KEY,
  PORTAL,
  WEAPON
}		e_block;

typedef	struct	s_block
{
  e_block	type;
  size_t	x;
  size_t	y;
  int		data;
} t_block;

typedef	struct	s_type
{
  char		c;
  e_block	type;
  int		data;
} t_type;

t_block		*create_block(e_block type, size_t x, size_t y, int data);
e_block		get_type_by_letter(char c);
int		get_life_by_letter(char c);

#endif /* _BLOCK_ */
