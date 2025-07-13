#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 0;

	printf("i = %d\n", i);
	printf("i = %d\n", i++);
	printf("i = %d\n", i);
	
	printf("\n");

	i = 0;
	printf("i = %d\n", i);
	printf("i = %d\n", ++i);
	printf("i = %d\n", i);


	return 0;
}
