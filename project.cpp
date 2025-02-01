#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // برای تنظیم عرض و دقت نمایش مقادیر

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
    void displayInfo() const {
        cout << "\nStudent Information:\n";
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Major: " << major << endl;
        cout << "Student ID: " << studentID << "\n";
    }

    // تابع محاسبه معدل
    double calculateGPA() const {
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

    // تابع نمایش کارنامه دانشجو
    void displayTranscript() const {
        double gpa = calculateGPA();
        
        // نمایش  کارنامه
        cout << "\n----------------------------\n";
        cout << "       Student Transcript\n";
        cout << "----------------------------\n";
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
        cout << "\nCourses:\n";
        cout << "---------------------------------\n";
        cout << "| Course Name        | Units | Grade |\n";
        cout << "---------------------------------\n";
        
        // نمایش دروس
        for (const auto& course : courses) {
            cout << "| " << left << setw(18) << course.courseName
                 << "| " << setw(5) << course.units
                 << "| " << setw(6) << course.grade << " |\n";
        }

        cout << "---------------------------------\n";
    }
};

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    vector<Student> students; // وکتور برای ذخیره دانشجویان

    // دریافت اطلاعات دانشجویان
    for (int i = 0; i < numStudents; i++) {
        Student s;  

        cout << "\nEnter information for student #" << i + 1 << ":\n";

        // دریافت اطلاعات دانشجو
        cout << "Enter first name: ";
        cin.ignore();  
        getline(cin, s.firstName);
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

        cin.ignore();

        for (int j = 0; j < numCourses; j++) {
            string cname;
            double cgrade;
            int cunits;

            cout << "\nEnter course name: ";
            getline(cin, cname); 

            cout << "Enter grade: ";
            while (!(cin >> cgrade) || cgrade < 0 || cgrade > 20) {
                cout << "Invalid grade! Enter again (0-20): ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
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

        students.push_back(s); 

        // نمایش کارنامه هر دانشجو بلافاصله بعد از وارد کردن اطلاعات دروس
        s.displayTranscript(); 
    }

    return 0;
}
