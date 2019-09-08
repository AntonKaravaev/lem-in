/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:27:52 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/06 14:18:11 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_str2del(char ***str)
{
	int i;

	i = 0;
	if (*str && **str != NULL)
	{
		while ((*str)[i] != NULL)
		{
			ft_strdel(&((*str)[i]));
			i++;
		}
		free(*str);
	}
}