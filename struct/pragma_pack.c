#include <stdio.h>

/*将结构体中的元素压栈，并制定对齐的字节为1个字节，注意n只能是1.2.4.8...*/
#pragma pack (push,1)

typedef struct
{
	char		a;
	int			b;
	char		c;
}test_one_t;

/*将结构体中的元素从栈中弹出，即只指定了push、pop语句间结构体的对齐，其他的没有指定*/
#pragma pack (pop)

typedef struct
{
	char		a;
	int			b;
	int			c;
}test_two_t;
//#pragma pack (pop)

int main()
{
	test_one_t				test1;
	test_two_t				test2;

	printf("struct test1 sizeof is:%d\n",sizeof(test1));
	printf("struct test2 sizeof is:%d\n",sizeof(test2));
	return 0;
}

/*结果分析：
 *		如果只运行第一个pragma 输出结果是6和12。因为只指定了第一个结构体对齐
 *		果只运行第二个pragma 输出结果是6和9。因为两个结构体都被包含在对齐语句中
 **/


#if 0
int main()
{
	test_one_t				test1;
	test_two_t				test2;

	printf("struct test1 sizeof is:%d\n",sizeof(test1));
	printf("struct test2 sizeof is:%d\n",sizeof(test2));
	return 0;
}
#endif
