#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Subject {
    string subjectName;
    int credit;
    float mark;
    char grade;
};

struct Student {
    string name;
    int age;
    Subject subjects[5];
    int subjectCount;
    float cpa;
};


char getGrade(float mark) {
    if (mark >= 85) return 'A';
    else if (mark >= 70) return 'B';
    else if (mark >= 55) return 'C';
    else if (mark >= 40) return 'D';
    else return 'F';
}


float calculateCPA(Subject subs[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += subs[i].mark;
    }
    return (count > 0) ? total / count : 0;
}


void inputSubject(Subject &s) {
    cout << "  Enter subject name (1 word): ";
    cin >> s.subjectName;

    cout << "  Enter credit hour: ";
    cin >> s.credit;

    do {
        cout << "  Enter mark (0 - 100): ";
        cin >> s.mark;
        if (s.mark < 0 || s.mark > 100) {
            cout << "  Invalid mark! Please re-enter.\n";
        }
    } while (s.mark < 0 || s.mark > 100);

    s.grade = getGrade(s.mark);
}

void inputStudent(Student &stu) {
    cout << "\nEnter student name (1 word): ";
    cin >> stu.name;

    cout << "Enter age: ";
    cin >> stu.age;

    cout << "Enter number of subjects (max 5): ";
    cin >> stu.subjectCount;

    for (int i = 0; i < stu.subjectCount; i++) {
        cout << "\nSubject " << i + 1 << " details:\n";
        inputSubject(stu.subjects[i]);
    }

    stu.cpa = calculateCPA(stu.subjects, stu.subjectCount);
}


void displayStudent(Student stu) {
    cout << "\n--------------------------------------\n";
    cout << "Name: " << stu.name << endl;
    cout << "Age: " << stu.age << endl;
    cout << "CPA: " << fixed << setprecision(2) << stu.cpa << endl;

    cout << "Subjects:\n";
    cout << left << setw(15) << "Subject"
         << setw(10) << "Credit"
         << setw(10) << "Mark"
         << "Grade" << endl;

    for (int i = 0; i < stu.subjectCount; i++) {
        cout << left << setw(15) << stu.subjects[i].subjectName
             << setw(10) << stu.subjects[i].credit
             << setw(10) << stu.subjects[i].mark
             << stu.subjects[i].grade << endl;
    }
}

int main() {
    Student students[10];
    int numStudent;

    cout << "Enter number of students (max 10): ";
    cin >> numStudent;

    for (int i = 0; i < numStudent; i++) {
        cout << "\n========== Student " << i + 1 << " ==========\n";
        inputStudent(students[i]);
    }

    cout << "\n========== All Students Information ==========\n";
    for (int i = 0; i < numStudent; i++) {
        displayStudent(students[i]);
    }

    return 0;
}