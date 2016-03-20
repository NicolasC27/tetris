/*
** mode.c for mode.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 17 19:06:26 2016 Chevalier Nicolas
** Last update Sun Mar 20 03:10:56 2016 Chevalier Nicolas
*/

#include <termios.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include "tetris.h"

int			mode(int i, int option)
{
  static struct termios	oldT;
  static struct termios	newT;

  if (i == 0)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);

      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      if (option == 1)
	{
	  newT.c_cc[VMIN] = 0;
	  newT.c_cc[VTIME] = 1;
	}
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    ioctl(0, TCSETS, &oldT);
  return (0);
}
