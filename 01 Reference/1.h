#include <iostream>
using namespace std;
class Component
{
};

class Composit
{
private:
	Component _component;
public:
	Composit():_component(Component()){};
	Component get() const
	{
		cout<<"Copied component"<<endl;
		return _component;
	}
	const Component& getref() const 
	{
		cout<<"Transmitted constant component"<<endl;
		return _component;
	}
	Component& getref()
	{
		cout<<"Transmitted non-constant component"<<endl;
		return _component;
	}
};