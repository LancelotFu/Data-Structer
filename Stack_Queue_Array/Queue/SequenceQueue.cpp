/************************************************
*************************************************/
#include <iostream>
using namespace std;

/************************************************
* ���е�˳��ʵ��
* ��ʵ�ֶ��еĹ�����Q.frontָ���һ��Ԫ��
* Q.rearָ��ĩβԪ�ص���һ��Ԫ�أ�NULL��
*************************************************/
const int MaxSize = 10;
typedef struct {
	int data[MaxSize];
	int front, rear;
	int size;
}SqQueue;

void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
	Q.size = 0;
}

bool QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front) {
		return true;
	}
	else {
		return false;
	}
	//if (Q.size == 0) {
	//	return true;
	//}
	//else {
	//	return false;
	//}
}

bool EnQueue(SqQueue& Q, int x) {
	if (Q.rear - Q.front == MaxSize) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = Q.rear + 1;
	Q.size++;
//  ѭ������
//  Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

bool Dequeue(SqQueue& Q, int& data) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.size--;
	return true;
}

bool GetHead(SqQueue Q, int& x) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

int GetLength(SqQueue Q) {
	return (Q.rear + MaxSize - Q.front) % MaxSize;
	//return size;
}