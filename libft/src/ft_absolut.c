/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:02:02 by jhurpy            #+#    #+#             */
/*   Updated: 2023/06/17 03:02:57 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_absolut(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
