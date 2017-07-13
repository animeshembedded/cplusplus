#include <iostream>
#include <cstring>
#include <utility>
using namespace std;
void break_point();
class Sample
{
	public:
	Sample() = delete;
	Sample(int rhs)
	{
		data=rhs;
	}
	private:
	int data;
};
int main()
{
	Sample oSampleA;
	Sample oSampleB(100);
}
#if 0
class Sample
{
	public:
	Sample() = default;
	Sample(int rhs)
	{
		data=rhs;
	}
	private:
	int data;
};
int main()
{
	Sample oSampleA;
	Sample oSampleB(100);
}
#endif
#if 0
class Sample
{
	public:
	Sample(int rhs)
	{
		data=rhs;
	}
	private:
	int data;
};
int main()
{
	Sample oSampleA;
	Sample oSampleB(100);
}
#endif

