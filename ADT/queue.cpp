/* queue implementation 

  Author: Karry Kaul
*/

#include<iostream>
#include<vector>
#include "queue.h"
#define dtype int

using namespace std;


int main() {
	
	queue _;
	_.enqueue(10);
	_.enqueue(20);
	_.enqueue(30);
	_.enqueue(49);
	_.enqueue(50);
	
	_.display();
	
	_.dequeue();
	_.display();
	
	return 0;
}