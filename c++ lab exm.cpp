/// problem no 02
#include<iostream>
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

class Author : public Person
{
    string City;
    string co_number;
public:
    Author(){};
    Author(string name,string co_number,string City): Person(name)
    {
        this->City=City;
        this->co_number = co_number;
    }
    void viewAuthor()
    {
        viewPerson();
        cout<<"Author city name:"<<this->City<<endl;
        cout<<"Author contact number:"<< this->co_number<<endl;
    }
    void getAuthorName()
    {
        cout<<"Author Name: "<<this->name<<endl;
    }

};

class Customer : public Person
{
    int customer_ID;
    string co_number;

public:
    Customer(){};
    Customer(string name,string co_number,int customer_ID):Person(name)
    {
        this->customer_ID=customer_ID;
        this->co_number = co_number;
    }

     void viewCustomer()
    {
        viewPerson();
        cout<<"Customer Id :"<<this->customer_ID<<endl;
        cout<<"Customer contact number:"<< this->co_number<<endl;

    }
};

class Salesman : public Person
{
    int salesman_ID;
    string co_number;
public:
    Salesman(){};
    Salesman(string name,string co_number,int salesman_ID) : Person(name)
    {

        this->salesman_ID=salesman_ID;
        this->co_number = co_number;
    }
    void viewSalesman()
    {
        viewPerson();
        cout<<"Salesman id no:"<<this->salesman_ID<<endl;
        cout<<" Salesman contact number:"<< this->co_number<<endl;
    }
};

class BookStore
{
    string name;
    int id;
public:
    BookStore(){};
    BookStore(string name,int id)
    {
        this->name=name;
        this->id=id;
    }
    void viewBookStore()
    {
        cout<<"Store Name:"<<this->name<<endl;
        cout<<"Store id :"<<this->id<<endl;
    }
};

class Category
{
    public:
    string name;

    Category(){};
    Category(string name)
    {
        this->name=name;
    }
    void viewCategory()
    {
        cout<<"Ctegory Name;"<<this->name<<endl;
    }
};

class Book
{
    string BookTitle;
    int price;
    int quantity;
    int serial_no;
    Author author;
    Category category;
public:

    Book(){};
    Book(string BookTitle,Author author,Category category,int price,int quantity,int serial_no)
    {
        this->BookTitle=BookTitle;
        this->price=price;
        this->quantity=quantity;
        this->serial_no=serial_no;
        this->author=author;
        this->category=category;
    }

    void viewBook()
    {
        cout<<"Book Tittle: "<<this->BookTitle<<endl;
        author.getAuthorName();
        cout<<"Category: "<<this->category.name<<endl;

        cout<<"Price of the Book: "<<this->price<<endl;
        cout<<"Quantity Of the Book: "<<this->quantity<<endl;
        cout<<"Serial No Of the Book: "<<this->serial_no<<endl;
    }
};


int main()
{
    int i;
    Category *category[3]=
    {
        new Category("Fiction"),
        new Category("non-fiction"),
        new Category ("Comics")
    };

    Customer *customer[3]=
    {
        new Customer("Akash","018344657283",1001),
        new Customer("Shakil","019646534",1002),
        new Customer("Anik","01734567890",1003)
    };
    Author *author[3]=
    {
        new Author("Jaffor Ikbal","01645678901","Shylet"),
        new Author("Robindronath","01765432876","Dhaka"),
        new Author("Shamsor Rahman","01987654876","Kurigram")
    };

    Book *book[3]=
    {
        new Book("Moyorakkhi",*author[0],*category[0],250,13,1001),
        new Book("Janina",*author[1],*category[1],270,16,1002),
        new Book("Sesher Kobita",*author[2],*category[2],240,18,1003)
    };
    cout<<".... Book Information....."<<endl;
    cout<<" "<<endl;


    cout<<".... Author Information....."<<endl;
    for(i=0;i<3;i++)
    {
        author[i]->viewAuthor();
        cout<< " "<<endl;
    }
    cout<<"   "<<endl;

    cout<<".... Book Information....."<<endl;
    for(i=0;i<3;i++)
    {

        book[i]->viewBook();
        cout<<endl;
    }
    cout<<"   "<<endl;

    int MonthlyFrequency[3]={3,0,4};

    cout<<"...Customer Has Discount..."<<endl;
    for(i=0;i<3;i++)
    {
        if(MonthlyFrequency[i]>=3)
        {
            customer[i]->viewCustomer();
        }
    }

};
