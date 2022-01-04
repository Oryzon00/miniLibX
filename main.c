#include "mlx/mlx.h"

// open, read, write, close
// ◦ malloc, free
// ◦ perror, strerror
// ◦ exit
// ◦ Toutes les fonctions de la lib math (-lm et man 3 math)
// ◦ Toutes les fonctions de la miniLibX.


typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    print_square(int x, t_data *img)
{
    int i;

    i = 0;
    while (i < x)
    {
        my_mlx_pixel_put(img, 900 + i, 500, 0x00FF0000);
        my_mlx_pixel_put(img, 900 + i, 500 + x, 0x00FF0000);
        my_mlx_pixel_put(img, 900, 500 + i, 0x00FF0000);
        my_mlx_pixel_put(img, 900 + x, 500 + i, 0x00FF0000);
        i++;
    }
}

void    print_triangle(int x, t_data *img)
{
    int i;

    i = 0;
    while (i < x)
    {
        my_mlx_pixel_put(img, 900 - i / 2, 500 + i / 2, 0x00FF0000);
        my_mlx_pixel_put(img, 900 + i / 2, 500 + i / 2, 0x00FF0000);
        my_mlx_pixel_put(img, 900 - x / 2 + i, 500 + x / 2, 0x00FF0000);
        i++;
    }

}

void    print_square_texture(int x, t_data *img)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < x)
    {
        while (i < x)
        {
            my_mlx_pixel_put(img, 900 + i, 500 + j, 0x00FF0000);
            i += 5;
        }
        j += 2;
        i = 0;
    }
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    print_square_texture(300, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

