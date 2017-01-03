int ft_exit_error()
{
	write(2, "open() failed\n", 14);
	return (0);
}