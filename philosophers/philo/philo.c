/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:26:16 by chpark            #+#    #+#             */
/*   Updated: 2022/05/24 14:26:23 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	life_checking(t_all *all, int i, int j)
{
	while (1)
	{
		i = 0;
		while (i < all->table->philo_num)
		{
			if (get_time() - all->philo[i].last_meal > all->table->time_to_die)
			{
				message (all, &all->philo[i], "has died");
				return (1);
			}
			j = -1;
			while (++j < all->table->philo_num && all->philo[j].eat_times \
				>= all->table->num_to_eat)
			{
				if (j == all->table->philo_num - 1)
				{
					write (1, "All Philosophers have eaten enough\n", 35);
					return (1);
				}
			}
			usleep (500);
			i++;
		}
	}
	return (0);
}

void	*life(void *cp_all)
{
	t_all	*all;
	t_list	*philo_c;

	all = cp_all;
	philo_c = all->philo + all->philo_count;
	philo_c->last_meal = get_time();
	while (1)
	{
		eating(all, philo_c);
		message(all, philo_c, "is sleeping");
		waiting (all->table->time_to_sleep);
		message(all, philo_c, "is thinking");
	}
	return (NULL);
}

int	create_philo(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->table->philo_num)
	{
		all->table->start_time = get_time();
		all->philo_count = i;
		if (pthread_create(&all->philo[i].thread_id, NULL, life, all))
			return (-1);
		usleep(50);
		i++;
	}
	return (0);
}

int	ft_thread_detach(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->table->philo_num)
	{
		if (pthread_detach(all->philo[i].thread_id))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_tab	table;
	t_all	all;

	all.table = &table;
	if (argc < 5 || argc > 6)
		error("Wrong number of arguments");
	if (argv_parsing(&table, argv))
		error("Wrong argument");
	if (philo_alloc(&all))
		error("Allocation failed");
	if (mutex_init(all.table) == -1)
		error("Mutex initialization failed");
	philo_init(&all);
	if (create_philo(&all))
		error("Failed to create a thread");
	if (ft_thread_detach(&all))
		error("Thread detach failed");
	life_checking(&all, 0, 0);
	free(all.philo);
	return (0);
}
