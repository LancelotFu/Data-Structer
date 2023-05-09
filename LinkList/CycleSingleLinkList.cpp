/************************************************
*************************************************/
#include<iostream>
using namespace std;

/************************************************
* ����˫������ÿһ���ڵ㶼��ǰ���ͺ����
*************************************************/
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinklist;

/************************************************
* ��ʼ��˫�������������������
* ������Ҫ��ǰ�����Ҳ�ÿ�
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
* ��Ȼ��ͨ���ж�ͷ�ڵ���Ƿ��нڵ����ж��Ƿ�Ϊ��
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
* ͨ����p������s�ڵ�
* �������ҲҪ�Ƚ�sָ��p->next����Ȼ���Ҳ���p->next��
* Ȼ���ٽ�p->next->priorָ��s
* Ȼ���ٽ�s->priorָ��p
* ������˫����������ڲ���ʱҪע��ǰ���ĸ�ֵ
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
* ɾ��p�ڵ�ĺ�̽ڵ�
* �����ж�p�Ƿ�Ϊ��
* Ȼ�����ж�q�Ƿ�Ϊ��
* Ȼ���ٽ�p�ĺ��ָ��q�ĺ�̣����ƹ���q��
* Ȼ���ٽ�q��̵�ǰ������Ϊp
* ����ͷ�q
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

