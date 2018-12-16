//
// Created by Nick Marhal on 1/31/18.
//

#ifndef OOP_PRACTICE_3_AGGREGATE_H
#define OOP_PRACTICE_3_AGGREGATE_H

class Aggregee
{
	public:
		explicit Aggregee(int a = 0);

	private:
		int _a;
};

class Aggregate
{
	public:
		Aggregate(Aggregee);

	private:
		Aggregee _aggregee;
};

#endif //OOP_PRACTICE_3_AGGREGATE_H
