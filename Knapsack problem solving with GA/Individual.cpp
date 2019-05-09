#include "Individual.h"



Individual::Individual()
{
	random_device rd;
	mt19937 generator(rd());
	gen = generator;
	knapsackProblem = nullptr;
}


Individual::~Individual()
{
}

double Individual::getFitness()
{
	return knapsackProblem->getFitness(genotype);
}

double Individual::getSize()
{
	return knapsackProblem->getSizeOfAllItems();
}


void Individual::mutate(double mutationProbability)
{
	uniform_real_distribution<> dis(0, 1);
	for (int i = 0; i < genotype.size(); i++)
	{
		if (dis(gen) <= mutationProbability)
		{
			if (genotype.at(i) == 0) genotype.at(i) = 1;
			else genotype.at(i) = 0;
		}
	}
}

vector<Individual*> Individual::crossover(Individual individualOther, double crossoverProbability)
{
	uniform_int_distribution<> dis(1, genotype.size() - 1);
	uniform_real_distribution<> disreal(0, 1);
	vector <Individual*> pairOfIndividuals;
	Individual *newIndividual = new Individual();
	Individual *newIndividualOther = new Individual();
	if (disreal(gen) <= crossoverProbability)
	{
		int crossoverPoint = dis(gen);
		vector <int> firstGenotype;
		vector <int> secondGenotype;

		for (int i = 0; i < crossoverPoint; i++)
		{
			firstGenotype.push_back(genotype.at(i));
			secondGenotype.push_back(individualOther.genotype.at(i));
		}
		for (int i = crossoverPoint; i < genotype.size(); i++)
		{
			firstGenotype.push_back(individualOther.genotype.at(i));
			secondGenotype.push_back(genotype.at(i));
		}

		newIndividual->setGenotype(firstGenotype);
		newIndividual->setKnapsachProblem(knapsackProblem);

		newIndividualOther->setGenotype(secondGenotype);
		newIndividualOther->setKnapsachProblem(knapsackProblem);

		pairOfIndividuals.push_back(newIndividual);
		pairOfIndividuals.push_back(newIndividualOther);

	}
	else
	{
		newIndividual->setGenotype(getGenotype());
		newIndividual->setKnapsachProblem(knapsackProblem);

		newIndividualOther->setGenotype(individualOther.getGenotype());
		newIndividualOther->setKnapsachProblem(knapsackProblem);

		pairOfIndividuals.push_back(newIndividual);
		pairOfIndividuals.push_back(newIndividualOther);
	}
	return pairOfIndividuals;
}

void Individual::setGenotype(vector<int> genotype)
{
	this->genotype = genotype;
}

void Individual::setKnapsachProblem(KnapsackProblem * knapsackProblem)
{
	this->knapsackProblem = knapsackProblem;
}

