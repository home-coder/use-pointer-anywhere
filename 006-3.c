#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef void (*print_arry)(const char *arry, const int len);
typedef int(arryp)[10];
int main()
{
	//1.p-->int
	int i = 4;
	int *pi = &i;
	printf("*pi =%d\n", *pi);

	//2.p-->char
	char c = 'a';
	char *pc = &c;
	printf("*pc =%c\n", *pc);

	//3.1 p-->int[]
	int arri[10] = {1, 2, 3};
#if 0	
	int *parri = arri;
	int ix = 0;
	for (; ix < sizeof(arri)/sizeof(arri[0]); ix++) {
		printf("*parri[%d] =%d\n", ix, *(parri + ix));
	}
#endif	
	//3.2 p-->int[]
	int (*parri)[] = &arri;
	#define SIZE(x) (sizeof(x)/sizeof(*x))
	int ix = 0;
	arryp *p = &arri; 
	for (; ix < 3; ix++) {
		(*p)[i] = 3 - i;
	}	
	printf("%d\n", (*p)[2]);
	//4.1 p-->char[]
	char arrc[] = {'a', 'b', 'c'};
	char *parrc = arrc;
	int cx = 0;
	for (; cx < sizeof(arrc)/sizeof(arrc[0]); cx++) {
		printf("*parrc[%d] =%c\n", cx, *(parrc + cx));
	}

	//4.2 p-->char[]

	//4.3 p-->"abc"
	char *pabc = "abcdefg";
	printf("%s\n", pabc + 2);

	//5.

	return 0;
}
