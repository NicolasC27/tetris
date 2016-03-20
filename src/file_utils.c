/*
** file_utils.c for file_utils.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Mar 18 02:22:36 2016 Chevalier Nicolas
** Last update Sun Mar 20 20:09:17 2016 Chevalier Nicolas
*/

#include <sys/types.h>
#include <fcntl.h>
#include "tetris.h"
#include "gnl.h"

/*
** Remove the end of the filename (".tetrimino")
*/
char		*separate_name(char *dirent)
{
  char		*name;
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  if (dirent[0] == '.')
    {
      nb++;
      i++;
    }
  while (dirent[++i] && !(my_strncmp(&dirent[i], ".tetrimino", 0)))
    nb++;
  if (!(my_strncmp(&dirent[i], ".tetrimino", 0)))
    return (NULL);
  if ((name = malloc(sizeof(*name) * (nb + 1))) == NULL)
    exit_tetris("Problem with malloc\n", -1);
  i = 0;
  while (i < nb + 1)
    name[i++] = '\0';
  i = -1;
  while (++i < nb)
    name[i] = dirent[i];
  name[i] = '\0';
  return (name);
}

/*
** Check space at end of file
*/
int		check_space(char **tmp, t_parser *parser, int i)
{
 int		j;

 if (tmp[i][0] == '\0')
   parser->count_height -= 1;
 else if (tmp[i][0] == ' ')
   {
     j = 0;
     while (tmp[i][j])
       {
	 if (tmp[i][j] != ' ')
	   return (0);
	 if (tmp[i][j + 1] == '\0')
	   {
	     parser->count_height -= 1;
	     return (0);
	   }
	 j++;
       }
     my_putchar('\n');
   }
  return (0);
}

int		my_strlen_tab(char **old)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (old[++i])
    nb++;
  return (nb);
}

char		**my_realloctab(char **ptr, size_t size)
{
  char		**new;
  int		i;

  i = -1;
  if ((new = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  while (ptr[++i])
    new[i] = ptr[i];
  new[i] = '\0';
  return (new);
}

/*
** Count line of file
*/
void		count_height(t_files *file, t_parser *parser)
{
  /* char		**tmp; */
  char		*s;
  int		fd;

  parser->count_height = -1;
  fd = file->fd;
  /* i = 0; */
  /* if ((tmp = malloc(sizeof((*tmp)) * 10)) == NULL) */
  /*   exit_tetris("Problem with malloc\n", -1); */
  while ((s = get_next_line(fd)))
    {
      parser->count_height += 1;
      free(s);
      /*  i += 1; */
      /* tmp[i] = '\0'; */
      /* if (i >= 9) */
      /* 	tmp = my_realloctab(tmp, 10 * sizeof(char *)); */
    }
  /* while (i > 0) */
  /*   check_space(tmp, parser, --i); */
  /* i = 0; */
  /* while (tmp[i]) */
  /*   free(tmp[i++]); */
  /* free(tmp); */
  close(fd);
  file->fd = open((file->link = concat("./tetriminos/", file->dirent->d_name)),
  		 O_RDONLY);
}
