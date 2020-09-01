#include<stdio.h>

int main()
{
	int				a=0;
	int				b=0;
	int				*pa=NULL;
	int				*pb=NULL;
	int				temp=0;
	
	char			*pc="helloWorld!";
	char			*pd=NULL;

	pa=&a;
	pb=&b;
	temp=pb-pa;
	printf("temp is:%d\n",temp);

	/*打印占用内存字节的个数 :利用地址来计算个数这点我觉得很	     * 有创意，还有就是指针的加减就是地址的加减，这点我也很欣赏 
	 * */
	pd=pc;
	while(*pd++)
	{
		printf("substract value is:%d\n",pd-pc);
	}
	return 0;
}
