/************************************************
*************************************************/
#include <iostream>
using namespace std;

/************************************************
* 循环双向链表
*************************************************/
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinklist;

/************************************************
* 循环双向链表的初始化，要将头节点的前驱和后继都设为头节点
*************************************************/
bool InitDLinkList(DLinklist& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->prior = L;
	L->next = L;
	return true;
}

/************************************************
* 由于循环节点next指针最后指向头节点
* 因此在判断是否为空的时候就要判断头节点的next是否为头节点
*************************************************/
bool Empty(DLinklist L) {
	if (L->next == L) {
		return true;
	}
	return false;
}

/************************************************
* 判断p节点是否为尾节点，只需要判断p的next指针是否指向头节点就可以了
*************************************************/
bool isTail(DLinklist L, DNode* p) {
	if (p->next == L) {
		return true;
	}
	return false;
}

/************************************************
* 在p后面插入s
* 插入过程与双向链表相似，也是需要设置好前驱和后继即可
*************************************************/
bool InsertNextDNode(DNode* p, DNode* s) {
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

/************************************************
* 删除p后边的q
* 也是将节点的前驱和后继设置好
*************************************************/
bool DeleteNextDNode(DNode* p, DNode* q) {
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true;
}