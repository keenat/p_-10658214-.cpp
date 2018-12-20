#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
void Students();
void Courses();
void Workers();


struct Student
{
string name;
vector<string> Scourses;
int year;
int level;
};

struct Staff
{
    string name;
    string job;
    int year;
};

int main()
{

vector<Staff> workers;
vector<string> courses;
vector<Student> Stud;
vector<char> grades;
vector<string> coursesS;
courses.push_back("Academic Writing");
courses.push_back("Critical Thinking");
courses.push_back("Numeracy Skills");
courses.push_back("Animals As Friends");

        cout<<"                 WELCOME TO HILLIA SCHOOL MANAGEMENT SYSTEM             "<<endl;
        cout<<"========================================================================"<<endl;
        cout<<"Enter a record preferred"<<endl;
        cout<<"S for Student"<<endl;
        cout<<"W for Workers/Staff"<<endl;
        cout<<endl;
    char p;

        cin>>p;
        cout<<"========================================================================"<<endl;

     while(p!='q')
 {
     if(p=='S')
    {
    char opt;
        cout<<"What would you like to do?"<<endl;
        cout<<"A to add a record."<<endl;
        cout<<"E to edit an item in existing record."<<endl;
        cout<<"D to delete an item in the record."<<endl;
        cout<<"G to add grades to a Student's courses."<<endl;
        cout<<"P to print out a Student's Academic Record."<<endl;
        cin>>opt;
        cout<<"========================================================================"<<endl;


    if(opt=='A')
        {
     char response;
     string sname, sfname, slname;
     int syear;
     int slevel;
        cout<<"Enter the first name of the new student: ";
        cin>>sfname;
        cout<<endl;
        cout<<"Enter the last name of the new student: ";
        cin>>slname;
        cout<<endl;
             sname = sfname+" "+slname;
        cout<<"Enter the year of admission: ";
        cin>>syear;
        cout<<endl;
        cout<<"Enter the level of the student: ";
        cin>>slevel;
        cout<<endl;

    for(int i=0; i<courses.size(); i++)
    {
        cout<<i+1<<". "<<courses[i]<<endl;
    }
     int number;
        cout<<"Enter the position of the course you want to add the student to: ";
        cin>>number;
        cout<<endl;
            number=number-1;
            coursesS.push_back(courses[number]);
        cout<<"Do you want to add more courses?Input 'Y' for yes and 'N' for no: ";
        cin>>response;

    while(response=='Y')
                {
        cout<<"Enter the position of the course you want to add the student to: ";
        cin>>number;
        cout<<endl; //if condition
            number=number-1;
            coursesS.push_back(courses[number]);
        cout<<"Do you want to add more courses?Input 'Y' for yes and 'N' for no: ";
        cin>>response;
                }

            Student info={sname,coursesS,syear,slevel};
            Stud.push_back(info);
            cout<<Stud[0].name<<endl;

            for(int i=0; i<Stud.size(); i++)
            {
            cout<<i<<". "<<Stud[i].name<<"    L"<<Stud[i].level<<endl;
            }
        }
        else
        {

            //////////////////////////////////////////
        if(opt=='G')
            {
            int snumber;
        for(int i=0;i<Stud.size();i++)
            {
                    cout<<i<<". "<<Stud[i].name<<"    L"<<Stud[i].level<<endl;
            }
            cout<<"Enter the position of the Student whose grades you want to record: "<<endl;
            cin>>snumber;
            cout<<endl;

        if(Stud[snumber].Scourses.empty()==true)
            {
            cout<<"There are no courses available to this student."<<endl;
            }
        else
            {
          char g;
        for(int i=0;i<Stud[snumber].Scourses.size();i++)
                {
            cout<<"Enter the grades for "<<Stud[snumber].Scourses[i]<<":";
            cin>>g;
                grades.push_back(g);
            cout<<endl;
                }
                cout<<endl;

            }
            }
        else
            {
        if(opt=='P')
                {
            int no;
        for(int i=0;i<Stud.size();i++)
             {
            cout<<i<<". "<<Stud[i].name<<"  L"<<Stud[i].level<<endl;
             }
            cout<<"Enter the Student's number: "<<endl;
            cin>>no;
             ofstream outfile;
             outfile.open("Studentfile.txt");


             outfile<<"ID:00"<<no<<endl;
             outfile<<"Name: "<<Stud[no].name<<setw(20)<<"Year:L"<<Stud[no].level<<endl;
             outfile<<"Subject"<<setw(20)<<"Grade"<<endl;
             outfile<<"--------------------------------------------------------------------------------"<<endl;
        for(int i=0;i<Stud[0].Scourses.size();i++)
            {
                outfile<<Stud[0].Scourses[i]<<setw(20)<<grades[i]<<endl;
            }
             outfile<<"--------------------------------------------------------------------------------"<<endl;
             outfile.close();
                }
        else
                 {
        if(opt=='E')
                     {
            int input;
            string first,last,nam;
            int lvl;
            int yearr2;
            char reply;
        for(int i=1;i<Stud.size();i++)
            {
            cout<<i<<". "<<Stud[i].name<<"    L"<<Stud[i].level<<endl;
            }
            cout<<"Enter the position of the Student you want to edit: ";
            cin>>input;

            cout<<endl;
            cout<<"Enter the first name of the Student: ";
            cin>>first;
            cout<<endl;
            cout<<"Enter the last name of the Student: ";
            cin>>last;
            cout<<endl;

            nam=first+" "+last;
            cout<<"Enter the Year of Admission: ";
            cin>>yearr2;
            cout<<endl;
            cout<<"Enter the Level of the Student:";
            cin>>lvl;
            cout<<endl;
            for(int i=0;i<courses.size();i++)
                {cout<<i+1<<". "<<courses[i]<<endl;}
            int number;
            cout<<"Enter the position of the course you wish to add the student to: ";
            cin>>number;
            cout<<endl;
            number=number-1;
            coursesS.push_back(courses[number]);
            cout<<"Do you want to add more courses?Input 'Y' or 'y' for yes and 'N' or 'n' for no: ";
            cin>>reply;
        while(reply=='y'||reply=='Y')
                {
            cout<<"Enter the position of the course you wish to add the student to: ";
            cin>>number;
            cout<<endl; //if condition
                number=number-1;
                coursesS.push_back(courses[number]);
            cout<<"Do you want to add more courses?Input 'Y' or 'y' for yes and 'N' or 'n' for no: ";
            cin>>reply;
                }
            Stud[input].name=nam;
            Stud[input].year=yearr2;
            Stud[input].level=lvl;
        for(int i=0;i<Stud[input].Scourses.size();i++)
            {
                Stud[input].Scourses[i]=coursesS[i];
            }
                     }
        else
                     {
        if(opt=='D')
                         {
        for(int i=0;i<Stud.size();i++)
                {
            cout<<i<<". "<<Stud[i].name<<"  L"<<Stud[i].level<<endl;
            }
            int number;
            cout<<"Enter the number of the Student you want to delete: ";
            cin>>number;
            cout<<endl;
            Stud.erase(Stud.begin() + number);
                         }
                         else
                         {
                             cout<<"Invalid Input"<<endl;
                         }
                     }
                 }

            }
        }
    }
      else
      {
          char opt;
          if(opt=='W')
          {
               char opt;
        cout<<"What would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        cout<<":";
        cin>>opt;
        cout<<"========================================================================"<<endl;
              if(opt=='A')
{
char c;

    cin>>c;
      cout<<"What would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        char opt;
        cin>>opt;

    string namee,fname,lname;
           string jobb;
           int yearr;
             workers.push_back(Staff());
           cout<<"Enter the first name of the new Staff: ";
           cin>>fname;
           cout<<endl;
           cout<<"Enter the last name of the new Staff: ";
           cin>>lname;
           cout<<endl;
           namee=fname+" "+lname;
           cout<<"Enter the job of the new Staff: ";
           cin>>jobb;
           cout<<endl;
           cout<<"Enter the year of employment: ";
           cin>>yearr;
           cout<<endl;
           Staff info={namee,jobb,yearr};
           workers.push_back(info);
           for(int i=1;i<workers.size();i++)
           {
                cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
           }

}
else
{
    if(opt=='E')
    {
         int input;
            string first,last,nam;
            string jobb2;
            int yearr2;
            for(int i=1;i<workers.size();i++)
            {
                    cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
            }
            cout<<"Enter the position of the Staff you want to edit: ";
            cin>>input;

            cout<<endl;
            cout<<"Enter the first name of the Staff: ";
            cin>>first;
            cout<<endl;
            cout<<"Enter the last name of the Staff: ";
            cin>>last;
            cout<<endl;
            nam=first+" "+last;
            cout<<"Enter the Job: ";
            cin>>jobb2;
            cout<<endl;
            cout<<"Enter the Year of Employment: ";
            cin>>yearr2;
            cout<<endl;
            workers[input].name=nam;
            workers[input].job=jobb2;
            workers[input].year=yearr2;
            for(int i=1;i<workers.size();i++)
           {
               cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
           }

    }
    else
    {
        if(opt=='D')
    {
           for(int i=1;i<workers.size();i++)
            {
                    cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
            }
            int number;
            cout<<"Enter the number of the Staff you want to delete: ";
            cin>>number;
            cout<<endl;
            workers.erase(workers.begin() + number);
             for(int i=1;i<workers.size();i++)
           {
               cout<<i<<". "<<workers[i].name<<" "<<workers[i].job<<" "<<workers[i].year<<endl;
           }
    }
    else
    {
        cout<<"Invalid Input"<<endl;
    }
    }

}
          }
          else
          {
              if(opt=='C')
              {   char op;
                  cout<<"What would you like to do?"<<endl;
        cout<<"A or a to add to record."<<endl;
        cout<<"E or e to edit an item in existing record."<<endl;
        cout<<"D or d to delete an item in the record."<<endl;
        cout<<":";
        cin>>op;
        cout<<"========================================================================"<<endl;
        if(opt=='A')
{
    string input;
            cout<<"Enter the course you want to add:";
            cin>>input;
            courses.push_back(input);
            cout<<endl;
            cout<<"The new course list is: "<<endl;
        for(int i=0;i<courses.size();i++)
            {
                cout<<i+1<<". "<<courses[i]<<endl;
            }
}
        else
{
        if(opt=='E')
    {
            int input;
            string input2;
        for(int i=0;i<courses.size();i++)
                {
                    cout<<i+1<<". "<<courses[i]<<endl;
                }
            cout<<"Enter the position of the course you want to edit: ";
            cin>>input;
              input=input-1;
            cout<<endl;
            cout<<"Enter the name of the course you wish to replace "<<courses[input]<<" with:";
            cin>>input2;
            cout<<endl;
            courses[input]=input2;
               cout<<"The new course list is: "<<endl;
        for(int i=0;i<courses.size();i++)
            {
                cout<<i+1<<". "<<courses[i]<<endl;
            }
    }
        else
    {
        if(opt=='D')
        {
             for(int i=0;i<courses.size();i++)
                {
                    cout<<i+1<<". "<<courses[i]<<endl;
                }
                int number;
                cout<<"Enter the position of the course you want to delete: ";
                cin>>number;
                cout<<endl;
                number=number-1;
                courses.erase(courses.begin() + number);
            cout<<"The new course list is: "<<endl;
            for(int i=0;i<courses.size();i++)
            {
                cout<<i+1<<". "<<courses[i]<<endl;
            }
        }
        else
        {
            cout<<"Invalid Input."<<endl;
        }
    }
}
              }
          }
      }
      cout<<endl;
      cout<<"========================================================================"<<endl;
      cout<<"Enter a record you would like to work on."<<endl;
      cout<<"S for student"<<endl;
      cout<<"W for Workers/Staff"<<endl;
    char p;

      cin>>p;
      cout<<"========================================================================"<<endl;
}
      cout<<"Exiting..."<<endl;



        return 0;
}



