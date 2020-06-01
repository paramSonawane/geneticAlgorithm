#include <iostream>
#include <iomanip>

#include <string>
#include <chrono>
#include <random>

class sentence{
// private:

public:
    std::string line;
    float fitness;

    sentence(std::string*);

    char giveRandomChar(void);
    void generateString(int);
    float calcFitness(std::string*);
    void mutate(void);
    std::string crossover(std::string*, float);
    void mutate(std::string*, float);

    void printLine(void);
};