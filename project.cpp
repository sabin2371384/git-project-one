#include<iostream>
#include<vector>
#include<string> 
using namespace std;
struct course{
string coursename ;
double grade ;
int units ; 
};
void addcourse(string cname, double cgrade, int cunits)
{  course.push_back({cname,cgrade,cunits});

}
struct student{   
 string firstname;
 string lastname ;
 string studentID ;
 string major;
 vector<course>courses;
};
void displayInfo()
{    cout<<"\nstudent information:\n";
     cout <<"name ="<<firstname <<"   "<<lastname << endl ;
     cout <<"major="<< major <<endl ;
     cout<<"studentID ="<<studentID <<"\n";

}
int main(){
     student s;
     course c;
     cout<<"Enter first name :";
     cin>>s.firstname;
     cout<<"Enter last name:";
     cin>> s.last name;
     cout<<"Enter student ID :";
     cin>> s.studentID ;
     cout<<"Enter major :";
     cin>> s.major;

     s.displayInfo();
     int numcourses ;
     cout<<"Enter a number of courses=";
     cin>>numcourses ;
     for(int i=0;i<numcourses;i++)
     { string cname ;
      double cgrade ;
      int cunits ;
       cout<<"\nEnter course name :";
        getline(cin, cname);
        cout<<"Enter grade :";
        cin>>cgrade ;
        cout<<"Enter units :";
        cin>>cunits ;
        s.addcourse(cname,cgrade,cunits);
     }


}
