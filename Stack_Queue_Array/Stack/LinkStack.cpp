/************************************************
*************************************************/
#include <iostream>
using namespace std;

/************************************************
* 链栈
* 假设是有链表头节点的
*************************************************/
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}* LinkStack, LinkNode;

bool InitLinkStack(LinkStack& head) {
	head = (LinkNode*)malloc(sizeof(LinkNode));
	if (head == NULL) {
		return false;
	}
	return true;
}

bool Push(LinkStack& S, int x) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = x;
	p->next = S->next;
	S->next = p;
	return true;
}

bool Pop(LinkStack& S, int& x) {
	LinkNode* p = S->next;
	x = p->data;
	S->next = p->next;
	free(q);
	return true;
}

int GetTop(LinkStack S) {
	if (S->next == NULL) {
		return -1;
	}
	return S->next->data;
}