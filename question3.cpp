#include <iostream>
#include <valarray>

using namespace std;

double secArea(double theta, double radius) {
    return 0.5 * theta * pow(radius,2);
}

int main() {

    //papply lambda fonksiyonu. Theta degerini veriyoruz, bize sadece radius isteyen lambda function donduruyor.
    auto papply = [](double theta) {
        return [theta](double radius) {
            return secArea(theta, radius);
        };
    };

    auto areaCircle = papply(6.28);
    //Theta degerini sabitledik. areaCircle artik sadece radius degeri alan bir lambda fonksiyon

    auto val = areaCircle(3.0);// pi * 3 * 3 = 28.26

    cout << val << endl;
    return 0;
}
