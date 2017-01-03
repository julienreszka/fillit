#include "libft.h"
#include "fillit.h"

char *get_buf(char *file_name)
{
	char		*buf;
	int			ret;
	int			fd;

	buf = (char *)malloc(sizeof(char) * 10000);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		write(2, "error\n", 6);		
		return (0);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	return(buf);
}