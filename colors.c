/*
0xTTRRGGBB
T-> Transparency
R -> Red
G -> Green
B -> Blue
Ex: 0x00FF0000
F = 16
FF = 256
Exemple couleur rouge:
TRGB: T=0 R=256 G=0 B=0
Hexa:   0x00FF0000
Binaire :  00000000 11111111 00000000 00000000

*/

// use bitshifting to set up colors in code
// bit -> 0 or 1
// 8 bits = 1 byte

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
	// 0x
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
