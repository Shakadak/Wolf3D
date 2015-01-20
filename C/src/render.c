void	render(t_env const *const env)
{
	t_player	tmp;
	int			i;
	int			distance;
	int			height;

	tmp.coordinate = env->player.coordinate;
	tmp.fov = env->player.fov;
	tmp.direction = (2 * M_PI + env->player.direction - tmp.fov / 2) % (2 * M_PI);
	i = 0;
	while (i < W_WIDTH)
	{
		distance = raycast(tmp, env->map);
		distance = distance * cos(env->player.direction - tmp.direction);
		height = GRAIN / distance * (W_WIDTH / 2) / tan(tmp.fov / 2);
	}
}
