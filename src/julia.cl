__kernel void julia(__global int* tab)
{
	int gid = get_global_id(0);
	int	x;
	int y;
	int	n;
	double z_re, z_im, z0_re, z0_im, tmp;

	if (gid > tab[0])
	{
		x = (gid - tab[0] - 1) % tab[1] + tab[7];
		y = (gid - tab[0] - 1) / tab[1] + tab[8];
		z_re = -2.0 + tab[5] / 100.0 + 2.0 * (2.0 - (tab[5]) / 100.0) * x / tab[1];
		z_im = -2.0 + tab[5] / 100.0 + 2.0 * (2.0 - (tab[5]) / 100.0) * y / tab[2];
		z0_im = 1.0 * tab[3] / tab[1];
		z0_re = 1.0 * tab[4] / tab[2];
		n = 0;
		while (n < 250 && (z_re * z_re + z_im * z_im) < 4)
		{
			tmp = z_re * z_re - z_im * z_im;
			z_im = z_re * z_im + z_im * z_re;
			z_re = tmp;
			z_re += z0_re;
			z_im += z0_im;
			n++;
		}
		tab[gid] = n;
	}
}