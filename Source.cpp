#include <iostream>

#include <cmath>



using namespace std;



class Point3D

{

private:

	int x;

	int y;

	int z;



public:

	Point3D() { x = y = z = 0; }

	Point3D(int a, int b, int c) { x = a; y = b; z = c; }

	~Point3D() {}

	int GetX() { return x; }

	int GetY() { return y; }

	int GetZ() { return z; }



	void SetX(int a) { x = a; }

	void SetY(int b) { y = b; }

	void SetZ(int c) { z = c; }



	void Print(void);

	double Distance(Point3D& obj);

};



void Point3D::Print(void)

{

	cout << x << ' ' << y << ' ' << z << endl;

}



double Point3D::Distance(Point3D& obj)

{

	return sqrt(pow((double)x - obj.GetX(), 2) +

		pow((double)y - obj.GetY(), 2) +

		pow((double)z - obj.GetZ(), 2));

}



int main()

{

	Point3D obj1(1, 2, 3);

	Point3D obj2;



	// cout<<obj1.x<<endl;   //недоступно

	// cout<<obj1.y<<endl;   //недоступно

	// cout<<obj1.z<<endl;   //недоступно



	cout << obj1.GetX() << endl;

	cout << obj1.GetY() << endl;

	cout << obj1.GetZ() << endl;



	obj2.Print();



	cout << obj1.Distance(obj2) << endl;



	obj1.SetX(6);

	obj1.SetY(5);

	obj1.SetZ(4);



	obj2.Print();



	cout << obj1.Distance(obj2) << endl;



	return 0;

}