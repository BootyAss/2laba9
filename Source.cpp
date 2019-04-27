#include<iostream>
#include<array>
#include<algorithm>

//Template Class
template <typename T>
class Myclass {
	T x;
	T y;
public:
	Myclass(T a = 0, T b = 0) :x(a), y(b) {};
	~Myclass() {};
	auto get_param();
};

template <typename T>
auto Myclass<T>::get_param() {
	auto temp = std::make_pair(this->x, this->y);
	return temp;
}


// int Class
class MyClass {
	int x;
	int y;
public:
	MyClass(int a = 0, int b = 0) :x(a), y(b) {};
	~MyClass() {};
	auto get_param();
};

auto MyClass::get_param() {
	auto temp = std::make_pair(this->x, this->y);
	return temp;
}


//Template Function
template<class A, class B, typename T>
void foo(A first, B second) {
	std::array<T, 4> a{ first.get_param().first, first.get_param().second, second.get_param().first, second.get_param().second };
	std::sort(a.begin(), a.end(), std::greater<T>());
	for (int i = 0; i < 4; i++)
		std::cout << a[i] << " \t";
	std::cout << "\n\n";
}


void main() {
	// Для ручного воода значений
	//int temp, temp1;
	//std::cin >> temp >> temp1;
	//Myclass<int> a(temp, temp1);

	//double temp2, temp3;
	//std::cin >> temp2 >> temp3;
	//Myclass<double> a1(temp2, temp3);

	//std::cin >> temp >> temp1;
	//MyClass b(temp, temp1);

	Myclass<int> a(6, 7);
	Myclass<double> a1(5.2, 6.8);
	MyClass b(5, 7);
	std::cout << "\n first <int> :     ";
	foo<Myclass<int>, MyClass, int>(a, b);
	std::cout << " first <double> :  ";
	foo<Myclass<int>, MyClass, double>(a, b);
	std::cout << " second <int> :    ";
	foo<Myclass<double>, MyClass, int>(a1, b);
	std::cout << " second <double> : ";
	foo<Myclass<double>, MyClass, double>(a1, b);

	system("pause");
}

