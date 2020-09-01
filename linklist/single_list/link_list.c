#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OK		 1
#define	ERROR	-1
typedef struct header
{
	int								data;
	struct header					*next;
}node,*list_node;

void link_list_create_header_insert(list_node *gg,int n);
//list_node link_list_create_header_insert(int n);
void link_list_create_tail_insert(list_node *gg,int n);
void link_list_print(list_node header);
int link_list_delete(list_node header,int i);
int link_list_insert(list_node header,int i);
int link_list_find(list_node header,int node_value);

int main()
{
	list_node				 header=NULL;

	list_node				 node=NULL;
	list_node                p=NULL;
	int						 i=0;
	int						 rt=0;

	/*by return value to get header address*/
	//header=link_list_create_header_insert(5);

	/*by pointer to get header address */
	//link_list_create_header_insert(&header,5);

	/*by tail insert method create link list*/
	link_list_create_tail_insert(&header,5);
	/*由头结点开始顺序打印 */
	printf("start print data...\n");
	link_list_print(header);
	
	/*delete node i*/
	rt=link_list_delete(header,2);
	if(rt<0)
		printf("delete failure!\n");
	else
		printf("success delete node i!\n");
	/*由头结点开始顺序打印 */
	printf("start print data...\n");
	link_list_print(header);

	/*before node i insert newNode */
	rt=link_list_insert(header,2);
	if(rt<0)
		printf("insert newNode failure!\n");
	else
		printf("insert newNode OK!\n");
	/*由头结点开始顺序打印 */
	printf("start print data...\n");
	link_list_print(header);

	rt=link_list_find(header,3);
	if(rt<0)	
		printf("find node failure!\n");
	else
		printf("success find node_value !\n");
	
	return 0;
}

#if 1
/*通过指针操作来实现头结点地址的获取 */
void link_list_create_header_insert(list_node *gg,int n)
{
	int								data=0;
	int								i=0;	
	list_node						newNode=NULL;
	list_node						header=NULL;

	/*创建头结点*/
	header=(list_node)malloc(sizeof(node));
	header->next=NULL;

	*gg=header;

	/*头插法依次插入元素*/
	for(i;i<n;i++)
	{
		newNode=(list_node)malloc(sizeof(node));
		printf("Please input data:\n");
		scanf("%d",&data);
		newNode->data=data;
		newNode->next=NULL;

		newNode->next=header->next;
		header->next=newNode;
	}
}
#endif


#if 0

/*通过返回值来获得指针的地址*/
list_node link_list_create_header_insert(int n)
{
	int							data=0;
	int							i=0;	
	list_node 					newNode=NULL;
	list_node 					Node=NULL;
	list_node 					header=NULL;

	/*创建头结点*/
	header=(list_node)malloc(sizeof(node));
	header->next=NULL;

	printf("in function header addr is:%p\n",header);

	/*头插法依次插入元素*/
	for(i;i<n;i++)
	{
		newNode=(list_node)malloc(sizeof(node));
		printf("Please input data:\n");
		scanf("%d",&data);
		newNode->data=data;
		newNode->next=NULL;

		newNode->next=header->next;
		header->next=newNode;
	}

	return header;
}
#endif


#if 1
/*尾插法创建链表 */
void link_list_create_tail_insert(list_node *gg,int n)
{
	list_node				newNode=NULL;
	list_node				header=NULL;
	list_node				tail=NULL;
	int						i=0;
	int						data=0;

	header=(list_node)malloc(sizeof(node));
	header->next=NULL;
	tail=header;
	*gg=header;

	for(i;i<n;i++)
	{
		newNode=(list_node)malloc(sizeof(node));
		newNode->next=NULL;
		printf("Please input data:\n");
		scanf("%d",&data);
		newNode->data=data;

		tail->next=newNode;
		tail=tail->next;
	}
}
#endif

/*由头节点开始顺序打印链表内容 */
void link_list_print(list_node header)
{
	if(header==NULL)
		printf("link list in NULL!\n");
	while(header->next)
	{
		header=header->next;
		printf("header data is:%d\n",header->data);
	}
}

/*删除节点i */
int link_list_delete(list_node header,int i)
{
	int						j=0;
	list_node				p=NULL;
	list_node				pointer_i=NULL;

	p=header;
	/*find node i-1:delete node i must find node i-1*/
	while(p->next && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p->next || j>i-1)
		return ERROR;

	/*delete node i*/
	pointer_i=p->next;
	printf("will delete pointer i value is:%d\n",pointer_i->data);
	p->next=pointer_i->next;
	free(pointer_i);
	pointer_i=NULL;
	return OK;
}

int link_list_insert(list_node header,int i)
{
	list_node			p=NULL;
	list_node			newNode=NULL;
	int					j=0;
	int					node_value=0;

	p=header;
	
	/*in link list find insert position*/
	while(p->next && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p->next || j>i-1)
		return ERROR;
	
	/*before node i insert newNode*/
	newNode=(list_node)malloc(sizeof(node));
	newNode->next=NULL;
	printf("Please input newNode's value:\n");
	scanf("%d",&node_value);
	newNode->data=node_value;
	newNode->next=p->next;
	p->next=newNode;

	return OK;
}

int link_list_find(list_node header,int node_value)
{
	list_node			p=NULL;
	int					node_number=0;
	
	p=header->next;
	node_number++;

	while(p && p->data!=node_value)
	{
		p=p->next;
		++node_number;
	}
	if(p->data==node_value)
	{
		printf("destination node is node %d!\n",node_number);
		return OK;
	}
	else
		return ERROR;
}
