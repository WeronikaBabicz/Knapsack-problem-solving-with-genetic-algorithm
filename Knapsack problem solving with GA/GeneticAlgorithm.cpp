#pragma once
#include "GeneticAlgorithm.h"
#include <iostream>


GeneticAlgorithm::GeneticAlgorithm()
{
	random_device rd;
	mt19937 generator(rd());
	gen = generator;
	populationSize = DEFAULT_POPULATION_SIZE;
	generationsNumber = DEFAULT_GENERATIONS;
	crossoverProbability = DEFAULT_CROSSOVER_PROB;
	mutationProbability = DEFAULT_MUTATION_PROB;
	knapsackProblem = nullptr;
}


GeneticAlgorithm::~GeneticAlgorithm()
{
	delete knapsackProblem;
}

void GeneticAlgorithm::vRun()
{
	generatePopulation();
	findAndSetBestIndividual();
	for (int i = 0; i < generationsNumber; i++)
	{
		vector <Individual*> newPopulation;
		uniform_int_distribution <> dis(0, population.size() - 1);

		while (newPopulation.size() < populationSize - 2)
		{
			int firstParentIndex = getBetterIndividualIndex(dis(gen), dis(gen));
			int secondParentIndex = getBetterIndividualIndex(dis(gen), dis(gen));

			vector <Individual*> childrenIndividuals = population.at(firstParentIndex)->crossover(*population.at(secondParentIndex), crossoverProbability);
			newPopulation.push_back(childrenIndividuals.at(0));
			newPopulation.push_back(childrenIndividuals.at(1));
		}
		Individual *bestForCurrentGeneration = new Individual();
		Individual *secondBestForCurrentGeneration = new Individual();

		bestForCurrentGeneration->setGenotype(bestIndividual.getGenotype());
		secondBestForCurrentGeneration->setGenotype(secondBestIndividual.getGenotype());

		bestForCurrentGeneration->setKnapsachProblem(knapsackProblem);
		secondBestForCurrentGeneration->setKnapsachProblem(knapsackProblem);

		newPopulation.push_back(bestForCurrentGeneration);
		newPopulation.push_back(secondBestForCurrentGeneration);
		for (int j = 0; j < populationSize; j++)
		{
			newPopulation.at(j)->mutate(mutationProbability);
		}
		deletePopulation();

		population = newPopulation;
		findAndSetBestIndividual();
	}
	deletePopulation();
}

bool GeneticAlgorithm::setPopulationSize(int populationSize)
{
	if (populationSize > 1)
	{
		this->populationSize = populationSize;
		return true;
	}
	else return false;

}

bool GeneticAlgorithm::setCrossoverProb(double crossoverProbability)
{
	if (crossoverProbability >= 0 && crossoverProbability <= 1)
	{
		this->crossoverProbability = crossoverProbability;
		return true;
	}
	else return false;
}

bool GeneticAlgorithm::setMutationProb(double mutationProbability)
{
	if (mutationProbability >= 0 && mutationProbability <= 1)
	{
		this->mutationProbability = mutationProbability;
		return true;
	}
	else return false;
}

bool GeneticAlgorithm::setGenerations(int generationsNumber)
{
	if (generationsNumber > 0)
	{
		this->generationsNumber = generationsNumber;
		return true;
	}
	else return false;
}

bool GeneticAlgorithm::setKnapsackProblem(KnapsackProblem * knapsackProblem)
{
	if (knapsackProblem != nullptr)
	{
		this->knapsackProblem = knapsackProblem;
		return true;
	}
	else return false;
}

vector<int> GeneticAlgorithm::getBestIndividualGenotype()
{
	return bestIndividual.getGenotype();
}

vector<int> GeneticAlgorithm::getSecondBestIndividualGenotype()
{
	return secondBestIndividual.getGenotype();
}

void GeneticAlgorithm::deletePopulation()
{
	for (int i = 0; i < population.size(); i++)
	{
		delete population.at(i);
	}
}

int GeneticAlgorithm::getBetterIndividualIndex(int indexOfFirstIndividual, int indexOfSecondIndividual)
{
	if (population.at(indexOfFirstIndividual)->getFitness() < population.at(indexOfSecondIndividual)->getFitness())
	{
		return indexOfSecondIndividual;
	}
	else return indexOfFirstIndividual;
}

void GeneticAlgorithm::findAndSetBestIndividual()
{
	int bestDefaultIndividualIndex = 0;
	double bestDefaultIndividualFitness = population.at(bestDefaultIndividualIndex)->getFitness();
	for (int i = 0; i < populationSize; i++)
	{
		if (population.at(i)->getFitness() > bestDefaultIndividualFitness)
		{
			bestDefaultIndividualIndex = i;
			bestDefaultIndividualFitness = population.at(i)->getFitness();
		}
	}
	if (bestDefaultIndividualFitness > bestIndividual.getFitness())
	{
		secondBestIndividual = bestIndividual;
		bestIndividual = *population.at(bestDefaultIndividualIndex);
	}


	for (int i = 0; i < getBestIndividualGenotype().size(); i++)
	{
		cout << getBestIndividualGenotype().at(i);
	}
	cout << FITNESS << bestIndividual.getFitness();
	cout << SIZE << bestIndividual.getSize() << endl;

}

void GeneticAlgorithm::generatePopulation()
{
	uniform_int_distribution <> dis(0, 1);
	for (int i = 0; i < populationSize; i++)
	{
		Individual *newIndividual = new Individual();
		vector <int> genotype;
		for (int j = 0; j < knapsackProblem->getNumberOfItems(); j++)
		{
			genotype.push_back(dis(gen));
		}
		newIndividual->setGenotype(genotype);
		newIndividual->setKnapsachProblem(knapsackProblem);
		population.push_back(newIndividual);
	}
	if (population.at(0)->getFitness() > population.at(1)->getFitness())
	{
		bestIndividual = *population.at(0);
		secondBestIndividual = *population.at(1);
	}
	else
	{
		bestIndividual = *population.at(1);
		secondBestIndividual = *population.at(0);
	}


}


