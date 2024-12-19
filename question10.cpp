#include <iostream>
#include <vector>

using namespace std;

auto filter2(vector<int>& cont, auto func){

    vector<int> newcont = {};
    int szminone = cont.size() - 1;

    for(int i=0; i<szminone; i++){
        if(func(cont[i], cont[i+1])){
            newcont.push_back(cont[i]);
        }
    }
    if(func(cont[szminone], 0)){
        newcont.push_back(cont[szminone]);
    }
    return newcont;
}

auto print(vector<int>& vec){
    int i = 0;
    for(int item : vec){
        cout << "Index " << i << ": " << item << endl;
        i++;
    }
}

int main() {
    auto v1 = vector<int>{10, 5, 15, 25, 5, 10};
    auto v2 = vector<int>{10, -5, 15, -25, 5, -10};
    auto businessLogic = [](auto i1, auto i2) { return i1 > i2; };
    auto v1_filtered = filter2(v1, businessLogic);
    auto v2_filtered = filter2(v2, businessLogic);
    print(v1_filtered);
    print(v2_filtered);
    return 0;
}
