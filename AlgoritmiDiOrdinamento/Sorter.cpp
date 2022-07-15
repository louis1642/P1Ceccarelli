#include "Sorter.h"
#include <iostream>

Sorter::Sorter(std::vector<int> &items)
{
	this->items = items;
	this->size = items.size();
}

Sorter::~Sorter()
{
}

void Sorter::sortWithDescription()
{
	this->printDescription();
	this->printItems();

	std::cout << std::endl;

	this->sort();
}

void Sorter::printDescription() const
{
	std::cout << "Risoluzione con metodo " << this->name << ": " << std::endl;
}

int Sorter::getSize() const
{
	return this->size;
}

std::vector<int>& Sorter::getItems()
{
	return this->items;
}

void Sorter::printItems() const
{
	int size = this->size;

	std::cout << "[";

	for (int i = 0; i < size; i++)
	{
		std::cout << this->items.at(i);

		if (i < size - 1)
			std::cout << ", ";
	}

	std::cout << "]";
}

void Sorter::printItems(std::vector<int> items) const
{
	int size = items.size();

	std::cout << "[";

	for (int i = 0; i < size; i++)
	{
		std::cout << items.at(i);

		if (i < size - 1)
			std::cout << ", ";
	}

	std::cout << "]";
}

void Sorter::swap(std::vector<int> &a, int i, int j) const
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}