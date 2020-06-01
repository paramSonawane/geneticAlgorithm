#include "include/generation.h"

int main(){
    std::string target = "To be or not to be, thats not the question!.";
    int popCap = 1000;
    float mutationRate = 0.05;
    generation initGen(&target, popCap, mutationRate);

    initGen.generatePop();
    initGen.giveBest();
    initGen.naturalSelection();
    initGen.replaceNextGen();

    return 0;
}
