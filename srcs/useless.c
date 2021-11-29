/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:25:23 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 11:26:06 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	norme(double c, double h, double x, double m)
{
	if (h >= 0 && h < 1)
		return (get_rgb((int)((c + m) * 255), (int)((x + m) * 255)
				, (int)(m * 255)));
	if (h >= 1 && h < 2)
		return (get_rgb((int)((x + m) * 255), (int)((c + m) * 255)
				, (int)(m * 255)));
	if (h >= 2 && h < 3)
		return (get_rgb((int)(m * 255), (int)((c + m) * 255)
				, (int)((x + m) * 255)));
	if (h >= 3 && h < 4)
		return (get_rgb((int)(m * 255), (int)((x + m) * 255)
				, (int)((c + m) * 255)));
	if (h >= 4 && h < 5)
		return (get_rgb((int)((x + m) * 255), (int)(m * 255)
				, (int)((c + m) * 255)));
	return (get_rgb((int)((c + m) * 255), (int)(m * 255)
			, (int)((x + m) * 255)));
}
