#include <iostream>

using namespace std;

enum Term { Fall, Spring, Summer };

struct OzuCourse
{
    short int year;
    Term term;
    std::string course_name;
    std::string instructor;

    //Constructor:
    OzuCourse(short int year, Term term, string coursename, string instructor) : year(year), term(term), course_name(coursename), instructor(instructor){}

    //Copy assignment operator
    auto operator=(const OzuCourse& other){
        this->instructor = other.instructor;
        this->term = other.term;
        this->course_name = other.course_name;
        this->year = other.year;
        return this; //Kendisini returnluyoruz boylece a = b = c gibi uc OzuCourse un esitliği yazilirsa yine calisir.
    }

    //Operator overload that check equality
    bool operator==(const OzuCourse& other){
        return ((this->instructor == other.instructor) &&
                (this->term == other.term) &&
                (this->course_name == other.course_name) &&
                (this->year == other.year));
    }

};



int main() {
    OzuCourse kurs1 = OzuCourse{2000, Fall, "cs123", "Void Eren"};

    OzuCourse kurs2 = OzuCourse{1999, Summer, "cs456", "Blackstone"};

    cout << kurs2.instructor << endl; //Blackstone

    cout << (kurs1 == kurs2) << endl; //Esit degiller. 0 yazar

    kurs2 = kurs1; //Operatoru kullandik

    cout << (kurs1 == kurs2) << endl; //Ustte esitledik. Artik 1 yazar

    cout << kurs2.instructor << endl; //Void Eren



    return 0;
}
