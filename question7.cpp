#include <iostream>
#include <valarray>

using namespace std;


// A: Global variables
// Global variables dedigi function disinda tanimli variablelar. Function bunlari kullanarak islemini yapacak.
int seq = 1;
int newseq = 1;
int temp = 0;

void FibonacciGlobal(){
    cout << newseq << endl;
    temp = newseq;
    newseq += seq;
    seq = temp;
}



// B: Function Object
class FibonacciObject{
public:
    int seq = 0;
    int newseq = 1;

    void operator()(){
        cout << newseq << endl;
        int temp = newseq;
        newseq += seq;
        seq = temp;
    }
};

int main() {

    //Global variable kullanan fonksiyon (A secenegi)
    FibonacciGlobal();
    FibonacciGlobal();
    FibonacciGlobal();
    FibonacciGlobal();
    FibonacciGlobal();
    FibonacciGlobal();
    FibonacciGlobal();

    cout << "-------------------" << endl;


    // B: Function Object
    FibonacciObject FibObj = FibonacciObject();
    FibObj();
    FibObj();
    FibObj();
    FibObj();
    FibObj();
    FibObj();
    FibObj();


    cout << "-------------------" << endl;


    // C: Lambda function
    auto FibonacciLambda = [seq = 1, newseq = 1]() mutable {
        cout << newseq << endl;
        int temp = newseq;
        newseq += seq;
        seq = temp;
    };

    FibonacciLambda();
    FibonacciLambda();
    FibonacciLambda();
    FibonacciLambda();
    FibonacciLambda();
    FibonacciLambda();
    FibonacciLambda();


    return 0;
}