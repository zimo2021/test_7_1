#pragma once
#include<iostream>
using namespace std;
#include<string>
template<class T>
class Myarr
{
public:
	//�вι���
	Myarr(int capacity)
	{
		//cout << "�вι��캯������" << endl;
		m_capacity = capacity;
		Address = new T[this->m_capacity];
		m_size = 0;
	}
	//��������
	Myarr(Myarr& arr)
	{
	//	cout << "�������캯������" << endl;

		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//���
		this->Address = new T[arr.m_capacity];
		//�������е�Ԫ�ؿ�������
		for (int i = 0; i < this->m_capacity; i++)
		{
			this->Address[i] = arr.Address[i];
		}
	}
	//����operator= ��ֹǳ��������
	Myarr& operator=(const Myarr arr)
	{
		//�ж�ԭ�������Ƿ������� ����� ɾ��
	//	cout << "operator=��������" << endl;

		if (this->Address != NULL)
		{
			delete[] this->Address;
			this->Address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//���
		this->Address = new T[arr.m_capacity];
		//�������е�Ԫ�ؿ�������
		for (int i = 0; i < this->m_capacity; i++)
		{
			this->Address[i] = arr.Address[i];
		}
		return *this;
	}
	~Myarr()
	{
	//	cout << "������������" << endl;
		if (this->Address != NULL)
		{
			delete[] this->Address;
			this->Address = NULL;
		}
	}
	//β��
	void pushback(T arr)
	{
		if (this->m_size == this->m_capacity)
		{
			cout << "��������" << endl;
			return;
		}
		this->Address[m_size] = arr;
		this->m_size++;
	}
	//βɾ
	void del_back()
	{
		if (this->m_size == 0)
		{
			cout << "�ļ�Ϊ�գ�ɾ��ʧ��" << endl;
			return;
		}
		this->m_size--;
	}
	//����[] ������Ի�ȡ���������еĵ�I��Ԫ��
	T& operator[](int index)
	{
		return this->Address[index];
	}
	//��ȡ��������
	int getcapacity()
	{
		return this->m_capacity;
	}
	//��ȡ�����С
	int getsize()
	{
		return this->m_size;
	}
private:
	T* Address;//��¼��ַ
	int m_capacity;//��¼����
	int m_size;//����Ĵ�С
};

