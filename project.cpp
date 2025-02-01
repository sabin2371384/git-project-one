#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string courseName;
    double grade;
    int units;
};

struct Student {
    string firstName;
    string lastName;
    string studentID;
    string major;
    vector<Course> courses ;
};
    void addCourse(string cname, double cgrade, int cunits) {
        courses.push_back({cname, cgrade, cunits});
    }

    // تابع نمایش اطلاعات دانشجو
    void displayInfo() {
        cout << "\nStudent Information:\n";
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Major: " << major << endl;
        cout << "Student ID: " << studentID << "\n";
    }
};

int main() {
    Student s;

    // دریافت اطلاعات دانشجو
    cout << "Enter first name: ";
    cin >> s.firstName;
    cout << "Enter last name: ";
    cin >> s.lastName;
    cout << "Enter student ID: ";
    cin >> s.studentID;
    cout << "Enter major: ";
    cin >> s.major;

    s.displayInfo();

    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;
    
    cin.ignore();

    for (int i = 0; i < numCourses; i++) {
        string cname;
        double cgrade;
        int cunits;

        cout << "\nEnter course name: ";
        getline(cin, cname); 

        cout << "Enter grade: ";
        cin >> cgrade;

        cout << "Enter units: ";
        cin >> cunits;
        cin.ignore();

        s.addCourse(cname, cgrade, cunits); 
    }

    // نمایش اطلاعات دروس دانشجو
    cout << "\nStudent Courses:\n";
    for (const auto &course : s.courses) {
        cout << "Course Name: " << course.courseName << ", Grade: " << course.grade << ", Units: " << course.units << endl;
    }

    return 0;
}
