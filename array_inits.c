
void	init_map(int map[3][100])
{
	int	r;
	int	c;

	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 100)
		{
			map[r][c] = 0;
			c++;
		}
		r++;
	}
}

void	init_grid(int map[10][10])
{
	int	r;
	int	c;

	r = 0;
	while (r < 10)
	{
		c = 0;
		while (c < 10)
		{
			map[r][c] = 0;
			c++;
		}
		r++;
	}
}
