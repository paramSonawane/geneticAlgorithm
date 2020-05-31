#include "sentence.h"
#include <vector>

class generation{
private :
    std::vector<sentence> population;
    std::vector<sentence> selectedParents;
    std::string target;
    int targetLen;
    int popCap;

public :
    generation(std::string*, int);

    void generatePop(void);
    std::vector<sentence>::iterator giveBest(void);
    void naturalSelection(void);
};