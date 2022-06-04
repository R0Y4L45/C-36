#include <iostream>
#include <cassert>

using namespace std;


#include "time.h"
#include "Vector.h"

int main()
{
	Vector a(5);
	a.push_front(5);
	a.push_back(3);
	a.push_back(4);
	a.push_front(6);
	a.push_back(5);
	a();
	cout << a.rfind(5) << endl;
	cout << a.find(5) << endl;
	a.sort(true);
	a();
}

