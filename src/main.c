#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096


size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	tmp = s;
	while (n > 0)
	{
		*tmp++ = '\0';
		n--;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

void	ft_putstr_fd(char const *s, int fd)
{
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(new_str + i++) = *(s2 + j);
	return (new_str);
}

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(ft_strjoin(s, "\n"), fd);
}

void	ft_error_msg(char *message)
{
	if (message)
	{
		ft_putstr_fd("Err: ", 2);
		ft_putendl_fd(message, 2);
	}
}

char	*ft_get_file_buf(char *av)
{
	int	fd;
	int ret;
	char *buf;

	buf = (char *)malloc(sizeof(char) * 10000);
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_error_msg("open() failed\n");
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		ft_error_msg("read() failed\n");
		return (0);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		ft_error_msg("close() failed\n");
		return (0);
	}
	return (buf);
}

int		main(int ac, char **av)
{
	char *ret;

	if (ac != 2)
	{
		ft_error_msg("Usage: ./fillit input_file\n");
		return (-1);
	}
	ret = ft_get_file_buf(av[1]);
	ft_putstr(ret);
	return (0);
}
