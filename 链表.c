#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct NODE * pNext;
}NODE,*PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
void sort_list(PNODE);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);



int main(void)
{
   PNODE pHead=NULL;
   pHead=create_list();
   traverse_list(pHead);
   sort_list(pHead);
 
   return 0;
}
PNODE create_list(void)
{
    int len;
    int i;
    int val;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));
    if(pHead==NULL)
    {
        printf("分配失败,程序终止!\n");
        exit(-1);
    }
    PNODE pTail=pHead;
    pTail->next=NULL;//有可能只有一个节点
    printf("请输入需要生成的链表节点的个数:len=");
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        printf("请输入第%d个节点的:",i+1)
        scanf("%d",&val);
        PNODE pNew=(PNODE)malloc(sizeof(NODE));
        if(pNew==NULL)
    {
        printf("分配失败,程序终止!\n");
        exit(-1);
    }
    pNew->data=val;
    pTail->next=pNew;
    pNew->next=NULL;
    pTail=pNew;
    }
    
    return pHead;
}
void traverse_list(PNODE pHead)
{
    PNODE p=pHead->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
void sort_list(PNODE pHead)
{
    int i,j,t;
    int len=length_list(pHead);
    PNODE p,q;
    for(i=0,p=p->next;i<len-1;i++,p=p->next)
    {
        for(j=i+1,q=p->next;j<len;j++,q=q->next)
        {
            if(p->data>q->data)
            {
                t=p->data;
                q->data=p->data;
                q->data=t;
            }
        }
    }
    return;
}
bool is_empty(PNODE pHead)
{
    if(pHead->next==NULL)
    return true;
    else
    return false;
}
int length_list(PNODE pHead)
{
    PNODE p=pHead->next;
    int len=0;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
}
bool insert_list(PNODE pHead,int pos,int val)
{
    int i=0;
    PNODE p=pHead;
    while(p!=NULL&&i<pos-1)
    {
        p=p->next;
        i++;
    }
    if(i>pos-1||p=NULL)
    return false;
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
    if(pNew==NULL)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }
    pNew->data=val;
    PNODE q=p->next;
    p->next=pNew;
    pNew->next=q;
    return true;
}
/*在pHead所指向链表的第pos个节点的前面插入一个新节点,该节点的值是val,pos从1开始*/
bool delete_list(PNODE pHead,int pos,int *pVal)
{
    int i=0;
    PNODE p=pHead;
    while(p->next!=NULL&&i<pos-1)
    {
        p=p->next;
        i++;
    }
    if(i>pos-1||p->next=NULL)
    return false;
    PNODE q=p->next;
    *pVal=q->data;
    p->next=p->next->next;
    free(q);
    q=NULL;
    return true;
}
