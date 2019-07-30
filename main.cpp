#include "TSPTS.h"

int main(int argc,char** argv){
    int Iteration = atoi(argv[1]);
    int Run = atoi(argv[2]);
    int TabuLength = atoi(argv[3]);

    TSPTS ts(Iteration,Run,TabuLength);
    ts.TS();
    return 0;
}