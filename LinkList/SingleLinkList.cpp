/************************************************
*************************************************/
#include <iostream>
using namespace std;


/************************************************
* 假设链表存储的数据是int类型
*************************************************/
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
/************************************************
其实LNode和*LinkList都是一样意义的，都表示链表的头节点
强调这是一个链表就是使用LinkList
强调这是一个节点就用LNode *
用不同的命名区分开是为了增加可读性
*************************************************/


/************************************************
*初始化带头节点的链表
* 首先要分配一个头节点
* 然后再检测是否分配成功
* 同时将next指针设置为空
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
* 由于链表头指针不具有数据存储的意义
* 因此判断之后的才可以
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
* 头插入法建立链表的思想为首先建立一个头节点
* 然后在插入节点时，将新节点指向后续节点
* 将头节点指向新节点这样就能保证每一个插入的节点都是在头节点后面，在其它节点之前
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
* 通过尾节点插入法来构造一个链表
* 首先要创建一个空块*s来负责构建每一个块
* 然后要拿*r = L来保证当前对L链表进行操作（此处不能直接用L来进行next操作，因为L是代表着头节点，不能随意移动）
* 然后每操作完一次后，都要保证链表的next指向了下一个块，完成指向记录后将r往后移动到当前的这个s块
* 如果输入完成了，就要把最后一个块的next置空来确保链表的结束
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
*从链表中取数据的思路：（按照index来进行索引）
*首先判断是否要取出第0个，如果需要取出第0个，直接返回链表头
*然后接下来判断要取出的链表节点位置是否合法（其实先判断是否合法也可以的吧）
*然后接下来就判断p节点是否为空以及当前所遍历到的节点是否为目标节点，如果满足条件，则返回节点
*如果前面的条件都不满足，则返回空节点，表示找不到
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
* 按值查找链表：
* 从头开始遍历，找不到就使用next
* 一直到最后找不到就返回null，找得到就输出
*************************************************/
LNode* LocateElement(LinkList L, int e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

/************************************************
* 将节点e，插入到链表L，的第i个，位置
* 首先判断是i的位置是否合法
* 然后插入的思想是
* 先找到插入位置的前驱节点，再将该指针赋值给s
* 然后再将p节点的后继设置为s
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
* 删除节点首先要找到要删除的节点的前驱
* 然后再用q节点来表示要删除的节点
* 将p的next指针指向q的next来代表p直接与q->next相连
* 然后最后free掉q节点就可以了
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