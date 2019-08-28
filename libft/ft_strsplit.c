/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:35 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/25 03:29:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int words;
	int flag;
	int	i;

	words = 0;
	flag = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		else if (flag == 1)
		{
			words++;
			flag = 0;
		}
		i++;
	}
	return (words);
}

static char		**get_words(char **fresh_str, char const *s, char c)
{
	int		i;
	int		j;
	int		w;
	char	*fresh_word;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			fresh_word = ft_strsub(s, j, i - j);
			fresh_str[w++] = fresh_word;
			i--;
		}
		i++;
	}
	fresh_str[w] = NULL;
	return (fresh_str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh_str;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(fresh_str = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	return (get_words(fresh_str, s, c));
}
