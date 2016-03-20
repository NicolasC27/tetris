/*
** debug2.c for debug2.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Mar 20 01:14:21 2016 Chevalier Nicolas
** Last update Sun Mar 20 03:10:05 2016 Chevalier Nicolas
*/

#include "tetris.h"

/*
** Calcul width line for display
*/
int	width_line(int **tmp, int a, int nb)
{
  a = 0;
  while (tmp[a][0] != '\0' && tmp[a][0] == nb)
    a++;
  return (tmp[a - 1][1]);
}
