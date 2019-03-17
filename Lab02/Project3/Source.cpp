#include <iostream>
#include <cmath>

using namespace std;

class CONE
{
private:

	double *R;
	double *H;
	double *L;

	const double Pi = 3.14;

public:

	CONE(double A, double B, double C);
	CONE();
	CONE(const CONE &obj);

	double GetR(CONE& obj);
	double GetH(CONE& obj);
	double GetL(CONE& obj);

	double SetR(double A);
	double SetH(double B);
	double SetL(double C);

	double square(CONE& obj);
	double V(CONE& obj);

	~CONE();
};

CONE::CONE()
{
	R = new double(0.0);
	H = new double(0.0);
	L = new double(0.0);
}

CONE::CONE(double R, double H, double L)
{
	this->R = new double(R);
	this->H = new double(H);
	this->L = new double(L);
}

CONE::CONE(const CONE &obj)
{
	R = new double(*obj.R);
	H = new double(*obj.H);
	L = new double(*obj.L);

}

double CONE::GetR(CONE& obj)
{
	return *R;
}

double CONE::GetH(CONE& obj)
{
	return *H;
}

double CONE::GetL(CONE& obj)
{
	return *L;
}

double CONE::SetR(double A)
{
	return *R = A;
}

double CONE::SetH(double B)
{
	return *H = B;
}

double CONE::SetL(double C)
{
	return *L = C;
}


double CONE::square(CONE& obj)
{
	return Pi * (*R) *(*R + *L);
}

double CONE::V(CONE& obj)
{
	return 1.0 / 3.0*Pi*(*R)*(*R)*(*H);
}

CONE::~CONE()
{
	delete R;
	delete H;
	delete L;
}

int main()
{

	system("chcp 1251");
	system("COLOR F0");

	CONE obj1(5.45, 4.05, 2.25);
	CONE *obj2 = new CONE;
	CONE obj3(obj1);

	cout << "\nОбчислення  площі та об'єму конуса :\n радіус = 5.45\n висота = 4.05\n твірна = 2.25\n";

	obj1.GetR(obj1);
	obj1.GetH(obj1);
	obj1.GetL(obj1);

	cout << "Площа поверхі конуса = ";
	cout << obj1.square(obj1) << endl;

	cout << "Об'єм конуса = ";
	cout << obj1.V(obj1) << endl;

	cout << "\nЗаміна значень радіуса , висоти та твірної конуса :\n радіус = 7.45\n висота = 9.55\n твірна = 7.85\n";

	obj1.SetR(7.45);
	obj1.SetH(9.55);
	obj1.SetL(7.85);

	cout << "Площа поверхі конуса = ";
	cout << obj1.square(obj1) << endl;

	cout << "Об'єм конуса = ";
	cout << obj1.V(obj1) << endl;

	system("pause");
	return 0;

}