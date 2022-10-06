#include <iostream>
#include <vector>

struct Lesson;
struct Student;

struct Student
{
    std::string Name;
    std::vector <Lesson*> lessons;

   // Lesson* lessons = new Lesson [10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

struct Lesson
{
    std::string Title;
    std::vector <Student*> students;

   // Student* students = new Student [10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

int main()
{   
    Student* Sasha = new Student {"Sasha"};
    Student* Masha = new Student {"Masha"};
    Student* Pety = new Student {"Pety"};

    Lesson math = {"Math"};
    Lesson PE = {"PE"};
    Lesson informatics = {"Informatics"};

    int i;
    Lesson* ar_of_les = new Lesson[3] {math, PE, informatics};
    Student* ar_of_stud = new Student[3] {*Sasha, *Masha, *Pety};

    for (i = 0; i < 3; i++) {
        Sasha->lessons.push_back(&(ar_of_les[i]));
        Masha->lessons.push_back(&(ar_of_les[i]));
        Pety->lessons.push_back(&(ar_of_les[i]));
    }
    
    
    std::cout << Pety->lessons[1]->Title << std::endl;
    

    return 0;
}
