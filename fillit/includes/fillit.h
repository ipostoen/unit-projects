/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:44:21 by ipostoen          #+#    #+#             */
/*   Updated: 2017/12/11 16:00:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

#define FIND_FIGURE(b, s, r) if (ft_strequ(b, s)) return (r);

typedef struct		s_blk
{
	char			c;
	int 			x[4];
	int				y[4];
	struct s_blk	*next;
}					t_fig;

void				ft_error(void);
int					ft_figure_size(t_fig *figure);
char				**ft_fill_empty(char **tab, int max);
t_fig				*ft_update_xy(t_fig *figure, int x, int y);
char				**ft_result(t_fig *figure, int max);

t_fig	*ft_open(char *str);
t_fig	*ft_read_figures(int fd, t_fig *figure);
char	*ft_what_figure(char *buffer);
t_fig	*ft_figure_xy(t_fig *figure, char *buffer);
int		ft_is_figure(int fd, char *buffer, int size, int read_size);
char	*ft_strntrim(char const *s, char c);
#endif
