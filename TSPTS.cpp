#include "TSPTS.h"

TSPTS::TSPTS(int Iteration,int Run,int TabuLength){
    iter = Iteration;
    run = Run;
    TabuL = TabuLength;
    

    srand(time(NULL));
}

void TSPTS::Initialize(){
    Best = 10000;
    tabuL = 0;
    header = NULL;
    alternation.clear();
    neighbor.clear();
    vector<int> temp;
    temp.clear();
    for(int i=0;i<size;i++){
        temp.push_back(i);
    }

    for(int i=0;i<size;i++){
        int pos = rand()%temp.size();
        alternation.push_back(temp[pos]);
        neighbor.push_back(temp[pos]);
        temp.erase(temp.begin()+pos);
    }
   
}

void TSPTS::TS(){
    ReadFile();
    
    //ofstream file("output.dat"); 
    for(int r=0;r<run;r++){
        Initialize();
       
        for(int i=0;i<iter;i++){
            neighbor = Transition(alternation);
            fit1 = Fitness(alternation);
            fit2 = Fitness(neighbor);
            Determination();
            ///file << i << " " << Best << endl;
        }
        cout << "Best: " << Best << endl;
        //file.close();
    }
}

vector<int> TSPTS::Transition(vector<int> arr){
    int pos1 = rand()%size;
    int pos2;
    int time=0;
    vector<int> tempArr = arr;

    while(true){
        
        pos2 = rand()%size;
        if(pos2==pos1)
            continue;
        
        time++;
        if(time>20)
            break;
        
        if (IsTabu(pos1,pos2))
            continue;
        
        break;
    }
    if(tabuL==TabuL)
        delTabu();       
    InsertTabu(pos1,pos2);

    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;

    return arr;
}

double TSPTS::Fitness(vector<int> arr){
    double sum = 0;
    int p1,p2;
    for(int i=0;i<size;i++){
        p1 = arr[i];
        p2 = arr[(i+1)%size];
        sum += Distance(p1,p2);
    }

    return sum;
}

void TSPTS::Determination(){
    if(fit2<fit1){
        if(fit2<Best)
            Best = fit2;
        alternation = neighbor;
    }

}

double TSPTS::Distance(int point1,int point2){
    double dis;
    dis = sqrt( pow(X[point1]-X[point2],2)+pow(Y[point1]-Y[point2],2) );
    return dis;
}

void TSPTS::ReadFile(){
    ifstream inputFile("input.txt");
    int temp,x,y;

    X.clear();
    Y.clear();

    while(inputFile>>temp>>x>>y){
        X.push_back(x);
        Y.push_back(y);
    }
    inputFile.close();

    size = X.size();
}

void TSPTS::InsertTabu(int pos1,int pos2){

    if(!header){
        header = new Node;
        header->pos1= pos1;
        header->pos2= pos2;
        header->next = NULL;
        current = header;
    }
    else{
        current->next = new Node;
        current = current->next;
        current->pos1= pos1;
        current->pos2= pos2;
        current->next = NULL;
    }
    tabuL++;
}

void TSPTS::print(){
    Node *temp = header;
    while(temp){        
        cout << temp->pos1 << endl;
        cout << temp->pos2 << endl;
        temp = temp->next;       
    }
}

void TSPTS::delTabu(){
    Node *temp = header;
    header = temp->next;
    delete temp;
    tabuL--;
}

bool TSPTS::IsTabu(int pos1,int pos2){
    bool res = false;
    Node *temp = header;
    while(temp){
        if(temp->pos1==pos1 && temp->pos2==pos2){
            res = true;
            break;
        }
        temp = temp->next;
    }
    return res;
}

