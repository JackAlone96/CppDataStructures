#pragma once
#include <string>

template <typename T>
class StaticArray
{
	T* m_array;
	size_t m_lenght;

public:

	StaticArray(size_t x)
	{
		m_lenght = x;

		m_array = new T[x];
	}

	~StaticArray()
	{
		delete[] m_array;
	}

	size_t Length() const
	{
		return m_lenght;
	}

	T GetAt(const int i) const
	{
		return m_array[i];
	}

	void SetAt(int i, T x)
	{
		m_array[i] = x;
	}

	T GetFirst() const
	{
		return m_array[0];
	}

	void SetFirst(T x)
	{
		m_array[0] = x;
	}

	T GetLast() const
	{
		return m_array[m_lenght - 1];
	}

	void SetLast(T x)
	{
		m_array[m_lenght - 1] = x;
	}

	std::string ToString()
	{
		std::string string = "(";

		for (int i = 0; i < m_lenght; i++)
		{
			string += std::to_string(m_array[i]);
			if (i != m_lenght - 1) string += ", ";
		}

		string += ")";

		return string;
	}

	// TODO Build(x) and Iterator Sequence
};