#include "sentence.h"
#include <vector>

class generation{
private :
    std::vector<sentence> population;
    std::vector<sentence> selectedParents;
    std::string target;
    int targetLen;
    int popCap;
    float mutationRate;

public :
    generation(std::string*, int, float);

    void generatePop(void);
    std::vector<sentence>::iterator giveBest(void);
    void naturalSelection(void);
    void replaceNextGen(void);
    std::string giveBestPerformer(void);
};