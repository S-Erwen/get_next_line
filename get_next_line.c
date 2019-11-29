/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 22:11:41 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 21:51:59 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		after_endl(char **save, char **line)
{
	int		size;
	char	*temp;

	if (!ft_strchr(*save, '\n'))
	{
		*line = ft_strdup(*save);
		if (*save)
		 	free(*save);
		return (0);
	}
	size = (int)(ft_strchr(*save, '\n') - *save);
	*line = ft_substr(*save, 0, size);
	temp = ft_strdup(*save + size + 1);
	if (*save)
		free(*save);
	*save = ft_strdup(temp);
	if (temp)
		free(temp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	int			readed;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!save)
		save = ft_strdup("");
	while (!ft_strchr(save, '\n')
		&& (readed = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		temp = ft_strjoin(&save, buffer);
		save = ft_strdup(temp);
		if (temp)
			free(temp);
	}
	return (after_endl(&save, line));
}
