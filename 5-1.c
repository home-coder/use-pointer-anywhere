#include <stdio.h>

int main()
{
	char *s[] = {"hellods", "home-coder", "linux gnu c", NULL};

//5.1 遍历字符串数组，里面全是指针	
	{
		char **p = s;
		for (; *p != NULL; p++) {
			printf("%s ", *p);
		}
		printf("\n");
	}

//5.2 遍历第二数组元素，是一个个字符串，直接指向数组中第二个元素的首元素地址
	{
		char *p = s[1];
		for (; *p != '\0'; p++) {
			printf("%c", *p);
		}
		printf("\n");
	}

//5.3 遍历第二个数组元素，是一个字符串，使用二维指针指向字符串的地址
	{
		char **p = &s[1];
	}

	return 0;
}
