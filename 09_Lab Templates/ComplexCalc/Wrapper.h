template <typename Type>
class Wrapper
{
private:
	Type _data;
public:
	Wrapper(const Type& data):_data(data){};
	operator Type() const {return _data;}
	Type data() const {return _data;}
	Type& data() {return _data;}
};

template <typename Type> ostream& operator<<(ostream & os, const Wrapper<Type> & a)
{
	return os<<a.data();
}
template <typename Type> istream& operator>>(istream & os, Wrapper<Type>& a)
{
	return is>>a.data();
}

template <typename Type> Wrapper<Type>& operator+=(Wrapper<Type>& a, const Wrapper<Type>& b)
{
	a.data()+=b.data();
	return a;
}
template <typename Type> Wrapper<Type>& operator-=(Wrapper<Type>& a, const Wrapper<Type>& b)
{
	a.data()-=b.data();
	return a;
}
template <typename Type> Wrapper<Type>& operator*=(Wrapper<Type>& a, const Wrapper<Type>& b)
{
	a.data()*=b.data();
	return a;
}
template <typename Type> Wrapper<Type>& operator/=(Wrapper<Type>& a, const Wrapper<Type>& b)
{
	a.data()/=b.data();
	return a;
}

template <typename Type> const Wrapper<Type>  operator+ (Wrapper<Type> a, const Wrapper<Type>& b)
{
	return a+=b;
}

template <typename Type> const Wrapper<Type>  operator- (Wrapper<Type> a, const Wrapper<Type>& b)
{
	return a-=b;
}
template <typename Type> const Wrapper<Type>  operator* (Wrapper<Type> a, const Wrapper<Type>& b)
{
	return a*=b;
}
template <typename Type> const Wrapper<Type>  operator/ (Wrapper<Type> a, const Wrapper<Type>& b)
{
	return a/=b;
}