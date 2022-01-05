/*
** Put a string in the window.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	int  x			the x location;
** @param	int  y			the y location;
** @param	int  color		the font color;
** @param	char *string	the text to write;
** @return	int				has no return value (bc).
*/
int		mlx_string_put(void *mlx_ptr, void *win_ptr, 
		int x, int y, int color, char *string);
