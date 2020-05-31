#include "include/generation.h"

int main(){
    std::string target = "To be or not to be, thats not the question!.";
    int popCap = 1000;

    generation initGen(&target, popCap);

    initGen.generatePop();
    initGen.giveBest();
    initGen.naturalSelection();

    return 0;
}
