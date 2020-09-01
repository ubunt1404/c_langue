#include <stdio.h>
int main()
{
	int			a=4;
	int			b=3;
	if((a-b) && (b=b-5) || (a=b) )
	{
		printf("in if b is:%d\n",b);
		printf("in if befor --a a is:%d\n",a);
		--a;
		printf("in if a is:%d\n",a);
	}
	printf("out if a is:%d\n",a++);
	
	int			c=0;
	int			d=1;
	int			e=-7;
	if(c&&d)
	{
		printf("c&&d is ture!\n");
	}
	if(e&&d)
	{
		printf("e&&d is ture!\n");
	}
}
