#pragma once

template <typename T>
class DynamicArray
{
	T* m_array;
	size_t m_lenght;
	size_t m_capacity;

public:

	DynamicArray()
	{
		m_lenght = 0;
		m_capacity = 1;
		m_array = new T[m_capacity];
	}

	DynamicArray(size_t capacity)
	{
		m_lenght = 0;
		m_capacity = capacity;
		m_array = new T[m_capacity];
	}

	~DynamicArray()
	{
		delete(m_array);
	}

	size_t Lenght()
	{
		return m_lenght;
	}

	size_t Capacity()
	{
		return m_capacity;
	}

	T GetAt(int i) const
	{
		m_array[i];
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

	void InsertAt(int i, T x)
	{
		if (m_lenght >= m_capacity)
		{
			m_capacity *= 2;

			T* tempArray = new T[m_capacity];

			for (int k = 0; k < m_lenght; k++)
			{
				tempArray[k] = m_array[k];
			}

			delete[] m_array;

			m_array = tempArray;
		}

		for (int k = m_lenght; k > 1; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		m_array[i] = x;

		m_lenght++;
	}

	void RemoveAt(int i)
	{
		for (int k = i; k < m_lenght; k++)
		{
			m_array[k] = m_array[k + 1];
		}

		m_lenght--;
	}

	void InsertLast(T x)
	{
		if (m_lenght >= m_capacity)
		{
			m_capacity *= 2;

			T* tempArray = new T[m_capacity];

			for (int k = 0; k < m_lenght; k++)
			{
				tempArray[k] = m_array[k];
			}

			delete[] m_array;

			m_array = tempArray;
		}

		m_array[m_lenght] = x;

		m_lenght++;
	}

	void RemoveLast()
	{
		m_lenght--;
	}

	void InsertFirst(T x)
	{	
		InsertAt(0, x);
	}

	void RemoveFirst()
	{
		RemoveAt(0);
	}

	void Clear()
	{
		m_lenght = 0;
	}
};