/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:28:26 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/03 14:36:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, t_ran ran, int *j)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || ran.fzero > 0)
	{
		if (str[i] == '\0')
		{
			*j -= 1;
			ft_putchar(str[i]);
			ran.fzero--;
		}
		else
			ft_putchar(str[i]);
		i++;
		*j = i;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzerop(void *s, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

int		ft_flagsup(char *str, t_ran *ran, t_spec *s)
{
	if (str[ran->i] == 'j')
	{
		ran->i++;
		s->flag = 5;
		return (1);
	}
	else if (str[ran->i] == 'z')
	{
		ran->i++;
		s->flag = 6;
		return (1);
	}
	return (0);
}
