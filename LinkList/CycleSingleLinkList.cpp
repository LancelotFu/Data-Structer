/************************************************
*************************************************/
#include<iostream>
using namespace std;

/************************************************
* 创建双向链表，每一个节点都有前驱和后继链
*************************************************/
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinklist;

/************************************************
* 初始化双向链表过程与链表相似
* 但是需要将前驱结点也置空
*************************************************/
bool InitDLinkList(DLinklist& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->prior = NULL;
	L->next = NULL;
	return true;
}

/************************************************
* 仍然是通过判断头节点后是否还有节点来判断是否为空
*************************************************/
bool Empty(DLinklist L) {
	if (L->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}

/************************************************
* 通过在p点后插入s节点
* 插入过程也要先将s指向p->next，不然会找不到p->next的
* 然后再将p->next->prior指向s
* 然后再将s->prior指向p
* 由于是双向链表，因此在插入时要注意前驱的赋值
*************************************************/
bool InsertNextDNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL) {
		return false;
	}
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}

/************************************************
* 删除p节点的后继节点
* 首先判断p是否为空
* 然后再判断q是否为空
* 然后再将p的后继指向q的后继（即绕过了q）
* 然后再将q后继的前驱设置为p
* 最后释放q
*************************************************/
bool DeleteNextDNode(DNode* p) {
	if (p == NULL) {
		return false;
	}
	DNode* q = p->next;
	if (q == NULL) {
		return false;
	}
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	}
	free(q);
	return true;
}

