/************************************************
*************************************************/
#include <iostream>
using namespace std;


/************************************************
* ���������洢��������int����
*************************************************/
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
/************************************************
��ʵLNode��*LinkList����һ������ģ�����ʾ������ͷ�ڵ�
ǿ������һ����������ʹ��LinkList
ǿ������һ���ڵ����LNode *
�ò�ͬ���������ֿ���Ϊ�����ӿɶ���
*************************************************/


/************************************************
*��ʼ����ͷ�ڵ������
* ����Ҫ����һ��ͷ�ڵ�
* Ȼ���ټ���Ƿ����ɹ�
* ͬʱ��nextָ������Ϊ��
*************************************************/
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

/************************************************
* ��������ͷָ�벻�������ݴ洢������
* ����ж�֮��Ĳſ���
*************************************************/
bool Empty(LinkList L) {
	if (L->next == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}

/************************************************
* ͷ���뷨����������˼��Ϊ���Ƚ���һ��ͷ�ڵ�
* Ȼ���ڲ���ڵ�ʱ�����½ڵ�ָ������ڵ�
* ��ͷ�ڵ�ָ���½ڵ��������ܱ�֤ÿһ������Ľڵ㶼����ͷ�ڵ���棬�������ڵ�֮ǰ
*************************************************/
LinkList ListHeaderInsert(LinkList& L) {
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	cin >> x;
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

/************************************************
* ͨ��β�ڵ���뷨������һ������
* ����Ҫ����һ���տ�*s�����𹹽�ÿһ����
* Ȼ��Ҫ��*r = L����֤��ǰ��L�������в������˴�����ֱ����L������next��������ΪL�Ǵ�����ͷ�ڵ㣬���������ƶ���
* Ȼ��ÿ������һ�κ󣬶�Ҫ��֤������nextָ������һ���飬���ָ���¼��r�����ƶ�����ǰ�����s��
* �����������ˣ���Ҫ�����һ�����next�ÿ���ȷ�������Ľ���
*************************************************/
LinkList ListTailInsert(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s;
	LNode* r = L;
	cin >> x;
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}

/************************************************
*��������ȡ���ݵ�˼·��������index������������
*�����ж��Ƿ�Ҫȡ����0���������Ҫȡ����0����ֱ�ӷ�������ͷ
*Ȼ��������ж�Ҫȡ���������ڵ�λ���Ƿ�Ϸ�����ʵ���ж��Ƿ�Ϸ�Ҳ���Եİɣ�
*Ȼ����������ж�p�ڵ��Ƿ�Ϊ���Լ���ǰ���������Ľڵ��Ƿ�ΪĿ��ڵ㣬��������������򷵻ؽڵ�
*���ǰ��������������㣬�򷵻ؿսڵ㣬��ʾ�Ҳ���
*************************************************/
LNode* GetElement(LinkList L, int i) {
	int j = 1;
	LNode* p = L->next;
	if (i == 0) {
		return L;
	}
	if (i < 1) {
		return NULL;
	}
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

/************************************************
* ��ֵ����������
* ��ͷ��ʼ�������Ҳ�����ʹ��next
* һֱ������Ҳ����ͷ���null���ҵõ������
*************************************************/
LNode* LocateElement(LinkList L, int e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

/************************************************
* ���ڵ�e�����뵽����L���ĵ�i����λ��
* �����ж���i��λ���Ƿ�Ϸ�
* Ȼ������˼����
* ���ҵ�����λ�õ�ǰ���ڵ㣬�ٽ���ָ�븳ֵ��s
* Ȼ���ٽ�p�ڵ�ĺ������Ϊs
*************************************************/
bool ListInsert(LinkList& L, int i, int e) {
	if (i < 0) {
		return false;
	}

	LNode* s;
	s->data = e;

	if (i == 0) {
		s->next = L->next;
		L->next = s;
		return true;
	}

	LNode* p = GetElement(L, i - 1);

	if (p == NULL) {
		return false;
	}

	s->next = p->next;
	p->next = s;
	return true;
}

/************************************************
* ɾ���ڵ�����Ҫ�ҵ�Ҫɾ���Ľڵ��ǰ��
* Ȼ������q�ڵ�����ʾҪɾ���Ľڵ�
* ��p��nextָ��ָ��q��next������pֱ����q->next����
* Ȼ�����free��q�ڵ�Ϳ�����
*************************************************/
bool DeleteItem(LinkList& L, int i) {
	if (i < 0) {
		return false;
	}
	LNode* p = GetElement(L, i - 1);
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

int main() {
	LNode* p = (LNode*)malloc(sizeof(LNode));

	return 0;
}