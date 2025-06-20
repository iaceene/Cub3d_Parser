/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utile_7.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:18:13 by yaajagro          #+#    #+#             */
/*   Updated: 2025/06/19 02:21:46 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_rendring_depend(t_cub *cub)
{
	char	*door_path;
	int		fd;

	door_path = "./textures/door/__door1.xpm";
	if (!cub)
		return ;
	log_state("CHECKING DEPENDENCIES", 3);
	fd = open(door_path, 0);
	if (fd == -1)
		log_state("DOOR IMG NOT FOUND", 0);
	close(fd);
	log_state("CHECKING DEPENDENCIES", 1);
}

int	get_len(char **s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	xe_cond(int c)
{
	return (!c || c == ' ');
}

int	only_space_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
