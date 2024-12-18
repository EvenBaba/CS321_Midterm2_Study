#include <iostream>

using namespace std;

int main() {

    auto triangular = [index = 0,sum = 0]() mutable{
        index++;
        sum += index;
        return sum;
    };

    cout << triangular() << endl;// 1
    cout << triangular() << endl;// 1 + 2
    cout << triangular() << endl;// 1 + 2 + 3
    cout << triangular() << endl;// 1 + 2 + 3 + 4
    cout << triangular() << endl;// 1 + 2 + 3 + 4 + 5
    cout << triangular() << endl;// 1 + 2 + 3 + 4 + 5 + 6

    //Her cagirdiginda fonksiyon calisir ve lambda degerleri degisir.
    //index her seferinde bir artar ve sum a eklenir.
    //Bu Lazy Evaluation. Fonksiyonu her cagirdiginda adim adim ilerier.

    return 0;
}
