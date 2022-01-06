/*OOPS CONCEPTS INCLUDED : CLASS AND OBJECTS ,ENCAPSULATION,DEFAULT AND PARAMETERIZED CONSTRUCTORS,DESTRUCTORS,STATIC DATAMEMBERS,
INHERTANCE,OPERATOR OVERLOADING,FRIEND FUNCTION,GRANTING ACCESS,VIRTUAL FUNCTIONS,RUNTIMETYPE IDENTIFICATION,VECTORS*/
#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class EMPLOYEE                                        //class and objects
{
    protected:
    int id,age;                                       //data hiding
    char name[20];
    public:
       static int co;                                //static data member
        EMPLOYEE()                                   //default constructors
        {
            co++;
        }
        int numobj(){return co;}
        virtual void display(){}                     //virtual function
        ~EMPLOYEE(){}                                //destructor
};
int EMPLOYEE::co;
class FULLTIME : public EMPLOYEE                      //inheritance
{
    private:
         int joindate;
         int basic,da,it;
    public:
       double insurancepremium;

        EMPLOYEE::age;                                  //granting access for base class member
        FULLTIME(int b,int d,int i)                    //parameterized constructors
        {
            basic=b;
            da=d;
            it=i;
        }
    void getdata()
    {
        cout<<"Enter the ID number of the employee : ";
        cin>>id;
        cout<<"Enter the name of the employee : ";
        cin>>name;
        cout<<"Enter the age of the employee : ";
        cin>>age;
        cout<<"Enter the join date of the employee : ";
        cin>>joindate;
        cout<<"Enter the insurance premium of the employee : ";
        cin>>insurancepremium;
        cout<<"\n";
    }
    void display()
    {
        cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<joindate<<"\t"<<basic<<"\t"<<da<<"\t"<<it<<"\t"<<insurancepremium<<endl;
    }
    int getage()
    {return age;}
     int netsalary()
     {
         return (basic+da)-it;
     }
     friend ostream&  operator<<(ostream& ,FULLTIME &f);           //friend function
};
ostream& operator<<(ostream& out,FULLTIME &f)                      //operator overloading
{
    out<<"Insurance premium for employees : ";
    return out;
}

class PARTTIME : public EMPLOYEE                                   //inheritance
{
    int joindate;
    int basic,da,it;
    public:
        EMPLOYEE::age;                                            //granting access for base class member
        double insurancepremium;
        PARTTIME(int b,int d,int i)                               //parameterized constructors
        {
            basic=b;
            da=d;
            it=i;
        }
    void getdata()
    {
        cout<<"Enter the ID number of the employee : ";
        cin>>id;
        cout<<"Enter the name of the employee : ";
        cin>>name;
        cout<<"Enter the age of the employee : ";
        cin>>age;
        cout<<"Enter the join date of the employee : ";
        cin>>joindate;
        cout<<"Enter the insurance premium : ";
        cin>>insurancepremium;
        cout<<"\n";
    }
    void display()
    {
        cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<joindate<<"\t"<<basic<<"\t"<<da<<"\t"<<it<<"\t"<<insurancepremium<<endl;
    }
    int getage()
    {return age;}
    int netsalary()
    {
        return (basic+da)-it;
    }
    friend ostream& operator<<(ostream& o,PARTTIME &p);                           //friend function

};
ostream& operator<<(ostream& o,PARTTIME &p)                                       //operator overloading
    {
        o<<"Insurance premium for part time employees : ";
         return o;
    }
int main()
{
    PARTTIME pt[5]={ PARTTIME(150000,300,200),PARTTIME(155000,400,300),PARTTIME(160000,600,400),PARTTIME(155600,320,200),PARTTIME(160020,300,100)};
    FULLTIME ft[5]={ FULLTIME(180000,500,400),FULLTIME(190000,700,500),FULLTIME(195050,602,321),FULLTIME(185000,300,100),FULLTIME(200000,900,800)};
    int ageft=0,agept=0,i;
    float avgft=0,avgpt=0;
    int netf,netfull=0,netp,netpart=0;
    cout<<"ENTER FULL TIME EMPLOYEES DETAILS : "<<endl<<"\n";
	for(i=0;i<5;i++)
        {
	      ft[i].getdata();
        }
    cout<<"\n-----FULL TIME EMPLOYEE DETAILS-----\n";
    cout<<"\nID\tNAME\tAGE\tJOINDATE BASIC\tDA\tIT\tINSURANCEPREMIUM\n"<<endl;
    for(i=0;i<5;i++)
    {
    ft[i].display();
    }
    for(i=0;i<5;i++)
    {
        ageft+=ft[i].getage();
    }

    avgft=ageft/5.0;
    cout<<"Average age of full time employees is "<<avgft<<"\n\n";
    for(i=0;i<5;i++)
    {
        netf= ft[i].netsalary();
        cout<<"Net salary of full time employee "<<i+1<<" is "<<netf<<"\n";
        netf=netf+netfull;
    }
    cout<<"\nNet salary of  all Full time employees : "<<netf<<"\n";
    double insft=0;
      for(i=0;i<5;i++)
    {
        insft=insft+ft[i].insurancepremium;
    }
    cout<<ft[5];
    cout<<insft<<endl;
    vector<int> v(5);                                                                          //vectors
    cout<<"Size of vector containing age of full time employees : "<<v.size()<<"\n";
    for(i=0;i<5;i++)
    {
        v[i]=ft[i].age;
    }
    cout<<"Age of full time employees : ";
    for(int i=0;i<5;i++)
    {
        cout<<v[i]<<"\t";
    }
    cout<<"\n";


    cout<<"\nENTER PART TIME EMPLOYEE DETAILS : "<<endl<<"\n";
	for(i=0;i<5;i++)
    {
	pt[i].getdata();
    }
    cout<<"\n----PART TIME EMPLOYEE DETAILS-----\n";
    cout<<"\nID\tNAME\tAGE\tJOINDATE BASIC\tDA\tIT\tINSURANCEPREMIUM\n"<<endl;
    for(i=0;i<5;i++)
    {
    pt[i].display();
    }
    for(i=0;i<5;i++)
    {
        agept+=pt[i].getage();
    }
    avgpt=agept/5.0;
    cout<<"\nAverage age of part time employees is : "<<avgpt<<endl;
    cout<<"\n";
    for(i=0;i<5;i++)
    {
        netp=pt[i].netsalary();
        cout<<"Net salary of part time employee  "<<i+1<<" is "<<netp<<"\n";
        netp=netp+netpart;
    }
     cout<<"\nNet salary of all part time employees : "<<netp<<"\n";
     double inspt=0;
      for(i=0;i<5;i++)
    {
        inspt=inspt+pt[i].insurancepremium;
    }
    cout<<pt[5];
    cout<<inspt<<endl;
   vector<int> ve(5);                                                                   //vector
    cout<<"Size of vector containing age of part time employees : "<<v.size()<<"\n";
    for(i=0;i<5;i++)
    {
        ve[i]=pt[i].age;
    }
    cout<<"Age of part time employees : ";
    for(int i=0;i<5;i++)
    {
        cout<<ve[i]<<"\t";
    }
     cout<<"\n\n";


   EMPLOYEE e;
     cout<<"The type of e is "<<typeid(e).name()<<endl;                                   //runtime type identification (rtti)
     cout<<"\nTotal number of objects created are : "<<e.numobj()<<"\n";
    return 0;
}
