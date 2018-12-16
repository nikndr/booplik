template <class ListItem>
class SingleList
{
public:
	
	class BadList{};
	SingleList();
	SingleList(const SingleList&);
	~SingleList();

	bool isEmpty() const;
	int length() const;

	void insert (int, ListItem);
	void remove (int);
	void retrieve(int, ListItem&) const;
	
	
private:
	struct ListNode
	{
		ListItem _elem;
		ListNode * _next;
	};
//	Whre is located the fist element
	ListNode * _head;
//	Where is located element # index
	ListNode * find(int index) const;
};