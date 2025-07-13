/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:14:50 by yaajagro          #+#    #+#             */
/*   Updated: 2025/07/09 13:34:36 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void exit_cub(void)
{
	write(1, COLOR_RED, ft_strlen(COLOR_RED));
	write(1, " ]\n", 4);
	print_prog();
	write(1, "[ 🚧 CLEANING AND EXITING ]\n", 31);
	write(1, COLOR_RESET, ft_strlen(COLOR_RESET));
	ft_malloc(-1);
	exit(1);
}

static void print_log_prefix(int fd, int flag)
{
	if (fd == 2)
		write(2, "[ Error ]\n", 10);
	if (flag == 1)
		write(fd, "[ ✅ ", 7);
	else if (flag == 3)
		write(fd, "[ ⏳ ", 7);
	else
		write(fd, "[ ⛔ ", 7);
}

static void print_log_message(char *msg, int fd)
{
	int i;

	i = 0;
	while (msg[i])
	{
		write(fd, &msg[i], 1);
		i++;
	}
}

void log_time()
{
	struct timeval av;
	static struct timeval start;
	static int i;

	if (!i)
	{
		gettimeofday(&start, NULL);
		gettimeofday(&av, NULL);
	}
	else
		gettimeofday(&av, NULL);
	if (av.tv_usec < start.tv_usec)
	{
		av.tv_sec -= 1;
		av.tv_usec += 1000000;
	}
	i++;
	write(1, "[ ", 2);
	print_log_message(ft_itoa((int)(av.tv_sec - start.tv_sec)), 1);
	print_log_message(ft_strjoin(".", ft_itoa((int)(av.tv_usec - start.tv_usec))), 1);
	write(1, "s ] ", 4);
}

void print_prog()
{
	static int i;
	int j;

	j = -1;
	write(1, "[", 1);
	while (++j < i)
		write(1, "*", 1);
	while (++j < 43)
		write(1, "-", 1);
	write(1, "]\n", 2);
	i++;
	if (i + 57 == 100)
		printf("Done 100%%\n");
	else
		printf("Progress %d%%\n", i + 57);
}

void log_state(char *msg, int flag)
{
	int fd;
	char *clr;

	if (!msg)
		return;
	fd = 1;
	usleep(1 * 15000);
	write(fd, "\x1B[H\x1B[2J", ft_strlen("\x1B[H\x1B[2J"));
	clr = COLOR_GREEN;
	if (TIMESTAMP)
		log_time();
	if (!flag)
	{
		fd = 2;
		clr = COLOR_RED;
	}
	else if (flag == 3)
		clr = COLOR_YELLOW;
	write(fd, clr, ft_strlen(clr));
	print_log_prefix(fd, flag);
	print_log_message(msg, fd);
	if (fd == 2)
		exit_cub();
	else
		write(fd, " ]\n", 3);
	if (ft_strncmp("CHECKING LINE", msg, ft_strlen("CHECKING LINE")))
		print_prog();
	write(fd, COLOR_RESET, ft_strlen(COLOR_RESET));
}
