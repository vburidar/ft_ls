/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:39:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/05 11:33:44 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*curseur1;
	unsigned char	*curseur2;

	i = 0;
	curseur1 = (unsigned char*)(s1);
	curseur2 = (unsigned char*)(s2);
	while (curseur1[i] == curseur2[i] && curseur1[i] && curseur2[i])
		i = i + 1;
	if (curseur1[i] != curseur2[i])
		return (curseur1[i] - curseur2[i]);
	else
		return (0);
}
