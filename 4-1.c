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

	//error
	{
		char c[] = {'a', 'b', 'c', 'e'};
		char *p = c;
		while (*p) {
			printf("%c ", *p);
			p++;
		}
		printf("\n");
	}

	//right
	{
		char c[] = {'a', 'b', 'c', 'e'};
		char *p = c;
		int i;

		for (i = 0; i < sizeof(c)/sizeof(c[0]); i++) {
			printf("%c ", *(p + i));
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
