/****************************************************************
*	Author       : guhaiming 
*	Last modified: 2020-03-05 20:33
*	Email        : 2427779305@qq.com
*	blog         : https://blog.csdn.net/go_home_look
*	Filename     : ts.c
*	Description  : 这里要重新申明一下%p的用法，虽然说是用来打印地址的，但用printf来打印时一定得满足%p对应的是一个地址，而不是一个值，否则打印的是值而不是地址，只不过值前面加了个0x罢了 
****************************************************************/
#include<stdio.h>
int main()
{
	int		*p=0;//看看他们的地址分别是什么？
	int		*q;
	int		c=4;
	printf("p init adder is:%p\n",&p);//这个打印的才是自己的地址
	printf("p init value is:%p\n",p);//这个打印的是p指向的地址，不信我们再做一个给p赋值为NULL的测试,已经证实了
	printf("q init adder is:%p\n",&q);
	printf("q init value is:%p\n",q);
	
	p=&c;

	printf("&c adder is:%p\n",&c);
	printf("c  adder is:%p\n",c);

	printf("p equaled adder is:%p\n",&p);
	printf("p equaled value is:%p\n",p);//p和&(*p)打印的是同一个地址
	printf("*p  adder is:%p\n",&(*p));

	return 0;
}
