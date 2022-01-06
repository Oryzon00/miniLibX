#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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

void	print_pink_floyd(int x, t_data *img)
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
			my_mlx_pixel_put(img, 800 + i, 500, couleur1.trgb);
			my_mlx_pixel_put(img, 800 + j - i, 500 + j, couleur1.trgb);
			my_mlx_pixel_put(img, 800, 500 + i, couleur1.trgb);
			my_mlx_pixel_put(img, 800 + j, 500 + j - i, couleur1.trgb);
			i++;
		}
		j += 1;
	}
}

void	print_colors(int x, t_data *img)
{
	double	i;
	double	ratio;
	t_color couleur1;

	i = 1;
	couleur1.trgb = 0x003030FF;
	while (i < x)
	{
		ratio = (i / x);
		couleur1.inside.b = 255 + ratio * (30 - 255);
		couleur1.inside.r = 30 + ratio * (255 - 30);
		my_mlx_pixel_put(img, 800 + i, 500, couleur1.trgb);
		i++;
	}
	
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	ouverture(t_vars *vars)
{
	printf("Bonjour\n");
}
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close(vars);
	printf("keycode: %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	return (0);
}


int	main(void)
{
	t_vars	vars;
	t_data	img;
	char	*str= "Allo\nJ'ecris\nsur\nplsuieurs\nlignes";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "My window");

	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	
	mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_expose_hook(vars.win, ouverture, &vars);

	print_pink_floyd(500, &img);

	mlx_string_put(vars.mlx, vars.win, 200, 200, 0x00FFFFFF, str);
	mlx_loop(vars.mlx);
}
