#include <iostream>
#include <vector>
#include <typeinfo>


struct Lesson;
struct Student;

struct Student
{
    std::string Name;
    std::vector <Lesson*> lessons;
    void print();
};

struct Lesson
{
    std::string Title;
    std::vector <Student*> students;
    void print();
};

void Student::print(){
    int i;
    std::cout << "Name: " << Name << "; Lessons: ";
    for (i = 0; i < lessons.size(); i++){
        std::cout << lessons[i]->Title << " ";
    };
    std::cout << "\n";
};

void Lesson::print(){
    int i;
    std::cout << "Title: " << Title << "; Students: ";
    for (i = 0; i < students.size(); i++){
        std::cout << students[i] ->Name << " ";
    };
    std::cout << "\n";
};

void connect(Student &st, Lesson &ls){
    st.lessons.push_back(&ls);
    ls.students.push_back(&st);
};

int main()
{   
    Student Sasha = {"Sasha"};
    Student Masha = {"Masha"};
    Student Pety = {"Pety"};

    Lesson math = {"Math"};
    Lesson PE = {"PE"};
    Lesson informatics = {"Informatics"};


    connect(Sasha, math);
    connect(Masha, PE);
    connect(Pety, informatics);
    connect(Pety, math);
    connect(Sasha, informatics);

    Sasha.print();
    informatics.print();
    Pety.print();
    Masha.print();
    math.print();

    return 0;
}
