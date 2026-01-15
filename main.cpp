#include "FourierCalculator.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cerr << "Uzycie: " << argv[0] << " <typ 0|1|2> <N>\n";
        return 1;
    }

    int type = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);

    MathFunc* f = 0;

    if (type == 0) f = new StepFunc();
    else if (type == 1) f = new CosFunc(1);
    else if (type == 2) f = new SinFunc(2);

    if (!f)
    {
        std::cerr << "Zly typ funkcji (0,1,2)\n";
        return 1;
    }

    f->DFT(N);

    delete f;
    return 0;
}
