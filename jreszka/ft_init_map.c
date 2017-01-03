char **ft_init_map(t_map map)
{
	int height;
	int width;
	
	map.content = (char**)malloc(sizeof(char*) * (map.size + 1));
	height = -1;
	while (++height < map.size)
	{
		map.content[height] = (char*)malloc(sizeof(char) * (map.size + 1));
		width = -1;
		while (++width < map.size)
		{
			map.content[height][width] = '.';
		}
		map.content[height][width] = '\0';
	}
	map.content[height] = 0;
	return (map);
}