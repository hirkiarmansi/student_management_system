#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<fstream>
using namespace std;
void main_menu(void);
void admin(void);
void add_stdata(void);
void delete_stdata(void);
void view(void);
void password_verification(void);
void main_menu(){
    system("cls");
    cout<<"  LOGIN "<<endl;
    cout<<" 1. Admin "<<endl;
    cout<<" 2. Student "<<endl;
    cout<<" 3. Exit "<<endl;
}
void add_stdata(){
    system("cls");
    fstream file("data1.csv",ios::out| ios::app);
    if(!file){
        cout<<"\n Failed to open data1.csv file ";
    }
    else{
        cout<<" Enter the data "<<endl;
        string name,college,percentage,branch,rollno;
        cout<<"\nEnter Student's roll number : ";
        cin>>rollno;
        file<<rollno<<" , ";
        cout<<"Enter Student's name : ";
        cin>>name;
        file<<name<<" , ";
        cout<<"Enter college : ";
        cin>>college;
        file<<college<<" , ";
        cout<<"Enter Branch : ";
        cin>>branch;
        file<<branch<<" , ";
        cout<<"Enter percentage : ";
        cin>>percentage;
        file<<percentage;
        file.close();
        
        string choice;
        cout<<"Do you want to enter more data ? ";
        cin>>choice;
        if(choice=="Yes"||choice=="YES"||choice=="yes"){
            add_stdata();
        }
        else if(choice=="No"||choice=="NO"||choice=="no"){
            admin();
        }
        else{
            cout<<"INVALID OPTION! ";
            admin();
        }
    }
}
void del(){
    system("cls");
    ifstream inFile("data1.csv");
    if (!inFile)
    {
        cout << "Can't open file.";
        return;
    }
    ofstream outFile("datanew1.csv");
    if (!outFile)
    {
        cout << "Can't create new file.";
        return;
    }
    cout << "Enter Student Number you want to remove: ";
    string snum;
    cin >> snum;
    string rollno,name , branch , college, percentage;    
    bool found = false;
    while (inFile >> rollno >> name >>college >> branch >> percentage)
    {
        if (snum == rollno)
        {
            found = true;
        }
        else if (!(outFile << rollno << " " << name << " " <<college<< " " << branch << " " << percentage ))
        {
            cout << "Can't write to new file.";
            outFile.close();
            remove("datanew1.csv");
            return;
        }
    }   
    if (!inFile.eof())
    {
        cout << "Can't read information.";
        outFile.close();
        remove("datanew1.csv");
        return;
    }
    outFile.close();
    inFile.close();
    if (!found)
    {
        cout <<"Student Number not found.";
        remove("datanew1.csv");
        return;
    }

    if (rename("data1.csv", "Olddata1.csv") != 0)
    {
        cout <<"Can't backup old file.";
        remove("datanew1.csv");
        return;
    }

    if (rename("datanew1.csv", "data1.csv") != 0)
    {
        cout <<"Can't rename new file.";
        rename("Olddata1.csv", "data1.csv");
        return;
    }

    remove("Olddata1.csv");
    cout <<"Successfully Deleted.";
    admin();
}
void view(){
    system("cls");
    fstream file("data1.csv");
    if (!file)
    {
        cout << "fail in opening the file"<<endl;
    }
    cout<<"STUDENT RECORD"<<endl;
    cout<<"_________________________________________________________________________________"<<endl;
    cout<<"|Student Roll No|"<<setw(16)<<"Name|"<<setw(16)<<"College|"<<setw(16)<<"Branch|"<<setw(16)<<"Percentage|"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    string name,rollno,college,branch,percentage;
    while(!file.eof())
    {
        getline(file, rollno, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, percentage, '\n');
        cout<<"| "<<rollno<<"\t\t|"<<setw(15)<<name<<"|"<<setw(15)<<college<<"|"<<setw(15)<<branch<<"|"<<setw(15)<<percentage<<"|"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }
        cout<<endl;
    file.close();
    admin();
}
void admin(){
    
    char option;
label1: cout<<" LOGIN AS ADMIN "<<endl;
        cout<<" 1. Add Student Record "<<endl;
        cout<<" 2. Delete Student Record "<<endl;
        cout<<" 3. View Table "<<endl;
        cout<<" 4. Exit"<<endl;
        cout<<"Enter the option: ";
        cin>>option;
        switch (option)
        {
        case '1':{
            add_stdata();
            break;
        }
        case '2':{
            del();
            break;
        }
        case '3':{
            view();
            break;
        }
        case '4':{
            main_menu();
            break;
        }
        default:{
            cout<<"INVALID CHOICE!"<<endl;
            goto label1;
            break;
        }
        }
    
}
void password_verification(){
    string n;
    cout<<"Enter the password: ";
    do{
        cin>>n;
        if (n!="password"){
            cout<<"WRONG PASSWORD!"<<endl;
            cout<<"TRY AGAIN OR ENTER QUIT TO EXIT"<<endl;
            cout<<"Enter the password: ";
        }
        if (n=="QUIT"||n=="quit"||n=="Quit")
        {
            exit(0);
        }
    }
    while(n!="password");
    admin();
}
void student(){

}
int main(){
    main_menu();
main: char number;
cout<<"Enter the Choice: ";
cin>>number;
    switch(number){
        case '1':{
            password_verification();
        break;
        }
        case '2':{
            student();
            break;
        }
        case '3':{
            exit(0);
        }
        default:{
            cout<<"INVALID OPTION! ";
            main_menu();
            break;
        }

    }
}