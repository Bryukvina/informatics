#include <iostream>

struct Student
{
    std::string Name;
    std::string Surname;
    Lesson *lessons;
};

struct Lesson
{
    std::string Title;
    Student *students;
};

int main()
{
    Student Sasha = {"Sasha", "Sev", new Lesson [3]};
    Student Masha = {"Masha", "Tar", new Lesson [2]};
    Student Pety = {"Pety", "Gor", new Lesson [4]};
    Student Isolda = {"Isolda", "Mora", new Lesson [5]};

    Lesson math = {"Math", new Student [3]};
    Lesson PE = {"PE", new Student [2]};
    Lesson informatics = {"informatics", new Student [3]};
    Lesson physics = {"physics", new Student [2]};
    Lesson english = {"english", new Student [4]};


    math.students = {&Sasha, &Pety, &Isolda};
    PE.students = {&Masha, &Isolda};
    informatics.students = {&Pety, &Sasha, &Isolda};
    physics.students = {&Pety, &Isolda};
    english.students = {&Sasha, &Masha, &Pety, &Isolda};


    Sasha.lessons  = {&math, &informatics, &english};
    Masha.lessons = {&PE, &english};
    Pety.lessons = {&math, &physics, &informatics, &english};
    Isolda.lessons = {&math, &PE, &informatics, &physics, &english};
}
