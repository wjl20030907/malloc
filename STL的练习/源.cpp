#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
/*
int main()
{
   
	vector<int>myvector;
	for (int i = 1; i < 10; ++i) myvector.push_back(i * 10);
	//这个操作会打印10到90，并且有 ，
	ostream_iterator<int>out_it(cout, 0);
	copy(myvector.begin(), myvector.end(), out_it);
	return 0;
}
*/
//下面是对
class Foo
{
public:
	int _id;
	long _data;
	string _str;
public:
	Foo() : _id(0) { cout << "default ctor.this=" << this << "id=" <<_id<< endl; }
	Foo(int i) : _id(i) { cout << "ctor.this=" << this << "id=" << _id << endl; }
public:
	static void* operator  new(size_t size);
	static void operator  delete(void* pdead, size_t size);
	static void* operator new[](size_t size);
	static void operator delete[](void* pdead, size_t size);

	//virtual
	~Foo() { cout << "dtor.this =" << this << "id=" << _id << endl; }
	
	void* Foo::operator new(size_t size) {
		Foo* p = (Foo*)malloc(size);
		cout <<"..."<< endl;
		return p;
	}
	void Foo::operator delete(void* pdead, size_t size)
	{
		cout << "..." << endl;
		free(pdead);
	}
};
int main()
{
	
}