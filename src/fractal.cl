__kernel void fractal(__global int* tab)
{
	int gid = get_global_id(0);
	int	x;
	int y;
	int	n;
	double z_re, z_im, zp_re, zp_im, z0_re, z0_im, tmp, c;

	if (gid > tab[0])
	{
		x = (gid - tab[0] - 1) % tab[1] + tab[7];
		y = (gid - tab[0] - 1) / tab[1] + tab[8];
		z_re = -0.5 + tab[5] / 100.0 + 2.0 * (0.5 - (tab[5]) / 100.0) * x / tab[1];
		z_im = -0.5 + tab[5] / 100.0 + 2.0 * (0.5 - (tab[5]) / 100.0) * y / tab[2];
		zp_re = z_re;
		zp_im = z_im;
		z0_im = 1.0 * sin(z_re);
		z0_re = 1.0 * sin(z_im);
		n = 0;
		c = z_im * z_re * z_re - z_re * z_im * z_im;
		while (n < 255 && (z_re * z_re + z_im * z_im) < 4)
		{
			z_re = z_re + c + z0_re;
			z_im = z_im + z0_im;
			n++;
		}
		tab[gid] = n;
	}
}