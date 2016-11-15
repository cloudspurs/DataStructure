/**
 * Description: 顺序表单元测试
 *
 *  Created: Nov 15, 2016
 *    Author: meingqinggang
 */

#include <iostream>
#include <assert.h>
#include "ArrList.h"

using namespace std;

int main() {

	 arrList<int> a(8);

	 assert(a.deletee(3) == false);

	a.append(1);
	a.append(2);
	a.append(3);
	a.append(4);
	a.append(5);
	a.append(6);

	assert(a.isEmpty() == false);
	assert(a.length() == 6);

	int b;
	a.getValue(0, b);
	assert(b == 1);
	a.getValue(3, b);
	assert(b == 4);
	a.getValue(5, b);
	assert(b == 6);

	assert(a.getValue(0, b) == true);
	assert(a.getValue(7, b) == false);
	assert(a.getValue(-1, b) == false);

	a.getPos(b, 1);
	assert(b == 0);
	a.getPos(b, 4);
	assert(b == 3);
	a.getPos(b, 6);
	assert(b == 5);

   assert(a.getPos(b, 5) == true);
   assert(a.getPos(b, 12) == false);

   assert(a.append(7) == true);
   assert(a.length() == 7);
//   assert(a.append(8) == false);
//   assert(a.length() == 7);

   assert(a.insert(-1, 12) == false);
   assert(a.insert(a.length() + 1, 1) == false);
   assert(a.insert(2, 12) == true);
   a.print();
   assert(a.length() == 8);
   assert(a.getValue(2, b) == true);
   assert(b == 12);

   assert(a.deletee(2) == true);
   a.print();
   assert(a.length() == 7);
   assert(a.deletee(-1) == false);
   assert(a.deletee(a.length()) == false);

	a.print();
	a.clear();
	a.print();

	return 0;
}
