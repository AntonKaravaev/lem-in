/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:51 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/18 22:59:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (size)
	{
		ptr = (void *)malloc(sizeof(*ptr) * size);
		if (ptr)
		{
			ft_memset(ptr, '\0', size);
			return (ptr);
		}
	}
	return (NULL);
}
