/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/02 12:30:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_s1_s2;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		str_s1_s2 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str_s1_s2)
		{
			while (*s1)
			{
				str_s1_s2[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				str_s1_s2[i++] = *s2;
				s2++;
			}
			str_s1_s2[i] = '\0';
			return (str_s1_s2);
		}
	}
	return (NULL);
}
