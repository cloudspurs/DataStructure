/**
 * Description: 顺序表类模板
 *
 *  Created: Nov 15, 2016
 *    Author: meingqinggang
 */

#ifndef	ARRLIST_H
#define	ARRLIST_H

#include <iostream>
using namespace std;

template <class T>
class arrList {

private:

	T *aList;       // list pointer
	int	maxSize;    // Max length
	int	curLen;     // current length
	int	position;   // current position

public:

	arrList(const int size) {
		maxSize = size;
		aList = new T[maxSize];
		curLen = position = 0;
	}

	~arrList() {
		delete [] aList;
	}

	/*
	 * 打印顺序表
	 */
	void print() {
		if (this->isEmpty()) {
			cout<<"Warning_ArrList: Empty ArrList!"<<endl;
			return;
		} else {
			for (int i = 0; i < curLen; i++) {
				cout<<aList[i]<<" ";
			}
			cout<<endl;
		}
	}

	/*
	 * 清空顺序表
	 */
	void clear() {
		delete [] aList;
		curLen = position = 0;
		aList = new T[maxSize];
	}

	/*
	 * 判断顺序表是否为空
	 */
	bool isEmpty() {
		if (curLen == 0) {
			return true;
		}
        else {
		    return false;
        }
	}

	/*
	 * 取得顺序表长度
	 * @Return 顺序表长度
	 */
	int length() {
		return curLen;
	}

	bool getValue(const int p, T& value);
	bool setValue(const int p, const T value);
	bool getPos(int& p, const T value);
	bool append(const T value);
	bool insert(const int p, const T value);
	bool deletee(const int p);
};

/*
 * 获取顺序表元素
 * @Para i 顺序表位置
 * @Para value 取得值的存放变量
 */
template <class T>
bool arrList<T>::getValue(const int p, T &value) {

	// empty arrList can't getvalue
    if (curLen == 0) {
        cout<<"ERROR_ArrList_getValue: Empty arrList!"<<endl;
        return false;
    }

	// illegal position can't getvalue
	if (p < 0 || p >= curLen) {
		cout<<"ERROR_ArrList_getValue: Illegal position!"<<endl;
		return false;
	}

	value = aList[p];

	return true;
}

/*
 * 设置顺序表元素
 * @Para 顺序表位置
 * @Para 需要设置的值
 */
template <class T>
bool arrList<T>::setValue(const int p, const T value) {
	if (p < 0 || p >= curLen) {
		cout<<"ERROR_ArrList_setValue: Illegal position!"<<endl;
		return false;
	}

	aList[p] = value;

	return true;
}

/*
 * 返回顺序表中元素第一次出现的位置
 * @Para 元素在顺序表中的位置
 * @Para 元素的值
 */
template <class T>
bool arrList<T>::getPos(int& p, const T value) {

	if (this->isEmpty()) {
		return false;
	}

	for (int i = 0; i < curLen; i++)
		if (value == aList[i]) {
			p = i;
			return true;
		}

	return false;
}

/*
 * 向顺序表追加元素
 * @Para 需要追加的元素
 */
template <class T>
bool arrList<T>::append(const T value) {
	// if arrlist full, can't append
	if (curLen >= maxSize) {
		cout<<"ERROR-ArrList_append: Arrlist is overflow!"<<endl;
		return false;
	}

	aList[curLen++] = value;

	return true;
}

/*
 * 向顺序表插入元素
 * @Para 需要插入的位置
 * @Para 需要插入的元素
 */
template <class T>
bool arrList<T>::insert(const int p, const T value) {
	if (curLen >= maxSize) {
		cout<<"ERROR_ArrList_insert: Arrlist is overflow!"<<endl;
		return false;
	}

	if (p < 0 || p > curLen) {
		cout<<"ERROR_ArrList_insert: Insertion position is illegal!"<<endl;
		return false;
	}

	// 从插入位置开始，把元素往后移一格，空出插入位置。
	for (int i = curLen; i > p; i--) {
		aList[i] = aList[i-1];
	}

	// 插入元素
	aList[p] = value;

	// 顺序表当前长度加一
	curLen++;

	return true;
}

/*
 * 删除顺序表元素
 * @Para 需要删除的元素位置
 */
template <class T>
bool arrList<T>::deletee(const int p) {
	if (this->isEmpty()) {
		cout<<"ERROR_ArrList_deletee: Empty arrList!"<<endl;
		return false;
	}

	if (p < 0 || p > curLen-1) {
		cout<<"ERROR_ArrList_deletee: Illegal deletion position!"<<endl;
		return false;
	}

	// 把删除位置往后的元素往前移一格
	for (int i = p; i < curLen-1; i++) {
		aList[i] = aList[i+1];
	}

	// 顺序表当前长度减一
	curLen--;

	return true;
}

#endif
