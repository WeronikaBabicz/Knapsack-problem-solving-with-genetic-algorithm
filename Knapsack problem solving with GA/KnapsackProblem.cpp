#include "KnapsackProblem.h"
#include <iostream>


KnapsackProblem::KnapsackProblem()
{
	capacity = DEFAULT_CAPACITY;
	itemsSizes = nullptr;
	itemsValues = nullptr;
}


KnapsackProblem::~KnapsackProblem()
{
	delete itemsSizes;
	delete itemsValues;
}

bool KnapsackProblem::setCapacity(double capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
		return true;
	}
	else return false;
}

bool KnapsackProblem::setItemsSizes(vector<double> *itemsSizes)
{
	if (itemsSizes != nullptr)
	{
		this->itemsSizes = itemsSizes;
		return true;
	}
	else return false;
}

bool KnapsackProblem::setItemsValues(vector<double> *itemsValues)
{
	if (itemsValues != nullptr)
	{
		this->itemsValues = itemsValues;
		return true;
	}
	else return false;
}

double KnapsackProblem::getFitness(vector<int> &genotype)
{
	double fitness = 0;
	double size = 0;
	for (int i = 0; i < genotype.size() && size <= capacity; i++)
	{

		if (genotype.at(i) == 1)
		{
			fitness += itemsValues->at(i);
			size += itemsSizes->at(i);
		}
	}
	sizeOfAllItems = size;
	return size <= capacity ? fitness : 0;
}

int KnapsackProblem::getNumberOfItems()
{
	return itemsSizes != nullptr ? itemsSizes->size() : 0;
}

double KnapsackProblem::getSizeOfAllItems()
{
	return sizeOfAllItems;
}
