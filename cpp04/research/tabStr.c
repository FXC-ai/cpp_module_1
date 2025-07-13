#include <stdio.h>

int main()
{
	char *C_tab[10];

	C_tab[0] = "chaine 0";
	C_tab[1] = "chaine 1";

	printf("0 : %p : %s\n", C_tab[0], C_tab[0]);
	printf("1 : %p : %s\n", C_tab[1], C_tab[1]);

	return 0;
}