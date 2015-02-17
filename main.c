/*
** main for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Fri 25 Mar 2011 09:34:32 PM CET botton vivien
** Last update Fri 25 Mar 2011 09:34:32 PM CET botton vivien
*/

#if defined (WIN32)
#include <windows.h>
#else
#include <stdio.h>
#endif
#include "gui.h"
#include "map.h"

int		main(int ac, char **av)
{
  t_gui		*gui;

  if (ac == 1)
  {
    gui = create_gui();
    show_menu(gui);
    free(gui);
  }
  else
    fprintf(stderr, "usage  : %s\n", av[0]);
  return (0);
}

#if defined (WIN32)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  char  **args;

  args = malloc(2 * sizeof(*args));
  args[0] = "epikong.exe";
  args[1] =  NULL;
  main(1, args);
  return (1);
}
#endif
