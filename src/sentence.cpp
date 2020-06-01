#include "include/sentence.h"

sentence::sentence(std::string* target){
    generateString( (*target).length() );
    calcFitness(target);
    // printLine();
}

char sentence::giveRandomChar(void){
    static const char validLetters[]=" .!ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int totalLetters = sizeof(validLetters) - 1;

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine randEng(seed);
    std::uniform_int_distribution<int> giveRandom(0, totalLetters);

    return validLetters[giveRandom(randEng)];
}

void sentence::generateString(int len){
    for(int i = 0; i < len; line.push_back(giveRandomChar()), i++);
}

float sentence::calcFitness(std::string* target){
    int matched = 0;
    for(std::string::iterator it1 = line.begin(), it2 = (*target).begin(); it1 != line.end(); it1++, it2++)
        if(*it1 == *it2)
            matched++;

    fitness =  float(matched) / (*target).length();
    return fitness;
}

void sentence::printLine(void){
    std::cout << line << " : " << std::fixed << std::setprecision(10) << fitness << std::endl;
}

std::string sentence::crossover(std::string* partner, float mutationRate){
    std::string child;

    // unsigned int midpoint = line.length()/2;

    for(unsigned int i = 0; i < line.length(); i++)
        child.push_back( (i%2 == 0 ? line[i] : (*partner)[i]) );

    mutate(&child, mutationRate);
    return child;
}

void sentence::mutate(std::string* child, float mutationRate){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine randEng(seed);
    std::uniform_real_distribution<double> giveRandom(0, 1);

    for(unsigned int i = 0; i < (*child).length(); i++)
        if(giveRandom(randEng) < mutationRate)
            (*child)[i] = giveRandomChar();
}