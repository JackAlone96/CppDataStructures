#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> list = LinkedList<int>();
	
	list.InsertLast(100);

	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;

	list.InsertLast(500);

	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;

	list.InsertFirst(1);

	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;

	list.InsertAt(2, 0);

	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;

	list.RemoveFirst();

	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;

	list.RemoveLast();

	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;

	list.InsertAt(list.Lenght(), 1000);
	std::cout << list.ToString() << " / lenght: " << list.Lenght() << std::endl;
	std::cout << list.GetFirst() << " / " << list.GetLast() << std::endl;

	return 0;
}