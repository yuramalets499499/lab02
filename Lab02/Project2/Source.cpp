// OOP Lab_1 task_5

#include <iostream>
#include <cmath>

using namespace std;

class RECTANGLE
{

private:

	int *h,
		*w;

public:

	RECTANGLE(int a, int b);
	RECTANGLE();
	RECTANGLE(const RECTANGLE &obj);

	int GetH(RECTANGLE& obj);
	int GetW(RECTANGLE& obj);

	int SetH(int a);
	int SetW(int b);

	int perimeter(RECTANGLE& obj);
	int square(RECTANGLE& obj);

	~RECTANGLE();
};



RECTANGLE::RECTANGLE()
{
	h = new int(0);
	w = new int(0);
}
RECTANGLE::RECTANGLE(int h, int w)
{
	this->h = new int(h);
	this->w = new int(w);
}
RECTANGLE::RECTANGLE(const RECTANGLE &obj)
{
	h = new int(*obj.h);
	w = new int(*obj.w);

}

int RECTANGLE::GetH(RECTANGLE& obj)
{
	return *h;
}

int RECTANGLE::GetW(RECTANGLE& obj)
{
	return *w;
}

int RECTANGLE::SetH(int a)
{
	return *h = a;
}

int RECTANGLE::SetW(int b)
{
	return *w = b;
}

int RECTANGLE::perimeter(RECTANGLE& obj)

{
	return (*h + *w) * 2;
}

int RECTANGLE::square(RECTANGLE& obj)
{
	return *h * *w;
}

RECTANGLE::~RECTANGLE()
{
	delete h;
	delete w;
}

int main()
{
	system("chcp 1251");
	system("COLOR FC");

	RECTANGLE obj1(3, 4);
	RECTANGLE *obj2 = new RECTANGLE;
	RECTANGLE obj3(obj1);

	cout << "\n���������� ��������� � ����� ������������ :\n ������ = 3\n ������ = 4\n";

	obj1.GetH(obj1);
	obj1.GetW(obj1);

	cout << "�������� ������������ = ";
	cout << obj1.perimeter(obj1) << endl;

	cout << "����� ������������ = ";
	cout << obj1.square(obj1) << endl;

	cout << "\n����� ������� ������ � ������ ������������ :\n ������ = 5\n ������ = 6\n";
	obj1.SetH(5);
	obj1.SetW(6);

	cout << "�������� ������������ = ";
	cout << obj1.perimeter(obj3) << endl;

	cout << "����� ������������ = ";
	cout << obj1.square(obj3) << endl;

	system("pause");

	return 0;
}