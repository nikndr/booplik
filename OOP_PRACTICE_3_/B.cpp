#include "B.h"

A& B::f(A& a)
{
	return a;
}

A *B::g(A *)
{
	return nullptr;
}

//NEVER DEFINE ASSIGNMENT THIS WAY LOL xD
void B::operator=(const B &)
{

}
