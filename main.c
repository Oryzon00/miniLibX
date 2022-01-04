#include "mlx/mlx.h"
#include <stdio.h>

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

struct trgb_char
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char t;
};

typedef union u_color
{
    int					trgb;
    struct trgb_char	inside;
}    t_color;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
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
            i += 2;
        }
        j += 6;
        i = 0;
    }
}

void	print_square(int x, t_data *img)
{
	int	i;

	i = 0;
	while (i < x)
	{
		my_mlx_pixel_put(img, 800 + i, 500, 0x0000FFFF);
		my_mlx_pixel_put(img, 800 + i, 500 + x, 0x0000FFFF);
		my_mlx_pixel_put(img, 800, 500 + i, 0x0000FFFF);
		my_mlx_pixel_put(img, 800 + x, 500 + i, 0x0000FFFF);
		i++;
	}
}

void	print_colors(int x, t_data *img)
{
	int		i;
	int		j;
	t_color couleur1;

	i = 1;
	j = 1;
	//couleur de depart: bleu: 0x003030FF;
	couleur1.trgb = 0x003030FF;
	//couleur d'arrive: rouge.0x00FF3030
	// difference entre les deux.
	while (i < x)
	{
		//incrementer tous de 1% la couleur tous les 1% de x
		if (i > (x * j / 100))
		{
			couleur1.trgb += j * (0x00FF3030 - 0x003030FF) / 100;
			j++;
		}
		my_mlx_pixel_put(img, 800 + i, 500, couleur1.trgb);
		i++;
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
	
	print_colors(500, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
