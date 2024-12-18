#include <iostream>
#include <vector>

using namespace std;


auto accumulate(string initial, auto& container, auto func){
    for(auto& item : container){
        initial = func(initial, item);
    }
    return initial;
}


int main() {
    auto v = vector<string>{"How", "do", "you", "do"};
    const auto s = accumulate("", v, [](string s1, string s2){return s1+s2;}) ;
    cout << s << endl; // prints Howdoyoudo

    return 0;
}
