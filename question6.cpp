#include <iostream>
#include <vector>

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

auto filter(const vector<OzuCourse>& cont, auto func){
    vector<OzuCourse> contnew = {};
    for(auto& item : cont){
        if(func(item)){
            contnew.push_back(item);
        }
    }
    return contnew;
}

auto transform(vector<OzuCourse> cont, auto func){//vektore & koymadik cunku ustunde degisiklik yapicaz. & koymadigimiz icin degisiklikler kopya bi vektorde olucak.
    for(auto& item : cont){
        item = func(item);
    }
    return cont;
}

auto termModifier(){
    return [](OzuCourse course){
        course.term = static_cast<Term>((course.term + 1) % 3);
        return course;
    };
}

int main() {

    //10 OzuCourse iceren vector tanimladik
    vector<OzuCourse> vec = {
            {2000, Fall, "cs123", "Blackstone"},
            {2010, Summer, "ee123", "Void Eren"},
            {1980, Summer, "me123", "MubarekSabahlar"},
            {1970, Spring, "cs201", "Berkay Sir"},
            {1987, Fall, "cs112", "Voit Eren"},
            {2002, Spring, "cs456", "Blackstone"},
            {2005, Fall, "cs789", "Gokalp"},
            {1976, Fall, "eng303", "Gokalp"},
            {2019, Summer, "dumen101", "MubarekSabahlar"},
            {2009, Spring, "dumen102", "Berkay Sir"},

    };

    //A sikkinin cvbi.
    //Filter a func olarak bool donduren lambda function verdim

    vector<OzuCourse> filtered_vec = filter(vec, [](const OzuCourse& course){return (course.term == Fall);});

    for(OzuCourse& item : filtered_vec){
        cout << item.year << ", " << item.term << ", " << item.instructor << ", " << item.course_name << endl;
    }
    //Fall, enum daki ilk deger oldugu icin int degeri 0. Ekranda fall kisminda 0 yazacak.


    cout << "--------------------" << endl;


    //B sikkinin cvbi
    //Bu sefer func yerine dogrudan lambda function yazmak yerine yukarda yazdigim lambda function donduren fonksiyonu kullandim.

    auto transformfunc = termModifier();//Lambda function
    vector<OzuCourse> transfomed_vec = transform(vec, transformfunc);

    for(int i=0; i<10; i++){
        cout << "term before transformation:" << vec[i].term << ", term after transformation:" << transfomed_vec[i].term << endl;
        // 0=Fall, 1=Spring, 2=Summer
    }
    return 0;
}
