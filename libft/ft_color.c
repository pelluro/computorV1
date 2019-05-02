#include "libft.h"

void	ft_putstr_color(char const *s, const char *color)
{
	ft_putstr_color_fd(s, color, 1);
}

void	ft_putstr_color_fd(char const *s, const char *color, int fd)
{
	ft_color_switch_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_color_reset_fd(fd);
}

void	ft_color_switch_fd(const char *color, int fd)
{
	ft_putstr_fd(color, fd);
}

void	ft_color_reset_fd(int fd)
{
	ft_putstr_fd(COL_RESET, fd);
}
