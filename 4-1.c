#include <stdio.h>

//4.x
int main()
{
//4.1
	{
		char c[] = "hellocoder";
		char *p = c;
		for (; *p !=0; p++) {
			printf("%c ", *p);
		}
		printf("\n");
	}

	{
		char c[] = {'a', 'b', 'c'}; 
		char *p = c;
		while (*p) {
			printf("%c ", *p);
			p++;
		}
		printf("\n");
	}

	{
		char *c = "world is coder";
		while (*c) {
			printf("%c ", *c);
			c++;
		}
		printf("\n");
	}

	return 0;
}
