#include <iostream>
#include <vector>
#include <string>
#include <limits> // برای numeric_limits

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
    vector<Course> courses;

    // تابع افزودن درس
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

    // تابع نمایش اطلاعات دروس دانشجو
    void displayCourses() {
        cout << "\nStudent Courses:\n";
        for (const auto &course : courses) {
            cout << "Course Name: " << course.courseName 
                 << ", Grade: " << course.grade 
                 << ", Units: " << course.units << endl;
        }
    }

    // تابع محاسبه معدل
    double calculateGPA() {
        double totalPoints = 0;
        int totalUnits = 0;

        for (const auto &course : courses) {
            totalPoints += course.grade * course.units;
            totalUnits += course.units;
        }

        if (totalUnits == 0) {
            return 0; // در صورت نداشتن هیچ واحد درسی، معدل 0 برمی‌گردد.
        }

        return totalPoints / totalUnits;
    }
};

int main() {
    Student s;

    // دریافت اطلاعات دانشجو
    cout << "Enter first name: ";
    getline(cin, s.firstName); // استفاده از getline برای ورودی رشته با فضای خالی
    cout << "Enter last name: ";
    getline(cin, s.lastName);
    cout << "Enter student ID: ";
    getline(cin, s.studentID);
    cout << "Enter major: ";
    getline(cin, s.major);

    s.displayInfo();

    // دریافت تعداد دروس
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    cin.ignore(); // پاک کردن بافر ورودی برای استفاده از getline بعدی

    for (int i = 0; i < numCourses; i++) {
        string cname;
        double cgrade;
        int cunits;

        cout << "\nEnter course name: ";
        getline(cin, cname); 

        cout << "Enter grade: ";
        while (!(cin >> cgrade) || cgrade < 0 || cgrade > 20) {
            cout << "Invalid grade! Enter again (0-20): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // حذف داده‌های نامعتبر از بافر
        }

        cout << "Enter units: ";
        while (!(cin >> cunits) || cunits <= 0) {
            cout << "Invalid units! Enter again (must be positive): ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        cin.ignore();

        s.addCourse(cname, cgrade, cunits);
    }

    s.displayCourses();

    // محاسبه و نمایش معدل دانشجو
    double gpa = s.calculateGPA();
    cout << "\nGPA: " << gpa << endl;

    return 0;
}
