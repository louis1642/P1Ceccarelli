#ifndef _SORTER_H_
#define _SORTER_H_

#include <vector>
#include <string>

class Sorter
{
private:
	int size;
	std::vector<int> items;

protected:
	std::string name;

	void swap(std::vector<int> &a, int i, int j) const;

public:
	Sorter(std::vector<int> &items);
	virtual ~Sorter();

	void sortWithDescription();
	void printItems() const;
	void printItems(std::vector<int> items) const;
	void printDescription() const;

	int getSize() const;
	std::vector<int>& getItems();

	virtual void sort() = 0;
};

#endif