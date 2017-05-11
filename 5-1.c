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

//5.2 遍历第二个数组，直接指向第二个数组的首元素地址
	{
		char *p = s[1];
		for (; *p != '\0'; p++) {
			printf("%c", *p);
		}
		printf("\n");
	}

//5.3 遍历第二个数组，使用数组指针指向第二个数组的行地址
	{
	
	}

	return 0;
}
