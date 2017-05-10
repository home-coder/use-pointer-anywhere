#include <stdio.h>

typedef int (*parri)[3];

static void print_second(parri p, int num)
{
	int i;
	for (i = 0; i < num; i++) {
		printf("%d ", *(*p + i));
	}
	printf("\n");
}

int main()
{
	int arri[][3] = {{4, 3, 6}, {4, 3, 2}, {9, 4, 0}};
	int *p = arri[0];
	int i, j;

	for (i = 0; i < sizeof(arri)/sizeof(arri[0][0]); i++) {
		printf("%d ", *(p + i));
	}
	printf("\n");

//2.parri	
	parri pa = arri;
	for (i = 0; i < sizeof(arri)/(sizeof(arri[0][0])*3); i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", *(*(pa + i) + j));
		}
	}
	printf("\n");

//3.func :print second arri data
	print_second(pa + 1, 3);	

	return 0;
}