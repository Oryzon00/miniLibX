#include "fdf.h"

// void    print_triangle(int x, t_image_data *img)
// {
//     int i;

//     i = 0;
//     while (i < x)
//     {
//         my_mlx_pixel_put(img, 900 - i / 2, 500 + i / 2, 0x00FF0000);
//         my_mlx_pixel_put(img, 900 + i / 2, 500 + i / 2, 0x00FF0000);
//         my_mlx_pixel_put(img, 900 - x / 2 + i, 500 + x / 2, 0x00FF0000);
//         i++;
//     }

// }

// void    print_square_texture(int x, t_image_data *img)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while (j < x)
//     {
//         while (i < x)
//         {
//             my_mlx_pixel_put(img, 900 + i, 500 + j, 0x00FF0000);
//             i += 2;
//         }
//         j += 6;
//         i = 0;
//     }
// }

void	print_pink_floyd(int x, t_all *all)
{
	double	i;
	int		j;
	double	ratio;
	t_color couleur1;
	int		f;

	
	j = 0;
	while (j < x)
	{
		couleur1.trgb = 0x003030FF;
		i = 1;
		f = 0;
		while (i < j)
		{
			ratio = (i / j);
			couleur1.inside.b = 255 + ratio * (30 - 255);
			couleur1.inside.r = 30 + ratio * (255 - 30);
			if (f == 0)
			{
				couleur1.inside.g++;
				if (couleur1.inside.g == 255)
					f = 1;
			}
			else
			{
				couleur1.inside.g--;
				if (couleur1.inside.g == 30)
					f = 0;
			}
			my_mlx_pixel_put(all, 800 + i, 400, couleur1.trgb);
			my_mlx_pixel_put(all, 800 + j - i, 400 + j, couleur1.trgb);
			my_mlx_pixel_put(all, 800, 400 + i, couleur1.trgb);
			my_mlx_pixel_put(all, 800 + j, 400 + j - i, couleur1.trgb);
			i++;
		}
		j += 1;
	}
}

// void	print_colors(int x, t_image_data *img)
// {
// 	double	i;
// 	double	ratio;
// 	t_color couleur1;

// 	i = 1;
// 	couleur1.trgb = 0x003030FF;
// 	while (i < x)
// 	{
// 		ratio = (i / x);
// 		couleur1.inside.b = 255 + ratio * (30 - 255);
// 		couleur1.inside.r = 30 + ratio * (255 - 30);
// 		my_mlx_pixel_put(img, 800 + i, 500, couleur1.trgb);
// 		i++;
// 	}
	
// }
