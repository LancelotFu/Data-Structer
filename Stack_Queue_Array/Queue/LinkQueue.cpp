/************************************************
*************************************************/
#include<iostream>
using namespace std;

/************************************************
* 实现链式队列
*************************************************/
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
};
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}

/************************************************
* 带头节点的链表队列插入新的节点
* 首先将新插入的数据构造成为节点
* 因为新节点会是队列的最后一个值，所以新节点要指向NULL
* 然后由于尾指针指向的是原来链表队列的最后一个值
* 所以此时要将表尾指针指向新节点
* 最后表尾指针往后移动一位，即指向新节点s
*************************************************/
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

/************************************************
* 带头结点的链表出队
* 首先先要判断链表队列是否为空
* 然后由于队头指向的是表头指针，于是队列的第一个元素应该是队头指针指向的next
* 然后获取队列第一个元素之后用链表删除的方法就可以了
*************************************************/
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;
	}
	free(p);
	return true;
}

