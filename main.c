#include "mlx/mlx.h"

int main(void)
{
    void    *mlx;
    // void    *window1;
    void    *img;

    mlx = mlx_init();
    // window1 = mlx_new_window(mlx, 1920, 1080, "Test");
    // mlx_loop(mlx);
    img = mlx_new_image(mlx, 1920, 1080);
    return (0);
}