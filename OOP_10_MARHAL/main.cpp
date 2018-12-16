#include "Sequence.h"

int main()
{
	try {

		Sequence<int> sequence1(10);
		cout << "Created empty sequence with length 10\nAdding from 0 to 11" << endl;
		sequence1.add(0).add(1).add(2).add(3).add(4).add(5);
		sequence1.add(6).add(7).add(8).add(9).add(10).add(11);
		cout << sequence1 << endl;
		cout << "capacity:" << sequence1.capacity() << endl;
		cout << "size:" << sequence1.size() << endl;

		cout << "cutting 10 times" << endl;
		for (size_t i = 0; i < 10; i++) {
			sequence1.cut();
		}
		cout << sequence1 << endl;
		cout << "capacity:" << sequence1.capacity() << endl;
		cout << "size:" << sequence1.size() << endl;

		cout << "Adding some numbers: 10,33,44" << endl;
		sequence1.add(10).add(33).add(44);
		cout << sequence1 << endl;
		cout << "capacity:" << sequence1.capacity() << endl;
		cout << "size:" << sequence1.size() << endl;

		cout << "inserting 100 to index 2" << end;
		sequence1.insert(100, 2);
		cout << sequence1 << endl;
		cout << "capacity:" << sequence1.capacity() << endl;
		cout << "size:" << sequence1.size() << endl;

		cout << boolalpha << "is 228 in sequence? " << sequence1.contains(228);
		cout << boolalpha << "is 32 and 44 in sequence? " << sequence1.contains(32) && sequence1.contains(44);

		cout << "clear sequence" << endl;
		sequence1.clear();
		cout << "inserting 100 to index 2" << end;
		sequence1.insert(100, 2);
		cout << sequence1 << endl;
		cout << "capacity:" << sequence1.capacity() << endl;
		cout << "size:" << sequence1.size() << endl;

		cout << "filling again with 0-9" << endl;
		for (size_t j = 0; j < 10; j++) {
			sequence1.add(j);
		}
		cout << "inserting 100 to index 2" << end;
		sequence1.insert(100, 2);
		cout << sequence1 << endl;
		cout << "capacity:" << sequence1.capacity() << endl;
		cout << "size:" << sequence1.size() << endl;

	}
	catch (Sequence<int>::BadSeq err) {
		err.printStackTrace();
	}
	catch (Array<int>::BadArray err) {
		err.trace();
	}
	return 0;
}