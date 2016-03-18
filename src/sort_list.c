/*
** sort_list.c for sort_list.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 17 18:55:42 2016 Chevalier Nicolas
** Last update Thu Mar 17 23:22:18 2016 Chevalier Nicolas
*/

#include	"tetris.h"

int		compare_string(char *str1, char *str2)
{
  int		i;
  int		loop;
  int		nb1;
  int		nb2;

  i = 0;
  loop = 0;
  while (!loop)
    {
      nb1 = str1[i];
      nb2 = str2[i];
      (nb1 == nb2) ? (i++) : (loop++);
    }
  if (nb1 > nb2)
      return (1);
  return (0);
}

/*
** Sorting with method insertion in recursive
*/
void		sorting_insertion(t_tetriminos **list, t_tetriminos *tmp)
{
  if ((*list) == NULL)
    {
      (*list) = tmp;
      tmp->next = NULL;
    }
  else if ((compare_string((*list)->name, tmp->name)))
    {
      tmp->next = (*list);
      (*list) = tmp;
    }
  else
    sorting_insertion(&(*list)->next, tmp);
}

/*
** Function whom sort the list per ascending order alphabetical
*/
t_tetriminos	*sort_list(t_tetriminos *list)
{
  t_tetriminos	*tmp;
  t_tetriminos	*tmp2;
  t_tetriminos	*tmp3;

  tmp3 = NULL;
  tmp = list;
  while (tmp)
    {
      tmp2 = tmp->next;
      sorting_insertion(&tmp3, tmp);
      tmp = tmp2;
    }
  /* my_putstr(tmp->next->name); */
  /* tmp = tmp->next; */
  return (tmp3);
}
