/*
** my_puterr.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Mar 16 16:40:53 2016 romain samuel
** Last update Wed Mar 16 16:43:02 2016 romain samuel
*/

#include "tetris.h"

int	my_puterr(char *str)
{
  write(2, "Error: tetris: ", my_strlen("Error: tetris:"));
  write(2, str, my_strlen(str));
  return (-1);
}
