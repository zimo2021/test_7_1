#include<iostream>
using namespace std;
//��ģ���������������
//1.ָ����������
//2.����ģ�廯
//3.������ģ�廯
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
////void showperson(person<string, int>& p)//��һ��.ָ����������
////{
////	cout << " ������" << p.m_name << " ����: " << p.m_age << endl;
////}
////template<class T1,class T2>
////void showperson(person<T1, T2>& p)//����������ģ�廯
////{
////	cout << " ������" << p.m_name << " ����: " << p.m_age << endl;
////}
//template<class T >
//void showperson(T & p)//������������ģ�廯(��ϵͳ�Զ��Ƶ�p������)
//{
//	cout << " ������" << p.m_name << " ����: " << p.m_age << endl;
//	cout << "T������Ϊ��" << typeid(T).name() << endl;//T������Ϊ��class person<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int>
//	//string��ȫ���ܳ���class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
//	//��ס����鿴���͵ĺ���
//	//ע������������һ��ʹ�õ�һ�ַ��� �Ƚ����� ����
//}
//void test()
//{
//	person<string, int>p("����",18);
//	showperson(p);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//��ģ����̳�
//template<class T>
//class Father
//{
//public:
//	T m_a;
//};
//
////class son1 :public Father//���� û�д���Father��T������
////{
////
////};
//class son1 :public Father<int>//�����Ϳ��� �������������
//{
//public:
//
//};
////�Ƚ����Ĵ���
//template<class T1,class T2>
//class son2 :public Father<T1>
//{
//public:
//	son2()
//	{
//		cout << "T1������Ϊ��" << typeid(T1).name() << endl;//T1������Ϊ��int
//		cout << "T2������Ϊ��" << typeid(T2).name() << endl;//T2������Ϊ��int
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
//��ģ��ĳ�Ա����������ʵ��
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
//Father<T1,T2>::Father(T1 name, T2 age)//ע����Father�����<T1��T2>���߱�����Father��һ����ģ��
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//template<class T1, class T2>
//void Father<T1,T2>::showinfo()
//{
//	cout << " ������ " << this->m_name << " ���䣺 " << this->m_age << endl;
//}
//void test()
//{
//	Father<string, int>p("����", 18);
//	p.showinfo();
//}
//int main()
//{
//	test();
//	return 0;
//}
//��ģ��ķ��ļ���д
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
//#include"person.h"//����person.h  ���� ��Ϊ��ģ���г�Ա�������ڵ���ʱ������
//����취1 ֱ�Ӱ���Դ�ļ�
//#include"person.hpp"//���hpp�������Լ������ ������kppҲ��
//�������2����Դ�ļ���ͷ�ļ�д��һ���ļ��� �������Ǹ��ļ�

//template<class T1, class T2>
//Father<T1,T2>::Father(T1 name, T2 age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//template<class T1, class T2>
//void Father<T1,T2>::showinfo()
//{
//	cout << " ������ " << this->m_name << " ���䣺 " << this->m_age << endl;
//}
//void test()
//{
//	Father<string, int>p("����", 18);
//	p.showinfo();
//}
//int main()
//{
//	test();
//	return 0;
//}
//��ģ������Ԫ
//ȫ�ֺ�������ʵ��
//#include<string>
//template<class T1,class T2>
//class person;//��ǰ�ñ�����֪����һ����ģ��person����
//template<class T1,class T2>
//void showinfo1(person<T1,T2> p)
//{
//	cout << " ������ " << p.m_name << " ���䣺 " << p.m_age << endl;
//}
//#include<string>
//template<class T1,class T2>
//class person
//{
//	//ȫ�ֺ�������ʵ��
//	friend void showinfo1<>(person<T1, T2> p);//����м��<>һ��Ҫд ���߱�����showinfo1()������һ������ģ��
//	//ȫ�ֺ�������ʵ��
//	friend void showinfo(person<T1,T2> p)//������<T1,T2>��д�ɲ�д
//	{
//		cout << " ������ " << p.m_name << " ���䣺 " << p.m_age << endl;
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
//	person<string, int>p("����", 18);
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
//��ģ�尸������������ķ�װ

#include"Myarr.hpp"
//void test()
//{
//	Myarr<int>arr(5);//�вι��캯������ ������������
//	Myarr<int>arr1(arr);
//	/*
//�вι��캯������
//�������캯������
//������������
//������������
//	*/
//	Myarr<int>arr2(100);
//	/*
//�вι��캯������
//�������캯������
//�вι��캯������
//�������캯������
//operator=��������
//������������
//������������
//������������
//������������
//�������һ�������������ò�֪��Ϊʲô
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
		cout << "��ӡʧ�ܣ�����Ϊ��" << endl;
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
		cout << "��ӡʧ�ܣ�����Ϊ��" << endl;
		return;
	}
	int i;
	for (i = 0; i < arr.getsize(); i++)
	{
		cout << "������" << arr[i].m_name << " " << "���䣺" << arr[i].m_age << endl;
	}
}
void test()
{
	//����int ����
	//Myarr<int>arr(10);
	//int i;
	//for (i = 0; i < 5; i++)
	//{
	//	/*arr[i] = i;*/
	//	arr.pushback(i);
	//}
	//cout << "arr��������" << endl;
	//printmyarr(arr);
	//cout << "arr������Ϊ" << arr.getcapacity() << endl;
	//cout << "arr�Ĵ�СΪ" << arr.getsize() << endl;
	//Myarr<int>arr1(arr);
	//cout << "arr1��������" << endl;

	//printmyarr(arr1);
	//cout << "arr1������Ϊ" << arr1.getcapacity() << endl;
	//cout << "arr1�Ĵ�СΪ" << arr1.getsize() << endl;
	//cout << "βɾ��arr��������" << endl;
	//arr1.del_back();
	//printmyarr(arr1);
	//cout << "βɾ��arr������Ϊ" << arr1.getcapacity() << endl;
	//cout << "βɾ��arr�Ĵ�СΪ" << arr1.getsize() << endl;
	//�����Զ�������
	Myarr<person>arr(10);
	person p1("����",18);
	person p2("����", 19);
	person p3("����", 20);
	person p4("����", 21);
	person p5("����", 23);
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














