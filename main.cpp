#include <iostream>
#include <fstream> //for file
#include<limits>
#include<iomanip>
#include<stdlib.h>

using namespace std;

void addCourse();//a function declaration to add course

void viewCourse();//a function declaration to view course

void addStudent();//a function declaration to add student

void viewStudent();//a function declaration to view student

void searchStudent();//a function declaration to search student in a department

void findStudent();//a function declaration to find student

void searchCourse();//a function declaration to search course

void deleteCourse();//a function declaration to delete course

void deleteStudent();//a function declaration to delete student


struct Student { // a structure to hold students record

char ID[20];

char fullName[40];

int age;

char sex;

char department[60];

char email[50];

};

struct Course { // a structure to hold course record

char cID[20];

char title[50];

int creditHour;

};


int main()
{
    char choice; // a variable to hold choice of the user
     cout<<"___________________________________________________________________"<<endl;
     cout<<"___________WELCOME To Art Students Data Management system __________"<<endl;
     cout<<"_____________________________________________________________________"<<endl;

do{
    cout<<"   Press 1 to add course data"<<endl;
    cout<<"   Press 2 to view all course data"<<endl;
    cout<<"   Press 3 to add student data"<<endl;
    cout<<"   Press 4 to view all students data"<<endl;
    cout<<"   Press 5 to see students in a department"<<endl;
    cout<<"   Press 6 to search student"<<endl;
    cout<<"   press 7 to search a course"<<endl;
    cout<<"   press 8 to delete a course "<<endl;
    cout<<"   press 9 to delete a student "<<endl;
    cout<<"   press C to exit "<<endl;
    cin>> choice;
    switch(choice){
case '1':
    addCourse();
    break;
case '2':
    viewCourse();
    break;
case '3':
    addStudent();
    break;
case '4':
    viewStudent();
    break;
case '5':
    searchStudent();
    break;
case '6':
    findStudent();
    break;
case'7':
    searchCourse();
    break;
case '8':
    deleteCourse();
    break;
case'9':
    deleteStudent();
    break;
case 'c':
case'C':
    exit(0);
    break;
default:
    cout<<"You entered a wrong input!"<<endl;

    } 
    }while(choice!='c' && choice!='C');
return 0;

}

void addCourse(){
	system("CLS"); //cleares the screen
    int numCourse;
    struct Course courseList[100];
    fstream artStudents; // declaring an object file

    cout<< " How many courses do you want to add?\n";
    cin>> numCourse;
    for(int i=0;i<numCourse;i++){

            cout<<"enter the course number " << i+1 << "course ID" <<endl;
           cin>>courseList[i].cID;
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //to ignore the space between the inputs
            cout<< "enter the course number " << i+1 << " title " <<endl;
            cin.getline(courseList[i].title,40);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<< "enter the course number " << i+1 << " credit Hour "<<endl;
            cin>> courseList[i].creditHour;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
             artStudents.open("course.txt" , ios::app); // to open an output file named course.txt
             artStudents<<courseList[i].cID<<setw(20)<<courseList[i].title<<setw(30)<<courseList[i].creditHour<<endl;//to write the inputs to the opened file 
              artStudents.close();//to close the file
            cout<<"You have added the course sucsessfully!"<<endl;
    }

}
void viewCourse(){
	system("CLS");
    fstream artStudents;
    artStudents.open("course.txt", ios::in);//to open an input file
    if (artStudents.is_open()){
    string line;
    while(getline(artStudents, line)){//to read a line from the file opened by artstudents 
        cout<< line << endl;//displays the data in the file line by line
    }
    artStudents.close();
  }
}

