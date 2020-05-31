#include "include/sentence.h"
#ifndef iomanip
#include <iomanip>
#endif


sentence::sentence(std::string* target){
    generateString( (*target).length() );
    calcFitness(target);
    // printLine();
}

void sentence::generateString(int len){
    static int lineNo = 1;
    static const char validLetters[]=" .,!ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int totalLetters = sizeof(validLetters) - 1;

    srand( (unsigned)time(NULL) + lineNo );
    for(int i = 0; i < len; i++)
        line.push_back(validLetters[rand()%totalLetters]);

    lineNo++;
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