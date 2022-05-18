#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class student
{
    int admno;
    char name[50];
    char addr[50];
    char divv[50];
    
    public:
        
        void setdata()
        {
            cout<<"\n\n";
            cout<<"\t\tEnter Roll Number of the Student : ";
            cin>>admno;
            cout<<"\n\t\tEnter Name of the Student : ";
            cin>>name;      
            cout<<"\n\t\tEnter the Division of the Student : ";
            cin>>divv;
            cout<<"\n\t\tEnter the Address of the Student : ";
            cin>>addr;
        }
        
        void showdata ()
        {
            cout<< "\n\t\t   *Student Roll No: "<<admno<<endl;
            cout<<"\t\t   *Student Name: "<<name<<endl;
            cout<<"\t\t   *Student Division: "<<divv<<endl;
            cout<<"\t\t   *Student Address: "<<addr<<endl;
        }
        
        int retadmno()
        {
            return admno;
        }
};

void write_record()
{
    ofstream outfile;
    outfile.open("student.data", ios::binary | ios::app);
    student obj;
    obj.setdata();
    outfile.write((char*)&obj, sizeof(obj));
    outfile.close();
}

void display()
{
    ifstream infile;
    infile.open("student.data", ios::binary );
    student obj;
    
    while(infile.read((char*)&obj, sizeof(obj)))
    {
        obj.showdata();
    }
    
    infile.close();
}

void search(int n)
{
    ifstream infile;
    infile.open("student.data", ios::binary);
    int flag = 0;
    student obj;
    
    while(infile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retadmno()==n)
        {
            obj.showdata();
            flag=1;
        break;
        }
    }
    
    if (flag==0)
    {
        cout<<"\nRecord not found "<<endl;
    }
    infile.close();
}

void delete_record(int n)
{
    student obj;
    ifstream infile;
    infile.open("student.data", ios::binary);
    ofstream outfile;
    outfile.open("temp.data", ios::out | ios::binary);
    
    while(infile.read((char*)&obj, sizeof(obj)))
    {
        if (obj.retadmno()!=n)
        {
            outfile.write((char*)&obj, sizeof(obj));
        }
    }
    
    infile.close(); 
    outfile.close();
    remove("student.data");
    rename("temp.data","student.data");
}

int main()
{
    int ch;
    do 
    {
        cout<<"\n****File Operations*** "<<endl;
        cout<<"\n1) Write \n2) Display \n3) Search \n4) Delete \n5) Exit "<<endl;
        cout<<"\n Enter your Choice : "; cin>>ch;
        
        switch(ch)
        {
            case 1:
                int n;
                cout<<"\n\tEnter number of records : ";cin>>n;
                for(int i=0; i<n; i++)
                {
                    write_record();
                }
            break;
            
            case 2:
                cout<<"\n\tList of records : "<<endl;
                display();
            break;
            
            case 3:
                int s;
                cout<<"\n\tEnter the Student's Roll Number you want to Search for : ";cin>>s;
                search(s);
            break;
            
            case 4:
                cout<<"\n\tEnter the Number to be Deleted : ";
                int d;
                cin>>d;
                delete_record(d);
            break;
            
            case 5:
                exit(1);
            
            default:
                cout<<"Wrong choice ";
            break;
            
        }
        
    }while(ch!=5);
    
return 0;
}