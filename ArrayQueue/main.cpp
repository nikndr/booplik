#include <iostream>
#include "ArrayQueue.h"

int main()
{
	ArrayQueue<int> q(10);
	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}
	cout << q << endl;

	for (int j = 0; j < 5; j++) {
		cout << q.dequeue() << " ";
	}
	q.enqueue(1).enqueue(2).enqueue(22);
	cout << endl << q << endl;
	return 0;
}