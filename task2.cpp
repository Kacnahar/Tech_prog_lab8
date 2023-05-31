/*
Варданян Гамлет 
группа 22.1

Разработать программу на языке С++ для решения следующей задачи.
Даны комплексные числа a, b, c
Найти комплесное число d по формуле d = a^3*b/(b+c)*|a-b|
*/

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
struct complex1
{
	float Re;
	float Im;
};
struct complex2
{
	float Modul;
	float Argum;
};

complex1 input()
{
	complex1 temp;
	cout<<"Введите  комлексное число\n";
	cin>>temp.Re;cin>>temp.Im;

	return temp;
}

void output(complex1 chislo)
{
	cout<<chislo.Re;
	if (chislo.Im>=0)
		cout<<" + "<<chislo.Im<<"i"<<endl;
	else 
		cout<<" "<<chislo.Im<<"i"<<endl;
}

complex1 transfer(complex2 a, bool pr=false)
{
	complex1 temp;
	temp.Re= a.Modul*cos(a.Argum);
	temp.Im= a.Modul*sin(a.Argum);
	if (pr) output(temp);
	return temp;
}

complex2 transfer(complex1 a)
{
	complex2 temp;
	temp.Modul=sqrt(a.Re*a.Re + a.Im*a.Im);
	temp.Argum=atan(a.Im/a.Re);
	return temp;
}
complex1 multy(complex1 a1, complex1 a2)
{
	complex1 temp;
	temp.Re = a1.Re*a2.Re - a1.Im*a2.Im;
	temp.Im = a1.Im*a2.Re + a1.Re*a2.Im;

	return temp;
}

complex1 pluse(complex1 a1, complex1 a2)
{
	complex1 temp;
	temp.Re = a1.Re + a2.Re;
	temp.Im = a1.Im + a2.Im;
	
	return temp;
}

complex1 minus1(complex1 a1, complex1 a2)
{
	complex1 temp;
	temp.Re=a1.Re - a2.Re;
	temp.Im=a1.Im - a2.Im;

	return temp;
}

complex1 divide1(complex1 a,	complex1 b) {
    double den = b.Re * b.Re + b.Im * b.Im;
    complex1 res;
    
    res.Re = (a.Re * b.Re + a.Im * b.Im) / den;
    res.Im = (a.Im * b.Re - a.Re * b.Im) / den;

    return res;
}

complex1 pow1(complex1 a, int n)
{
	complex1 temp;
	complex2 temp2;
	float p=1;
	temp2 = transfer(a);	
	for(int i = 1; i<=n;p*=temp2.Modul,i++);
	temp.Re=p*cos(n*temp2.Argum);
	temp.Im=p*sin(n*temp2.Argum);
	return temp;
}
complex1 sqrtn1(complex1 a1, int n, float * ro,float * fi)
{	complex1 temp;
	complex2 temp2;
	int i=0;
	temp2=transfer(a1);	
	*ro=pow(temp2.Modul, (float)1/n);
	*fi=temp2.Argum;
	temp.Re=*ro*cos((*fi+2*M_PI*i)/n);
	temp.Im=*ro*sin((*fi+2*M_PI*i)/n);
	return temp;
}
int main()
{
    complex1 a1, a2, a3, a4;	
	float temp;
    a1 = input();
    a2 = input();
    a3 = input();
	
	a4 = minus1(a1, a2);
	temp =  sqrt((a4.Re * a4.Re) + (a4.Im * a4.Im));//|a-b|

	
    a1 = pow1(a1, 3);
    a1 = multy(a1, a2);//a^3*b
	cout << "a^3*b = " << a1.Re << " + " <<a1.Im << "i" << endl;
    a2 = pluse(a2, a3);//b+c
	cout << "b + c = " << a2.Re << " + " <<a2.Im << "i" << endl;
    a3 = divide1(a1, a2);//divide 
	cout << "divide = " << a3.Re << " + " <<a3.Im << "i" << endl;
	
	a3.Im *= temp;a3.Re *= temp;//end
	cout << "temp = " << temp << endl;

	cout << a3.Re << " + " << a3.Im << "i" << endl;

}

