/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:27:06 by yaajagro          #+#    #+#             */
/*   Updated: 2025/06/20 02:12:21 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	log_state("INIT PARSING", 3);
	if (map_parsing(ac, av, &cub))
		return (ft_malloc(-1), 1);
	check_rendring_depend(&cub);
	log_state("VALID MAP", 1);
	ft_malloc(-1);
	return (0);
}
