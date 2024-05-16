#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

class student{
    int idnum;
    char name[50];
    int payment;
    int roomno;
    char date[50];
    char department[50];


public:
    //void calculate();
    void getdata();
    void showdata() const;
    void show_tabular() const;
    int getIDNum() const;
};

/*void student::calculate()
{
    per=(cpp+cloud_computing+drone+hpc+evs)/5.0;
    if(per>90){
        grade='A+';
    }
    else if(per>=80){
        grade='A';
    }
    else if(per>=70){
        grade='B';
    }
    else if(per>=60){
        grade='C';
    }
    else if(per>=50){
        grade='D';
    }
    else{
        grade='F';
    }
}*/
void student::getdata()
{
    cout<<"Enter ID:";
    cin>>idnum;

    cout<<"Enter Student's Name:";
    cin.ignore();
    cin.getline(name,50);

    cout<<"Enter Department:";
    //cin.ignore();
    cin.getline(department,50);

    cout<<"Enter Students Payment:";
    cin>>payment;
    cout<<"Enter Room No:";
    cin>>roomno;
    cout<<"Enter Payment Date:";
    cin.ignore();
    cin.getline(date,50);
    //calculate();
}

void student::showdata() const
{
    cout<<"\nID:"<<idnum;
    cout<<"\nDepartment:"<<department;
    cout<<"\nName:"<<name;
    cout<<"\nPaid:"<<payment;
    cout<<"\nRoom Number:"<<roomno;
    cout<<"\nPaymnet Date:"<<date;
    /*cout<<"\nhpc:"<<hpc;
    cout<<"\nevs:"<<evs;
    cout<<"\npercentage:"<<per;
    cout<<"\ngrade:"<<grade;*/
}

void student::show_tabular() const
{
    cout<<idnum<<setw(6)<<" "<<department<<setw(10)<<" "<<name<<setw(10)<<" "<<payment<<setw(10)<<" "<<roomno<<setw(10)<<" "<<date<<endl;
}

int student::getIDNum() const
{
    return idnum;
}

void SaveStudent();
void displayAll();
void Searchdisplay(int);
void modifyStudent(int);
void deleteStudent(int);
void DisplayClassResult();
void DisplayResult();

void write_Student()
{
    student st;
    ofstream outfile;
    outfile.open("student.dat",ios::binary|ios::app);

    st.getdata();

    outfile.write(reinterpret_cast<char *> (&st),sizeof(student));

    outfile.close();

    cout<<"\n\nStudent Record Has Been Created";

    cin.ignore();
    cin.get();
}

void displayAll()
{
    student st;
    ifstream inFile;

    inFile.open("student.dat",ios::binary);
    if(!inFile){
        cout<<"File can not open"<<endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\tDispaly All Record\n\n";

    while(inFile.read(reinterpret_cast<char *> (&st),sizeof(student))){
        st.showdata();
        cout<<"\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void display_sp(int n){
    student st;
    ifstream inFile;

    inFile.open("student.dat",ios::binary);

    if(!inFile){
        cout<<"File can not open"<<endl;
        cin.ignore();
        cin.get();
        return;
    }

    bool flag = false;

    while(inFile.read(reinterpret_cast<char *> (&st),sizeof(student))){
        if(st.getIDNum()==n){
            st.showdata();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false){
        cout<<"Record doesn't exist";
    }
    cin.ignore();
    cin.get();

}

void modifyStudent(int n){
    bool found = false;
    student st;
    fstream File;

    File.open("student.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File can not open"<<endl;
        cin.ignore();
        cin.get();
        return;
    }

    while(!File.eof()&&found==false){
        File.read(reinterpret_cast<char *> (&st),sizeof(student));
        if(st.getIDNum()==n){
            st.showdata();
            cout<<"Enter The New Details"<<endl;
            st.getdata();
            int pos=(-1)*static_cast<int>(sizeof(st));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&st),sizeof(student));
            cout<<"Record Updated"<<endl;
            found=true;
        }
    }
    File.close();
    if(found==false){
        cout<<"Record Not Found";
    }
    cin.ignore();
    cin.get();

}

void deleteStudent(int n){
    student st;
    ifstream inFile;

    inFile.open("student.dat",ios::binary);
    if(!inFile){
        cout<<"File can not open"<<endl;
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat",ios::out);

    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&st),sizeof(student))){
        if(st.getIDNum()!=n){
            outFile.write(reinterpret_cast<char *> (&st),sizeof(student));
        }
    }

    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"Record Deleted";
    cin.ignore();
    cin.get();
}

void DisplayClassResult(){
    student st;
    ifstream inFile;

    inFile.open("student.dat",ios::binary);

    if(!inFile){
        cout<<"File can not open"<<endl;
        cin.ignore();
        cin.get();
        return;
    }

    cout<<"\n\nSTUDENT'S RESULT\n\n";
    cout<<"===============================\n\n";

    cout<<"ID         Department        Name          Payment       RoomNo        Date"<<endl;

    cout<<"==================================================================================="<<endl;

    while(inFile.read(reinterpret_cast<char *> (&st),sizeof(student))){
        st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();

}


int main()
{
    char ch;
    int num;
    cout.setf(ios::fixed|ios::showpoint);
    cout<<setprecision(2);

    do{
        cout<<"\n\n";
        cout<<"MEAL MANAGEMENT SYSTEM";
        cout<<"\n\n\t==================================\n";
        cout<<"\n\n\t\t\t1.CREATE STUDENT RECORD";
        cout<<"\n\n\t\t\t2.DISPLAY ALL STUDENT'S PAYMENT";
        cout<<"\n\n\t\t\t3.SEARCH STUDENT'S PREVIOUSLY PAID RECORD";
        cout<<"\n\n\t\t\t4.MODIFY STUDENT RECORD";
        cout<<"\n\n\t\t\t5.DELETE STUDENT RECORD";
        cout<<"\n\n\t\t\t6.DISPLAY CLASS RESULT";
        cout<<"\n\n\t\t\t7.EXIT";
        cout<<"\n\n\t==========================================\n";
        cout<<"\n\n\tPlease Enter a Choice(1-7):";
        cin>>ch;

        switch(ch){
            case '1':write_Student(); break;
            case '2':displayAll();break;
            case '3':cout<<"\n\n\tEnter student Id:";cin>>num;display_sp(num);break;
            case '4':cout<<"\n\n\tEnter student Id:";cin>>num;modifyStudent(num);break;
            case '5':cout<<"\n\n\tEnter student Id:";cin>>num;deleteStudent(num);break;
            case '6':DisplayClassResult();break;
            case '7':exit(0);

            default:cout<<"\a";
        }
    }
    while(ch!='7');

    return 0;
}



