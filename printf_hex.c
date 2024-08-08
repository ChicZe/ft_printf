/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <cristianiusca13@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:36:23 by ciusca            #+#    #+#             */
/*   Updated: 2023/11/09 16:44:25 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	printf_hex(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr != 0)
		count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "(nil)", 5);
	else
	{
		ft_put_ptr(ptr);
		count += ft_ptr_len(ptr);
	}
	return (count);
}
