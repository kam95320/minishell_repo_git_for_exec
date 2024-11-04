/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:52:16 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/03 13:58:26 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/env/env.h"
#include "export_internal.h"

bool	is_valid_identifier(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i] || !(ft_isalpha(arg[i]) || arg[i] == '_'))
		return (false);
	while (arg[++i])
		if (!(ft_isalnum(arg[i]) || arg[i] == '_' || arg[i] == '='))
			return (false);
	return (true);
}

void	print_invalid_identifier_error(char *arg)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}
