/************************************************
*************************************************/
#include<iostream>
using namespace std;

/************************************************
* ʵ����ʽ����
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
* ��ͷ�ڵ��������в����µĽڵ�
* ���Ƚ��²�������ݹ����Ϊ�ڵ�
* ��Ϊ�½ڵ���Ƕ��е����һ��ֵ�������½ڵ�Ҫָ��NULL
* Ȼ������βָ��ָ�����ԭ��������е����һ��ֵ
* ���Դ�ʱҪ����βָ��ָ���½ڵ�
* ����βָ�������ƶ�һλ����ָ���½ڵ�s
*************************************************/
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

/************************************************
* ��ͷ�����������
* ������Ҫ�ж���������Ƿ�Ϊ��
* Ȼ�����ڶ�ͷָ����Ǳ�ͷָ�룬���Ƕ��еĵ�һ��Ԫ��Ӧ���Ƕ�ͷָ��ָ���next
* Ȼ���ȡ���е�һ��Ԫ��֮��������ɾ���ķ����Ϳ�����
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

