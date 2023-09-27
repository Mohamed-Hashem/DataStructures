#include <iostream>
using namespace std;

template <class type1, class type2>
struct Pair
{
	type1 first;
	type2 second;

	Pair()
	{

	}
	Pair(type1 _first, type2 _second)
	{
		first = _first;
		second = _second;
	}
};