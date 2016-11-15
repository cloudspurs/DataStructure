/**
 * Description: 链表类模板
 *
 *  Created: Nov 15, 2016
 *    Author: meingqinggang
 */

#ifndef	LNKLIST_H
#define	LNKLIST_H

#include <iostream>
using namespace std;

template <class T>
class Node {

public:
	T data;
	Node<T> *pointer;

	Node(const T d, Node<T> *pointerNode = NULL) {
		data = d;
		pointer = pointerNode;
	}

	Node(Node<T> *pointerNode) {
		pointer = pointerNode;
	}
};

template <class T>
class lnkList {

private:
	Node<T> *head, *tail;
	Node<T>* setPos(const int p);

public:
	lnkList();
	~lnkList();
	void print();
	void clear();
	bool isEmpty();
	int	 length();
	bool getValue(const int p, T &value);
	bool setValue(const int p, const T value);
	bool getPos(int &p, const T value);
	bool append(const T value);
	bool insert(const int p, const T value);
	bool deletee(const int p);
};

/*
* 设置链表的当前节点
* @para i 节点位置
* @return 设置的节点指针
*/
template <class T>
Node<T>* lnkList<T>::setPos(const int i) {
	if (i < -1) {
		return NULL;
	}
	// 返回头节点
	if (i == -1) {
		return head;
	}

	Node<T> *p = head->pointer;
	int count = 0;
	while (p != NULL && count < i) {
		p = p->pointer;
		count++;
	}
	return p;
}

template <class T>
lnkList<T>::lnkList() {
    // head & tail point to head node
	head = tail = new Node<T>(0, NULL);
	cout<<"new empty list!"<<endl;
}

template <class T>
lnkList<T>::~lnkList() {
	Node<T> *tmp;

	while (head != NULL) {
		tmp = head;
		head = head->pointer;
		delete tmp;
	}
}
/*
* 打印链表
*/

template <class T>
void lnkList<T>::print() {
	Node<T> *tmp = head->pointer;
	while (tmp != NULL) {
		cout<<tmp->data<<" ";
		tmp = tmp->pointer;
	}
	cout<<endl;
}

/*
* 清空链表
*/
template <class T>
void lnkList<T>::clear() {
	Node<T> *tmp;

	while (head != NULL) {
		tmp = head;
		head = head->pointer;
		delete tmp;
	}

	head = tail = new Node<T>(0, NULL);
}

/*
* 判断链表是否为空
*/
template <class T>
bool lnkList<T>::isEmpty() {
	if (head == tail) {
		cout<<"Lnklist is empty!"<<endl;
		return true;
	}

	return false;
}

/*
* 取得链表长度
* @Return 链表长度
*/
template <class T>
int lnkList<T>::length() {
	int length = 0;
	Node<T> *tmp = head->pointer;

	while (tmp != NULL) {
		length++;
		tmp = tmp->pointer;
	}

	return length;
}

/*
 * 设链表表元素
 * @Para i 链表位置
 * @Para value 需要设置的值
 */
template <class T>
bool lnkList<T>::setValue(const int i, const T value) {
	Node<T> *p;

	if ((p = setPos(i)) == NULL) {
		cout<<"Illegal setvalue!"<<endl;
		return false;
	}

	p->data = value;

	return true;
}

/*
 * 链表序表元素
 * @Para i 链表位置
 * @Para value 取得值的存放变量
 */
template <class T>
bool lnkList<T>::getValue(const int i, T &value) {
	Node<T> *p;

	if ((p = setPos(i)) == NULL) {
		cout<<"illegal getvalue!"<<endl;
		return false;
	}

	value = p->data;

	return true;
}

/*
 * 返回链表中元素第一次出现的位置
 * @Para 元素在链表中的位置
 * @Para 元素的值
 */
template <class T>
bool lnkList<T>::getPos(int &p, const T value) {
	Node<T> *q = head->pointer;
	int curLen = length();

	for (int i = 0; i < curLen; i++) {
		if (q->data == value) {
			p = i;
			return true;
		}

		q = q->pointer;
	}

	return false;
}

/*
 * 向链表追加元素
 * @Para value 需要追加的元素
 */
template <class T>
bool lnkList<T>::append(const T value) {
	Node<T> *p = new Node<T>(value, NULL);
	tail->pointer = p;
	tail = p;

	return true;
}

/*
 * 向链表插入元素
 * @Para i 需要插入的位置
 * @Para value 需要插入的元素
 */
template <class T>
bool lnkList<T>::insert(const int i, const T value) {
	Node<T> *p, *q;

	if (i < 0) {
		cout<<"Insertion illegal!"<<endl;
		return false;
	}

	if ((p = setPos(i-1)) == NULL) {
		cout<<"Insertion illegal!"<<endl;
		return false;
	}

	q = new Node<T>(value, p->pointer);
	p->pointer = q;

	if (p == tail) {
		tail = q;
	}

	return true;
}

/*
 * 向删除链表元素
 * @Para i 需要删除的元素位置
 */
template <class T>
bool lnkList<T>::deletee(const int i) {
	Node<T> *p, *q;

	if ((p = setPos(i-1)) == NULL || p == tail) {
		cout<<"Deletion illegal!"<<endl;
		return false;
	}

	q = p->pointer;

	if (q == tail) {
		tail = p;
		p->pointer = NULL;
		delete q;
	}
	else {
		if (q != NULL) {
			p->pointer = q->pointer;
			delete q;
		}
	}
	return true;
}

#endif
