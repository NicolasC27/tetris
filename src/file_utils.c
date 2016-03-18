/*
** file_utils.c for file_utils.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Mar 18 02:22:36 2016 Chevalier Nicolas
** Last update Fri Mar 18 02:26:49 2016 Chevalier Nicolas
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
  while (dirent[++i] && dirent[i] != '.')
    nb++;
  if ((name = malloc(sizeof(*name) * (nb + 1))) == NULL)
    return (NULL);
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
** Count line of file
*/
void		count_height(t_files *file, t_parser *parser)
{
  char		*tmp;
  int		fd;

  parser->count_height = -1;
  fd = file->fd;
  while ((tmp = get_next_line(fd)))
    {
      parser->count_height += 1;
      free(tmp);
    }
  close(fd);
  file->fd = open((file->link = concat("./tetriminos/", file->dirent->d_name)),
  		 O_RDONLY);
}
