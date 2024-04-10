#pragma once

#include "DynamicArray.h"
#include <string>

template <typename T>
class LinkedList
{
	struct Node
	{
		T element;
		Node* next;
	};

	size_t m_lenght;
	Node* m_head;
	Node* m_tail;

public:

	LinkedList()
	{
		m_lenght = 0;
		m_head = nullptr;
		m_tail = nullptr;
	}

	~LinkedList()
	{
		Clear();
	}

	size_t Lenght()
	{
		return m_lenght;
	}

	T GetAt(int i) const
	{
		Node* currentNode = m_head;

		for (int k = 1; k <= i; k++)
		{
			currentNode = currentNode->next;
		}

		return currentNode->element;
	}

	void SetAt(int i, T x)
	{
		Node* currentNode = m_head;

		for (int k = 1; k <= i; k++)
		{
			currentNode = currentNode->next;
		}

		currentNode->element = x;
	}

	T GetFirst() const
	{
		return m_head->element;
	}

	void SetFirst(T x)
	{
		m_head->element = x;
	}

	T GetLast() const
	{
		return m_tail->element;
	}

	void SetLast(T x)
	{
		m_tail->element = x;
	}

	void InsertAt(int i, T x)
	{
		if (i == 0)
		{
			InsertFirst(x);
			return;
		}

		if (i == m_lenght)
		{
			InsertLast(x);
			return;
		}

		Node* currentNode = m_head;

		for (int k = 1; k < i; k++)
		{
			currentNode = currentNode->next;
		}

		Node* newNode = new Node();
		newNode->element = x;
		newNode->next = currentNode->next;

		currentNode->next = newNode;

		m_lenght++;
	}

	void RemoveAt(int i)
	{
		if (i == 0)
		{
			RemoveFirst();
			return;
		}

		if (i == m_lenght)
		{
			RemoveLast();
			return;
		}

		Node* currentNode = m_head;

		for (int k = 1; k < i; k++)
		{
			currentNode = currentNode->next;
		}

		Node* nodeToDelete = currentNode->next;
		Node* nextNode = nodeToDelete->next;

		delete nodeToDelete;

		currentNode->next = nextNode;

		m_lenght--;
	}

	void InsertFirst(T x)
	{
		Node* newNode = new Node();
		newNode->element = x;
		newNode->next = m_head;

		m_head = newNode;

		m_lenght++;

		if (m_lenght == 1) m_tail = m_head;
	}

	void RemoveFirst()
	{
		Node* nextNode = m_head->next;
		delete m_head;
		m_head = nextNode;

		m_lenght--;

		if (m_lenght == 0) m_tail = nullptr;
	}

	void InsertLast(T x)
	{
		Node* newNode = new Node();
		newNode->element = x;
		
		if (m_tail)
		{
			m_tail->next = newNode;
		}

		m_tail = newNode;

		m_lenght++;

		if (m_lenght == 1) m_head = m_tail;
	}

	void RemoveLast()
	{
		Node* currentNode = m_head;

		for (int k = 1; k < m_lenght - 1; k++)
		{
			currentNode = currentNode->next;
		}

		delete currentNode->next;
		m_tail = currentNode;
		m_tail->next = nullptr;

		m_lenght--;

		if (m_lenght == 0) m_head = nullptr;
	}

	void Clear()
	{
		int nodesToDelete = m_lenght;
		for (int i = 0; i < nodesToDelete; i++)
		{
			RemoveFirst();
		}

		m_head = nullptr;
		m_tail = nullptr;
	}

	std::string ToString()
	{

		std::string string = "(";

		if (m_head)
		{
			Node* currentNode = m_head;
			string += std::to_string(currentNode->element);
			string += ", ";

			for (int k = 1; k < m_lenght; k++)
			{
				currentNode = currentNode->next;
				string += std::to_string(currentNode->element);

				if (k != m_lenght - 1) string += ", ";
			}
		}

		string += ")";

		return string;
	}
};