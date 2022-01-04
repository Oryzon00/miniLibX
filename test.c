#include <stdio.h>

struct inside
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char t;
};

typedef union u_color
{
    int trgb;
    struct inside inside;
}    t_color;

int main(void)
{
	t_color couleur1;

	couleur1.trgb = 0x00FFFFFF;
	printf("%x\n", couleur1.trgb);
	printf("%d\n",couleur1.trgb);
}
