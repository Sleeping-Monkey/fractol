__kernel void mandel(__global int* tab)
{
	int gid = get_global_id(0);
	int	x;
	int y;
	int	n;
	double z_re, z_im, z0_re, z0_im, tmp;

	if (gid > tab[0])
	{
		x = (gid - tab[0] - 1) % tab[1] + tab[3];
		y = (gid - tab[0] - 1) / tab[1] + tab[4];
		z_re = -1.7433419053321 - 0.00000000374 + x * 0.00000000374 * 2.0 / tab[1];
		z_im = 0.0000907687489 - 0.00000000374 + y * 0.00000000374 * 2.0 / tab[2];
		z0_im = z_im;
		z0_re = z_re;
		n = 0;
		while (n < 255 && (z_re * z_re + z_im * z_im) < 4)
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
