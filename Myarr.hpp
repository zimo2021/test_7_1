#pragma once
#include<iostream>
using namespace std;
#include<string>
template<class T>
class Myarr
{
public:
	//有参构造
	Myarr(int capacity)
	{
		//cout << "有参构造函数调用" << endl;
		m_capacity = capacity;
		Address = new T[this->m_capacity];
		m_size = 0;
	}
	//拷贝构造
	Myarr(Myarr& arr)
	{
	//	cout << "拷贝构造函数调用" << endl;

		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//深拷贝
		this->Address = new T[arr.m_capacity];
		//将数组中的元素拷贝过来
		for (int i = 0; i < this->m_capacity; i++)
		{
			this->Address[i] = arr.Address[i];
		}
	}
	//重载operator= 防止浅拷贝问题
	Myarr& operator=(const Myarr arr)
	{
		//判断原数组中是否有数据 如果有 删除
	//	cout << "operator=函数调用" << endl;

		if (this->Address != NULL)
		{
			delete[] this->Address;
			this->Address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//深拷贝
		this->Address = new T[arr.m_capacity];
		//将数组中的元素拷贝过来
		for (int i = 0; i < this->m_capacity; i++)
		{
			this->Address[i] = arr.Address[i];
		}
		return *this;
	}
	~Myarr()
	{
	//	cout << "析构函数调用" << endl;
		if (this->Address != NULL)
		{
			delete[] this->Address;
			this->Address = NULL;
		}
	}
	//尾插
	void pushback(T arr)
	{
		if (this->m_size == this->m_capacity)
		{
			cout << "容量已满" << endl;
			return;
		}
		this->Address[m_size] = arr;
		this->m_size++;
	}
	//尾删
	void del_back()
	{
		if (this->m_size == 0)
		{
			cout << "文件为空，删除失败" << endl;
			return;
		}
		this->m_size--;
	}
	//重置[] 让其可以获取任意数组中的第I个元素
	T& operator[](int index)
	{
		return this->Address[index];
	}
	//获取数组容量
	int getcapacity()
	{
		return this->m_capacity;
	}
	//获取数组大小
	int getsize()
	{
		return this->m_size;
	}
private:
	T* Address;//记录地址
	int m_capacity;//记录容量
	int m_size;//数组的大小
};

