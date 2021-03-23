/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:19:46 by rcollas           #+#    #+#             */
/*   Updated: 2021/03/23 10:34:44 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_error(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i++])
	{
		if (*base == '+' || *base == '-')
			return (1);
	}
	if (base == '\0' || ft_strlen(base) == 1)
		return (1);
	i = 0;
	while (base[i])
	{
		while (base[j++])
		{
			if (base[i] == base[j])
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	num;
	char		to_print;
	int			len;

	num = nbr;
	if (check_error(base))
		return ;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num > len)
		ft_putnbr_base(num / len, base);
	num = num % len;
	to_print = base[num];
	write(1, &to_print, 1);
}
