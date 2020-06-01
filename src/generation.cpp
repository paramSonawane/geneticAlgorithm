#include "include/generation.h"

generation::generation(std::string *target, int popCap, float mutationRate){
    this -> target = *target;
    this -> targetLen = this -> target.length();
    this -> popCap = popCap;
    this -> mutationRate = mutationRate;
}

void generation::generatePop(void){
    for(int i = 0; i < popCap; population.push_back( *(new sentence(&target)) ), i++);
}

std::vector<sentence>::iterator generation::giveBest(void){
    float maxFit = 0.0;
    std::vector<sentence>::iterator maxIt;

    for(std::vector<sentence>::iterator it1 = population.begin(); it1 != population.end();  it1++)
        if(maxFit < (*it1).fitness){
            maxFit = (*it1).fitness;
            maxIt = it1;
        }

    return maxIt;
}

void generation::naturalSelection(void){
    float maxFit = (*giveBest()).fitness;

    selectedParents.clear();

    for(std::vector<sentence>::iterator it = population.begin(); it != population.end(); it++){
        int normFitness = ( (*it).fitness / maxFit) * 100;
        // std::cout << std::endl << "normFitness : " << normFitness;
        for(int i = 0; i < normFitness; selectedParents.push_back(*it), i++);
    }
}

void generation::replaceNextGen(void){
    std::cout << "The populations is : " << population.size() << std::endl;

    for(std::vector<sentence>::iterator it = population.begin(); it != population.end(); it++){
        std::cout << (*it).line << std::endl;

        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine randEng(seed);
        std::uniform_int_distribution<int> giveRandom(0, selectedParents.size());

        int parentA = giveRandom(randEng), parentB = giveRandom(randEng);
        (*it).line = selectedParents.at(parentA).crossover( &(selectedParents.at(parentB).line), mutationRate);
    }
}