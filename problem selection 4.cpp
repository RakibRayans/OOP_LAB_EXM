///Problem no 4
#include<bits/stdc++.h>
using namespace std;

class Person
{
  public:
  string name;
      Person(){};
      Person(string name)
      {
          this->name=name;

      }
      void viewPerson()
      {
          cout<<"Name:"<<this->name<<endl;
      }
      void getName()
      {
          cout<<this->name<<endl;
      }
};

class Department
{
public:
    string dpt_name;
    Department() {};
    Department(string name)
    {
        this->dpt_name=name;
    }
};

class Student : public Person
{
public:
    string id;
    Department department;
    int total_solve;
    string position;
    Student() {};
    Student(string name,Department dpt_name,string id_no,int total_solve,string position) : Person(name)
    {
        id=id_no;
        department=dpt_name;
        this->total_solve=total_solve;
        this->position=position;

    }
    viewProblemsetterinfo()
    {
        cout<<"Student name: "<<name<<endl;
        cout<<"Student ID: "<<id<<endl;
    }
    viewstudentinfo()
    {
        cout<<"Student name: "<<name<<endl;
        cout<<"Department: "<<department.dpt_name<<endl;
        cout<<"Student ID: "<<id<<endl;
        cout<<"Students total solve: "<<total_solve<<endl;
        cout<<"Students type: "<<position<<endl;
    }
    int getSolves()
    {
        return this->total_solve;
    }
    int isContestent()
    {
        if(position=="World Finalist")
        {
            return 1;
        }
        else
            return 0;
    }
};

class Judge : public Person
{
public:
    string tittle;
    Department department;
    Judge() {};
    Judge(string tittle,string name,Department department1):Person(name)
    {
        this->tittle=tittle;
        department=department1;
    }
    viewjudge()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department.dpt_name<<endl;
        cout<<"Tittle: "<<tittle<<endl;
    }
};

int main()
{
    Department dept("CSE");
    Student *student[5]=
    {
        new Student("Safran",dept,"11608010",233,"World Finalist"),
        new Student("Nabil",dept,"11608025",400,"Participant"),
        new Student("Rayans",dept,"11608035",300,"World Finalist"),
        new Student("Raihan",dept,"11608003",450,"World Finalist"),
        new Student("Asraf",dept,"11608016",275,"Participant")
    };
    cout<<".....Applicant Information....."<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"Student Information:"<<endl;
        student[i]->viewstudentinfo();
        cout<<endl;
        cout<<endl;
    }


    Judge *faculty_member[2]=
    {
        new Judge("Chairmen","Kamal Hossain Chowdhury",dept),
        new Judge("Assistant Professor","Mahmudul Hasan Raju",dept)

    };

    cout<<endl;
    cout<<"Judge Information: "<<endl;
    for(int i=0; i<2; i++){
        faculty_member[i]->viewjudge();

         cout<<endl;
    }

    for(int i=0;i<5;i++)
    {
        int solves=student[i]->getSolves();
        if(solves>=400 && (student[i]->isContestent()==1))
        {
           cout<<"No Of Problems Selected: "<<2<<endl;
           cout<<"Problem Setter info: "<<endl;
           student[i]->viewProblemsetterinfo();
        }
        else if(solves<400 && (student[i]->isContestent()==1))
        {
            cout<<"No Of Problems Selected: "<<1<<endl;
           cout<<"Problem Setter info: "<<endl;
           student[i]->viewProblemsetterinfo();
        }
        else if(solves>=300)
        {
            cout<<"No Of Problems Selected: "<<1<<endl;
           cout<<"Problem Setter info: "<<endl;
           student[i]->viewProblemsetterinfo();
        }

         cout<<endl;
    }

    return 0;
}

