int ft_error(char *s)
{
	{
		write(2, s, ft_strlen(s));
		write(2, '\n', 1);
		return (0);
	}
}