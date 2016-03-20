/*
** main_utils.c for main_utils.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Mar 20 22:50:32 2016 Chevalier Nicolas
** Last update Sun Mar 20 22:50:48 2016 Chevalier Nicolas
*/

#include "tetris.h"

int		check_one_valid(t_list *list)
{
  t_tetriminos	*tmp;

  tmp = list->first;
  while (tmp)
    {
      if (tmp->valid == true)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
