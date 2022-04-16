#pragma once
#include <iostream>
template<class T>

class AutoPtr
{
private:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
		std::cout << "AutoPtr defalut constructor" << std::endl;

	}
	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;
		if (m_ptr != nullptr) delete m_ptr;
	}
	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment" << std::endl;

		if (&a == this)
			return *this;
		if (m_ptr != nullptr) delete m_ptr;

		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}
};
