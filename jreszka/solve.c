t_map test(t_tetrimino tet, int min_square_space)
{
	t_map crt;
	crt.size = min_square_space;
	crt.m = ft_init_map(crt.size);
	t_i = -1;
	while(++t_i < tets_nb)
	{
		crt.p_i.x = 0;
		crt.p_i.y = 0;
		h_i = -1;
		while(++h_i < 4)
		{
			m_y = tet[t_i].hash[h_i].y - tet[t_i].ref_min.y + crt.p_i.y;
			m_x = tet[t_i].hash[h_i].x - tet[t_i].ref_min.x + crt.p_i.x
			if (crt.string[m_y][m_x] == '.')
				crt.string[m_y][m_x] = tet[t_i].lettre;
			else
			{
				
				if (crt.p_i.y < crt.size)
				{	
					if (crt.p_i.x < crt.size)
						crt.p_i.x++;
					else if (crt.p_i.x == crt.size)
					{
						crt.p_i.y++;
						crt.p_i.x = 0;
					}
					h_i = -1;
				}
			}
		}
	}
	return (crt);
}