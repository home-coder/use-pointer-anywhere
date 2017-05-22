#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef void (*print_arry)(const char *arry, const int len);
typedef int(arryp)[3];
int main()
{
	//1.p-->int
	{
		int i = 4;
		int *pi = &i;
		printf("*pi =%d\n", *pi);
	}
	//2.p-->char
	{
		char c = 'a';
		char *pc = &c;
		printf("*pc =%c\n", *pc);
	}
	//3.1 p-->int[]
	{
		int arri[10] = {1, 2, 3};//后面的数据默认初始化为 0
		int *parri = arri;
		int ix = 0;
		for (; ix < sizeof(arri)/sizeof(arri[0]); ix++) {
			printf("*parri[%d] =%d\n", ix, *(parri + ix));
		}
	}
	//3.2 p-->int[]
	{
		int arri[10] = {1, 2, 3};
		int (*parri)[] = &arri;
#define SIZE(x) (sizeof(x)/sizeof(*x))
		int ix = 0;
		for (; ix < 3; ix++) {
			printf("一维数组，还用二维的数组指针，这种方式太多余\n");		
		}
	}
	//3.3 p-->int[][x] 
	//二维数组，哪一个维度是可以省略的呢, 为什么?
	{
		int arri[][3] = {{1, 3, 4}, {9, 8, 3}, {9, 0, 9}};
		arryp *p = arri; //首元素：是一个一维数组{1, 3, 4}	
		int i, j;
		printf("er wei %d\n", (int)sizeof(arri));
		for (i = 0; i < sizeof(arri)/(sizeof(int)*3); i++) {
			for (j = 0; j < 3; j++) {
				printf("%d ", *(*(p + i) + j));	
			}
		}
		printf("\n");
	//重点来了，二维数组指针的用途，比如说我现在仅仅想用这个二维数组的第二行数组，用作输出也好，用作某一个函数的参数也好
		for (j = 0; j < 3; j++) {
			printf("%d ", *(*(p + 1) + j));
		}
		printf("\n");
	}
	//3.4 p-->int[][x]中的元素
	{
		int arri[][3] = {{1, 3, 4}, {9, 8, 3}, {9, 0, 9}};
		int *p = arri[0];//或者&arri[0][0]; 但是不能int *p = arri;
		/*如果知道了编译原理，其实这和一维数组的方式如出一辙，即arri[0]单独使用在sizeof,&等情况
		* 是代表着整个的数组{1, 3, 4}， 但是这里表示这个数组{1,3,4}的首元素的地址
		* 可以对比 3.1   3.1  3.1  3.1
		*/
		int i, j;
		for (i = 0; i < sizeof(arri)/sizeof(arri[0][0]); i++) {
				printf("%d ", *(p + i));
		}
		printf("\n");
	}
	//4.1 p-->char[] ；数组大小 3， 无尾零
	{
		char arrc[] = {'a', 'b', 'c'};
		char *parrc = arrc;
		int cx = 0;
		for (; cx < sizeof(arrc)/sizeof(arrc[0]); cx++) {
			printf("*parrc[%d] =%c ", cx, *(parrc + cx));
		}
		printf("\n");
	}
	//4.2 p-->char[] ; 数组大小是6 + 1，尾零
	{
		char arrc[] = "abcdes";
		printf("%d \n", (int)sizeof(arrc));
		char *p = arrc;
		for (; *p != 0; p++) {
			printf("%c ", *p);
		}
		printf("\n");
	}

	//4.3 p-->"abc"
	{
		char *pabc = "abcdefg";
		char *p = pabc;
		for (; *p != 0; p++) {
			printf("%c ", *p);
		}
		printf("\n");
	}

	//5.1 p-->{"hello", "china", "home coder"}; //本质是一维的数组, 3.4是二维的数组
	{
		char *str[] = {"hello", "fdjlsa", "oneface"};
		char **p = str;
		int i;
		for (i = 0; i < sizeof(str)/sizeof(str[0]); i++) {
			printf("%s ", *(p + i));
		}
		printf("\n");
	}	
	//5.2 p-->{"hello", "china", "home coder", NULL}. 优化表示字符串数组
	{
		char *str[] = {"hello", "fdjlsa", "oneface", NULL};
		char **pstr = str;

		for (; *pstr != NULL; pstr++) {
			printf("%s ", *pstr);
		}
		printf("\n");
	}
	
	return 0;
}
