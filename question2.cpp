#include <iostream>

using namespace std;

template<typename T>
struct isSigned{
    static const bool value = true;
};

template<>
struct isSigned<unsigned int>{
    static const bool value = false;
};

template<>
struct isSigned<unsigned char>{
    static const bool value = false;
};

template<>
struct isSigned<unsigned short>{
    static const bool value = false;
};

template<>
struct isSigned<unsigned long>{
    static const bool value = false;
};

template<>
struct isSigned<unsigned long long>{
    static const bool value = false;
};

//Tum unsigned ihtimalleri special case olarak yazdim
//Hocanin istedigi bu mu bilmiyorum :D ama en kafisi bu gibi
//Obur turlu bi yontem anlatmadi hoca (benim hatirladigim yok yani)

int main() {
    cout << isSigned<int>::value << endl;
    cout << isSigned<unsigned int>::value << endl;
    cout << isSigned<float>::value << endl;
    cout << isSigned<unsigned char>::value << endl;
    cout << isSigned<double>::value << endl;
    cout << isSigned<unsigned long>::value << endl;
    return 0;
}
