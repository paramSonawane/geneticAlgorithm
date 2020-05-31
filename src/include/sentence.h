#include <iostream>
#include <string>

class sentence{
// private:

public:
    std::string line;
    float fitness;
    
    sentence(std::string*);

    void generateString(int);
    float calcFitness(std::string*);
    char giveChar(void);
    void mutate(void);

    void printLine(void);
};