/****************************************************************
*	Author       : guhaiming 
*	Last modified: 2020-04-03 23:17
*	Email        : 2427779305@qq.com
*	blog         : https://blog.csdn.net/go_home_look
*	Filename     : circular_link_list.c
*	Description  : 循环单链表可以运用在下面的场景，就是在最后一个元素的后面插入一个元素，在最前面一个元素删除一个元素，这种场景的功能有点像队列的功能吧 ！
*	通过这次编写发现自己的问题：发现每次都是不知道怎么处理创建节点后p的移动
****************************************************************/
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
	int						data;
	struct	node			*next;
};

struct node* node_create(int init_data,int node_number);
void node_print(int node_number,struct node *pointer);
void node_insert(struct node* index);
int main()
{
	struct node				*head,*tail;
	struct node				*p;
	int						init_data;
	int						node_number;
	int						node_id;
	head=NULL;

	head=node_create(1,10);
	p=head;
	printf("头节点指向第一个节点成功，请输入要创建的其他节点个数：\n");
	scanf("%d",&node_number);
	//这里节点创建之后我们选择的是尾插的方式加入到循环链表中,当然你也可以前插 
	for(node_id=2;node_id<node_number+2;node_id++)
	{
		scanf("%d",&init_data);
		tail=node_create(node_id,init_data);
		p->next=tail;
		p=p->next;
		tail->next=head;
	}
	node_insert(head);
	
	//打印一下刚刚加入的链表信息
	for(int i=1;i<=node_number+1;i++)
	node_print(i,head);//由head开始顺序打印
}

struct node* node_create(int node_id,int init_data)
{
	struct node				crt_node;
	struct node*			crt_node_pointer;
	
	crt_node_pointer=(struct node*)malloc(sizeof(crt_node));
	crt_node_pointer->data=init_data;
	printf("创建了第%d个节点！\n",node_id);

	return crt_node_pointer;
}
void node_insert(struct node* index)
{
	int				insert_node_id=0;
	struct node		pointer;
	struct node		*new_pointer;
	int				ist=0;
	int				data=0;

	printf("请输入要插入节点的位置：\n");
	scanf("%d",&insert_node_id);
	for(int i=1;i<insert_node_id;i++)//找到插入位置
	index=index->next;
	
	printf("请输入插入节点存储的值：\n");
	scanf("%d",data);
	new_pointer=node_create(insert_node_id+1,data);
	
	new_pointer->next=index->next;
	index->next=new_pointer;
	
	ist=insert_node_id+1;
	printf("在节点%d后面插入了一个元素！\n",ist);
}

void node_delete(struct node* index)
{
	int					delete_node_id;
	struct node			*front_pointer;

	printf("请输入要删除节点的位置：\n");
	scanf("%d",&delete_node_id);
	for(int i=1;i<delete_node_id-1;i++)//找到删除位置
	index=index->next;
	front_pointer=index;
	front_pointer=index->next->next;
	printf("删除了节点%d\n",delete_node_id);
}

//打印一个节点在链表中的位置信息和内容,先将指针移动到目标位置再打印目标位置的值
void node_print(int node_id,struct node *pointer)
{
	for(int i=1;i<node_id;i++)
	pointer=pointer->next;//从这里我知道了链表地址不连续指针执行自加操作是不能实现跳转的
	printf("第%d个节点的内容是：%d\n",node_id,pointer->data);
}

