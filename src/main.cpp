#include "include/generation.h"

int main(){
    std::string target = "To be or not to be that is the question.";
    int popCap = 3000;
    float mutationRate = 0.01;
    bool finished = false;
    generation initGen(&target, popCap, mutationRate);
    initGen.generatePop();

    long genCount = 0;
    do{
        initGen.giveBest();
        initGen.naturalSelection();
        initGen.replaceNextGen();
        std::cout << " Generation : " << genCount;
        genCount++;
        finished = initGen.giveBestPerformer();
        // getchar();
    }while(!finished);

    return 0;
}