void addStudent(){
	system("CLS");
    int numStudent;
    struct Student studentList[200];
    fstream artStudents;

    cout<< " How many students do you want to add?\n";
    cin>> numStudent;
    for(int i=0;i<numStudent;i++){
    		cout<<endl;
            cout<<"enter student " << i+1 << " ID" <<endl;
            cin>> studentList[i].ID;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<< "enter student " << i+1 << " full name " <<endl;
            cin.getline(studentList[i].fullName,40);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<< "enter student " << i+1 << " age "<<endl;
            cin>> studentList[i].age;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<<"enter student " << i+1 << " sex " <<endl;
            cin>>studentList[i].sex;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<< "enter student " << i+1 << " department " <<endl;
            cin.getline(studentList[i].department,60);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

             cout<< "enter student " << i+1 << " Email address " <<endl;
            cin.getline(studentList[i].email,50);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');


            artStudents.open("student.txt", ios::app); //to write at the end of the file

            artStudents<<studentList[i].ID <<setw(10)<< studentList[i].fullName<<setw(10)<< studentList[i].age<<setw(10)<<studentList[i].sex<<setw(10)<< studentList[i].department<<setw(10)<<studentList[i].email<<endl;

              artStudents.close();
              cout<<"You have entered a student succesfully :"<<endl;
    }

}
void viewStudent(){
	system("CLS");
    fstream artStudents;
    artStudents.open("student.txt", ios::in);
    if (artStudents.is_open()){ //checks if the file is open
    string line;
    while(getline(artStudents, line)){ 
        cout<< line << endl;
    }
    artStudents.close();
  }
}

    void searchStudent(){
    	system("CLS");
    string departmentX; //declaring a variable to hold the department name the user wants to search
    int counter=0;
    fstream artStudents;
 artStudents.open("student.txt", ios::in);
 cout<<"Enter the first word of the department to see the students in it:  ";
  cin>>departmentX;
 string line; //declaring a string variable to hold the line read by getline( )
 int offset;
    if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);// reads a line from the file created by artstudents object and save it to the variable line 
    if((offset = line.find( departmentX,0)) != string::npos){//checks if the department entered is found in the line
        cout<<"ID"<<"             "<<"FULL NAME"<<"                "<<"AGE"<<"              "<<"SEX"<<"             "<<"DEPARTMENT"<<"           "<<"EMAIL"<<endl;
        cout<< line << endl;
        counter++;
    }
    }

}
 if(counter==0){
    cout<<"No item is found"<<endl;
}
artStudents.close();


}



void findStudent(){
	system("CLS");
    string findStu;
    int counter=0;
    fstream artStudents;
 artStudents.open("student.txt", ios::in);
 cout<<"Enter the ID of the student you want to search:  ";
 cin>> findStu;//to recieve the student's ID
 string line;
 int offset;
    if (artStudents.is_open()){
    while(!artStudents.eof()){//iterating loop until the end of the file is reached
    getline(artStudents, line);
    if((offset = line.find( findStu,0)) != string::npos){//searches the students's ID in the line
        cout<<"ID"<<"             "<<"FULL NAME"<<"                "<<"AGE"<<"              "<<"SEX"<<"             "<<"DEPARTMENT"<<"           "<<"EMAIL"<<endl;
        cout<< line << endl;//displays the line which the student's ID is found on
        counter++;
    }
    }

}
 if(counter==0){
    cout<<"No item is found"<<endl;
}
artStudents.close();


}

void searchCourse(){
	system("CLS");
    string findID;
    int counter=0;
    fstream artStudents;
 artStudents.open("course.txt", ios::in);
 cout<<"Enter the ID of the course you want to search:  ";
 cin>>findID;
 string line;
 int offset;
    if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    if((offset = line.find( findID,0)) != string::npos){
        cout<<"ID"<<"           "<<"Title"<<"           "<<"credit hour"<<endl;
        cout<< line << endl;
        counter++;
    }
    }

}
 if(counter==0){
    cout<<"No item is found"<<endl;
}
artStudents.close();


}

void deleteCourse(){
	system("CLS");
    string deleteCID, line;
    int offset;
 cout<<"Enter the ID of the course you want to delete :  ";
 cin>> deleteCID;

 fstream artStudents;
 artStudents.open("course.txt" , ios::in);
 fstream temporary;//creates a temporary file
 temporary.open("tempo.txt" , ios::out);
if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    offset=((line.find( deleteCID,0)) != string::npos);
    if (offset==0){
            temporary << line << endl;
    }
    }
}

temporary.close();
artStudents.close();
remove("course.txt");//removes the previous file 
rename("tempo.txt","course.txt");//rename the temporary file to course.txt
}

void deleteStudent(){
	system("CLS");
    string deleteStu, line;
    int offset;
 cout<<"Enter the ID of the student you want to delete :  ";
 cin>> deleteStu;

 fstream artStudents;
 artStudents.open("student.txt" , ios::in);
 fstream temporary;
 temporary.open("tempo.txt" , ios::out);
if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    offset=((line.find( deleteStu,0)) != string::npos);
    if (offset==0){
            temporary << line << endl;
    }
    }
}

temporary.close();
artStudents.close();
remove("student.txt");
rename("tempo.txt","student.txt");
}


