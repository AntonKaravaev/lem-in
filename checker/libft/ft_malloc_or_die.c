/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_or_die.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:07:27 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 14:07:32 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void		*ft_malloc_or_die(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)) == NULL)
	{
		perror("malloc");
		exit(1);
	}
	return (ptr);
}
