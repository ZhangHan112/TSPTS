#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct Node
{
    int pos1;
    int pos2;
    Node *next;
};


class TSPTS{
public:
    int iter;
    int run;

    double fit1;
    double fit2;
    double Best;
    int TabuL;
    int tabuL;
    int size;


    Node *header;
    Node *current;
    vector<int> alternation;
    vector<int> neighbor;
    vector<int> X;
    vector<int> Y;

    TSPTS(int Iteration,int Run,int TabuLength);
    void Initialize();
    void TS();
    vector<int> Transition(vector<int> arr);
    double Fitness(vector<int> arr);
    void Determination();
    double Distance(int point1,int point2);
    void ReadFile();
    void InsertTabu(int pos1,int pos2);
    void delTabu();
    bool IsTabu(int pos1,int pos2);
    void print();
    bool Aspiration(vector<int> arr,int pos1,int pos2);

};