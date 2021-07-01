#include<iostream>
using namespace std;
//类模板对象做函数参数
//1.指定传入类型
//2.参数模板化
//3.整个类模板化
//#include<string>
//template<class T1,class T2>
//class person
//{
//public:
//	person(T1 name,T2 age )
//	{
//		m_name = name;
//		m_age = age;
//	}
//	T1 m_name;
//	T2 m_age;
//};
////void showperson(person<string, int>& p)//法一：.指定传入类型
////{
////	cout << " 姓名：" << p.m_name << " 年龄: " << p.m_age << endl;
////}
////template<class T1,class T2>
////void showperson(person<T1, T2>& p)//法二：参数模板化
////{
////	cout << " 姓名：" << p.m_name << " 年龄: " << p.m_age << endl;
////}
//template<class T >
//void showperson(T & p)//法三：整个类模板化(让系统自动推导p的类型)
//{
//	cout << " 姓名：" << p.m_name << " 年龄: " << p.m_age << endl;
//	cout << "T的类型为：" << typeid(T).name() << endl;//T的类型为：class person<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int>
//	//string的全名很长：class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
//	//记住这个查看类型的函数
//	//注：开发过程中一般使用第一种方法 比较明了 方便
//}
//void test()
//{
//	person<string, int>p("张三",18);
//	showperson(p);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//类模板与继承
//template<class T>
//class Father
//{
//public:
//	T m_a;
//};
//
////class son1 :public Father//报错 没有传入Father中T的类型
////{
////
////};
//class son1 :public Father<int>//这样就可以 但这样不够灵活
//{
//public:
//
//};
////比较灵活的代码
//template<class T1,class T2>
//class son2 :public Father<T1>
//{
//public:
//	son2()
//	{
//		cout << "T1的类型为：" << typeid(T1).name() << endl;//T1的类型为：int
//		cout << "T2的类型为：" << typeid(T2).name() << endl;//T2的类型为：int
//
//	}
//	T2 m_b;
//};
//void test()
//{
//	//son1 p1;
//	son2<int, int>p2;
//}
//int main()
//{
//	test();
//	return 0;
//}
//类模板的成员函数的类外实现
//#include<string>
//template<class T1,class T2>
//class Father
//{
//public:
//	Father(T1 name,T2 age);
//	void showinfo();
//	T1 m_name;
//	T2 m_age;
//};
//template<class T1, class T2>
//Father<T1,T2>::Father(T1 name, T2 age)//注意在Father后加上<T1，T2>告诉编译器Father是一个类模板
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//template<class T1, class T2>
//void Father<T1,T2>::showinfo()
//{
//	cout << " 姓名： " << this->m_name << " 年龄： " << this->m_age << endl;
//}
//void test()
//{
//	Father<string, int>p("张三", 18);
//	p.showinfo();
//}
//int main()
//{
//	test();
//	return 0;
//}
//类模板的份文件编写
//#include<string>
//template<class T1,class T2>
//class Father
//{
//public:
//	Father(T1 name,T2 age);
//	void showinfo();
//	T1 m_name;
//	T2 m_age;
//};
//#include"person.h"//引用person.h  报错 因为类模板中成员函数是在调用时创建的
//解决办法1 直接包含源文件
//#include"person.hpp"//这个hpp好像是自己定义的 我试了kpp也行
//解决方法2：将源文件和头文件写在一个文件中 在引用那个文件

//template<class T1, class T2>
//Father<T1,T2>::Father(T1 name, T2 age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//template<class T1, class T2>
//void Father<T1,T2>::showinfo()
//{
//	cout << " 姓名： " << this->m_name << " 年龄： " << this->m_age << endl;
//}
//void test()
//{
//	Father<string, int>p("张三", 18);
//	p.showinfo();
//}
//int main()
//{
//	test();
//	return 0;
//}
//类模板与友元
//全局函数类外实现
//#include<string>
//template<class T1,class T2>
//class person;//提前让编译器知道有一个类模板person类在
//template<class T1,class T2>
//void showinfo1(person<T1,T2> p)
//{
//	cout << " 姓名： " << p.m_name << " 年龄： " << p.m_age << endl;
//}
//#include<string>
//template<class T1,class T2>
//class person
//{
//	//全局函数类内实现
//	friend void showinfo1<>(person<T1, T2> p);//这个中间的<>一定要写 告诉编译器showinfo1()函数是一个函数模板
//	//全局函数类内实现
//	friend void showinfo(person<T1,T2> p)//这里面<T1,T2>可写可不写
//	{
//		cout << " 姓名： " << p.m_name << " 年龄： " << p.m_age << endl;
//	}
//public:
//	person(T1 name,T2 age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//private:
//	T1 m_name;
//	T2 m_age;
//};
//void test()
//{
//	person<string, int>p("张三", 18);
//	showinfo(p);
//	showinfo1(p);
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//类模板案例———数组的封装

#include"Myarr.hpp"
//void test()
//{
//	Myarr<int>arr(5);//有参构造函数调用 析构函数调用
//	Myarr<int>arr1(arr);
//	/*
//有参构造函数调用
//拷贝构造函数调用
//析构函数调用
//析构函数调用
//	*/
//	Myarr<int>arr2(100);
//	/*
//有参构造函数调用
//拷贝构造函数调用
//有参构造函数调用
//拷贝构造函数调用
//operator=函数调用
//析构函数调用
//析构函数调用
//析构函数调用
//析构函数调用
//这里多了一个拷贝函数调用不知道为什么
//	*/
//	arr2 = arr;
//}
//int main()
//{
//	test();
//	return 0;
//}
#include<string>
class person
{
public:
	person()
	{
		;
	}
	person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
void printmyarr(Myarr<int>& arr)
{
	int i;
	if (arr.getsize() == 0)
	{
		cout << "打印失败，数组为空" << endl;
		return;
	}
	for (i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void printperson(Myarr<person>& arr)
{
	if (arr.getsize() == 0)
	{
		cout << "打印失败，数组为空" << endl;
		return;
	}
	int i;
	for (i = 0; i < arr.getsize(); i++)
	{
		cout << "姓名：" << arr[i].m_name << " " << "年龄：" << arr[i].m_age << endl;
	}
}
void test()
{
	//测试int 类型
	//Myarr<int>arr(10);
	//int i;
	//for (i = 0; i < 5; i++)
	//{
	//	/*arr[i] = i;*/
	//	arr.pushback(i);
	//}
	//cout << "arr数组的输出" << endl;
	//printmyarr(arr);
	//cout << "arr的容量为" << arr.getcapacity() << endl;
	//cout << "arr的大小为" << arr.getsize() << endl;
	//Myarr<int>arr1(arr);
	//cout << "arr1数组的输出" << endl;

	//printmyarr(arr1);
	//cout << "arr1的容量为" << arr1.getcapacity() << endl;
	//cout << "arr1的大小为" << arr1.getsize() << endl;
	//cout << "尾删后arr数组的输出" << endl;
	//arr1.del_back();
	//printmyarr(arr1);
	//cout << "尾删后arr的容量为" << arr1.getcapacity() << endl;
	//cout << "尾删后arr的大小为" << arr1.getsize() << endl;
	//测试自定义类型
	Myarr<person>arr(10);
	person p1("张三",18);
	person p2("李四", 19);
	person p3("王五", 20);
	person p4("赵六", 21);
	person p5("韩信", 23);
	arr.pushback(p1);
	arr.pushback(p2);
	arr.pushback(p3);
	arr.pushback(p4);
	arr.pushback(p5);
	printperson(arr);
}

int main()
{
	test();
	return 0;
}














