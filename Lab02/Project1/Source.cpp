// OOP Lab_1 task_19

#include <iostream>
#include <cmath>

using namespace std;

class COUNTER
{

private:
	int *n, *m;
	int *a, *b;

public:

	COUNTER();
	COUNTER(const COUNTER &obj);

	void pp1();
	void pp2();
	void check();
	void add();
	void go(COUNTER& obj1);

	~COUNTER();
};
COUNTER::COUNTER()
{
	n = new int(0);
	m = new int(0);
	a = new int(0);
	b = new int(0);
}

COUNTER::COUNTER(const COUNTER &obj)
{
	n = new int(*obj.n);
	m = new int(*obj.m);
	a = new int(*obj.a);
	b = new int(*obj.b);
}

void COUNTER::pp1()
{
	cin >> *a;

}

void COUNTER::pp2()
{
	cin >> *b;
}

void COUNTER::check()
{
	if (*b >= *a)
	{
		cout << "¬ведене вами м≥н≥мальне значенн€ б≥льше , н≥ж максимальне .¬вед≥ть знову : ";

	}
}

void COUNTER::go(COUNTER& obj1)
{
	for (*n = *b; *n <= *a; (*n)++)
	{
		cout << (*n) << endl;
	}
}


void COUNTER::add()
{
	(*n)++;
	(*m)++;
	(*a)++;
	(*b)++;

	for (*n = *b; (*n) <= (*a); (*n)++)
	{
		cout << (*n) << endl;
	}

}

COUNTER::~COUNTER()
{
	delete n;
	delete m;
	delete a;
	delete b;
}

int main()
{
	system("chcp 1251");
	system("COLOR F0");

	COUNTER obj1(int a, int b);
	COUNTER *obj2 = new COUNTER;
	COUNTER obj3;

	cout << "¬вед≥ть максимальне значенн€ л≥чильника : ";
	obj3.pp1();

	cout << "¬вед≥ть м≥н≥мальне  значенн€ л≥чильника : ";
	obj3.pp2();
	obj3.go(*obj2);
	obj3.check();
	cout << "«б≥льшенн€ значень л≥чильника на 1 : " << endl;
	obj3.add();

	system("pause");
	return 0;


}