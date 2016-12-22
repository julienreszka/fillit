char **ft_init_map(int size)
{
	map = (char**)malloc(sizeof(char*) * (size + 1));
	int height;
	height = 0;
	int width;
	while(height < size)
	{
		map[height] = (char*)malloc(sizeof(char) * (size + 1));
		width = 0;
		while (width < size)
		{
			map[height][width] = '.';
			width++;
		}
		map[height][width] = '\0';
		height++;
	}
	map[height] = 0;
	return (map);
}