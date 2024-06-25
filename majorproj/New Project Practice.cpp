#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

void EMS();
bool BreakOut(string);
void printdata(int);
void registerEmployees(string);
void viewEmployees(string);
void searchEmployees(string);
void editEmployees(string);

struct Employee{
        int ID;
        char name[20];
        char fname[20];
        char dob[15];
        char doh[15];
        unsigned int salary;
        char pnum[15];
        char adrs[20];
        char department[20];
        char email[40];
        char pos[50];
        char status[20];
        char sex;

    };

struct Login{
    string userName;
    string password;
};

Login login[3];

Employee *emp;
fstream infrofile, outofile, SizeoFile, openfile; // infrofile: is the stream of input from the file. outofile: opposite of infrofile. SizeoFile: is the stream for the file that holds just 1 number which will be the size of the array of structueres. 
bool decision; // Made to allow users to decide if they would like to continue with a function (i.e registering employees, updating, etc.) or not.
char choice; // Goes hand in hand with decision. Holds the choice of the user, "Y for Yes" and "N for No".
static int SIZE; // Holds the size of the 'emp' array.
int P; // Holds the ID for the Employees; is 1 less than the size of the array of structures that holds the Employee objects.
int usersinfo; // Holds the ID for the User that is logging on and using the Employee Management System.
string NumOfEmp;



// Login in Part of the Program.
int main()
{   
    

    login[0].userName= "TheCEO!";
    login[0].password= "The-Boss-91X";

    login[1].userName= "MoneyMaster";
    login[1].password= "herecomesthe$$$";

    login[2].userName= "TheCTO?";
    login[2].password= "Techguru32";

    string USER;
    string PASSWORD;

    cout << "\n\t\tWelcome to Halcast Employee Management System.\n"<<endl;
    cout<<"Login\n"<<endl;

    for (int i=1; i<=5; i++){
        cout<<"Username:\t";
        cin>>USER;
        cout<<"\n";
        cout<<"Password:\t";
        cin>>PASSWORD;

    // Account of the CEO. 
    usersinfo=0;
    if (USER==login[usersinfo].userName && PASSWORD==login[usersinfo].password){
        EMS();
        break;
    }

    // Account of the CTO.
    usersinfo=1;
    if (USER==login[usersinfo].userName && PASSWORD==login[usersinfo].password){
        EMS();
        break;
    }


    // Account of the CFO. 
    usersinfo=2;
    if (USER==login[usersinfo].userName && PASSWORD==login[usersinfo].password){
        EMS();
        break;
    }


    // Security mechanism. Try too many times and you get locked out.
    else if (i==5){
        cout<<"You have tried too many times and will be locked out"<<endl;
        break;
    }


    // Leniency for incorrect username or password entry. Lets you try again 5 times.
    else {
        cout<<"\nIncorrect Username or Password \nPlease try again \n\n";
    }    

    }


    
}


// Used to ask the user if they'd like to continue with what they're doing and if not to break out of the current function that they're in.
bool BreakOut(string Prompt = "Is there anything else you would like to do?\n[Y]Yes   [N]No")
{   
    decision=true;
    while(true)
    {
        cout<<Prompt<<endl;
        cin>>choice;
        if(choice=='N' || choice=='n'){
            decision=false;
            break;
        }
        else if(choice=='Y' || choice=='y')
            break;

        else
        cout<<"Invalid entry. Please try again"<<endl;
    }
    cout<<"\n\n";
        return decision;
}


// Used just to Print data, just to make the code a little shorter.
void printdata(int i)
{
    cout<< "ID = "<<emp[i].ID<<endl;
    cout<< "First name = "<<emp[i].name<<endl;
    cout<< "Father's name = "<<emp[i].fname<<endl;
    cout<< "Phone number = "<<emp[i].pnum<<endl;
    cout<< "Date of Birth = "<<emp[i].dob<<endl;
    cout<< "Date of Hire = "<<emp[i].doh<<endl;
    cout<< "Salary = "<<emp[i].salary<<"$"<<endl;
    cout<< "E-mail = "<<emp[i].email<<endl;
    cout<< "Position = "<<emp[i].pos<<endl;
    cout<< "Department = "<<emp[i].department<<endl;
    cout<< "Address = "<<emp[i].adrs<<endl;
    cout<<"Status = "<<emp[i].status<<endl;
    cout<< "Sex = "<<emp[i].sex<<endl;
    
    
}



// Main part of the Program.
void EMS()
{
    decision=true;
    NumOfEmp = "Num of Employees.dat";
    string NameOfEmpFile = "emplo.bin";

    SizeoFile.open(NumOfEmp, ios::in);
    if(SizeoFile.fail()){
        cerr<<"Failed to Open Size file"<<endl;
        exit(1);
    }
    SizeoFile>>SIZE;
    SizeoFile.close();

    emp = new Employee[SIZE];

    while(decision==true){
        char OPTION;
        cout<<"\nWhat would you like to do?\n\n";
        cout<<"[A] Add New Employee Records     [B] Edit Employee Records     [C] View Employee Records    [D] Search for Employees     [E] Exit"<<endl;
        cout<<"Option: ";
        cin>>OPTION;
        cout<<"\n";
        switch (OPTION)
        {
            case 'A':
            case 'a':
            {
                registerEmployees(NameOfEmpFile);
                decision= BreakOut();
                break;
            }

            case 'B':
            case 'b':
            {
                editEmployees(NameOfEmpFile);
                decision= BreakOut();
                break;
            }


            case 'C':
            case 'c':
            {
                viewEmployees(NameOfEmpFile);
                decision= BreakOut();
                break;
            }


            case 'D':
            case 'd':
            {
                searchEmployees(NameOfEmpFile);
                decision= BreakOut();
                break;
            }


            case 'E':
            case 'e':
            {
                decision=false;
                break;
            }

            default:
            {
                cout<<"Invlaid Input. Please try again\n"<<endl;
                break;
            }





        


        }

    }


    
    delete []emp;
    cout<<"\nHave a Great Day"<<endl;
}




void registerEmployees(string filename){
    decision=true;
    
    openfile.open(filename,ios::app | ios::binary);
    P=SIZE;
    if (openfile.is_open()){
        while(decision==true){
            SIZE++;
            emp = new Employee[SIZE];
                emp[P].ID=P;
                cout<<"ID: "<<emp[P].ID<<endl;
                cout<< "\nFirst Name\n";
                cout << "----------------------------\n";
                cin>>emp[P].name;

                cout<< "\nFather's Name\n";
                cout << "----------------------------\n";
                cin>>emp[P].fname;

                cout<< "\nPhone number\n";
                cout<< "--------------------------------------\n";
                cin.ignore();
                cin.getline(emp[P].pnum,15);

                cout<< "\nDate of Birth (mm/dd/yyyy)\n";
                cout << "----------------------------\n";
                cin>>emp[P].dob;

                cout<< "\nDate of Hire (mm/dd/yyyy)\n";
                cout << "----------------------------\n";
                cin>>emp[P].doh;

                cout<< "\nEmail\n";
                cout<< "-------------------------------\n";
                cin>> emp[P].email;

                cout<< "\nSalary (only numbers, no other characters)\n";
                cout<< "-------------------------------\n";
                while (true){
                    cin>> emp[P].salary;
                    if (emp[P].salary<0)
                        cout<<"Invalid entry. Salary can not be negative. Please re-enter salary: \n";
                    else if(emp[P].salary>2000000000)
                        cout<<"Invalid entry. Salary can not be so high. Please re-enter salary: \n";
                    else
                        break;
                }

                cout<< "\nPosition \n";
                cout << "----------------------------\n";
                cin.ignore();
                cin.getline(emp[P].pos,30);                    

                cout << "\nDepartment\n";
                cout<< "-------------------------------------\n";
                cin>>emp[P].department;

                cout<< "\nAddress\n";
                cout << "----------------------------\n";
                cin.ignore();
                cin.getline(emp[P].adrs,20);

                cout<<"\nStatus\n";
                cout << "----------------------------\n";
                cin.ignore();
                cin.getline(emp[P].status,20);

                cout<< "\nSex (M/F)\n";
                cout << "----------------------------\n";
                while (true){
                    cin>>emp[P].sex;
                    emp[P].sex=toupper(emp[P].sex);
                    if (emp[P].sex=='M' || emp[P].sex=='F'){
                        break;
                    }
                    else{
                        cout<<"Invalid entry. Sex can only be M(Male) or F(Female). Please re-enter a valid entry: \n";
                    }
                }


                openfile.write((char*)&emp[P],sizeof(Employee));
                cout<<"\n\nRegistration success\n"<<endl;

                cout<< "--------------------------------\n\n";
                
                
                P++;
                
                    
                decision= BreakOut("Would you like to add another Employee?\n[Y]Yes   [N]No");
        }
    }
    else{
        cerr<<"Failed to open Employee Files"<<endl;
        exit(1);
    }
    
    openfile.close();

    SizeoFile.open(NumOfEmp, ios::out);
    if(SizeoFile.fail()){
        cerr<<"Failed to Open Size file"<<endl;
        exit(1);
    }
    SizeoFile<<SIZE;
    SizeoFile.close();

    
}




void viewEmployees(string filename)
{
    
    int EID; 
    bool EmpFound=false;
    cout<< "ID: ";
    cin>>EID;
    cout<<"\n";

    infrofile.open(filename,ios::in | ios::binary);

    if(infrofile.is_open()){
        

    for(int i =0; i<SIZE; i++){
        while(infrofile.read((char*)&emp[i], sizeof(Employee))){
           if(EID == emp[i].ID){
                printdata(i);

                EmpFound=true;
                break;
           }
        }
    }
    if(!EmpFound){
        cout << "\nNo Employee record found with ID = "<<EID<<endl;
    }

    infrofile.close();
    }
    else
        cout<<"Error!"<<endl;

}



void editEmployees(string filename){
decision=true;
char value;
bool is_found = false;
int EID;
cout<<"ID: ";
cin>>EID;
cout<<"\n\n";

openfile.open(filename,ios::out|ios::in|ios::binary);
if(openfile.is_open()){
    while(decision==true){
    for(int b = 0; b<SIZE; b++){
        while(openfile.read((char*)&emp[b],sizeof(Employee))){
            if(EID == emp[b].ID){
                while(true){
                    printdata(b);
                cout<<"\n\nWhat would you like to change?"<<endl;
                cout<<"A. First Name\nB. Last Name\nC. Birth Date\nD. Address\nE. Phone Number\nF. Email\nG. Department\nH. Position\nI. Salary\nJ. Status\n";
                cin>>value;
                    if (value=='A'||value=='a'){
                        cout<<"\nCurrent Value: "<<emp[b].name<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].name;
                        break;
                    }

                    else if (value=='B'||value=='b'){
                        cout<<"\nCurrent Value: "<<emp[b].fname<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].fname;
                        break;
                    }
                    else if (value=='C'||value=='c'){
                        cout<<"\nCurrent Value: "<<emp[b].dob<<endl;
                        cout<<"Enter the new value in the format mm/dd/yyyy: ";
                        cin>>emp[b].dob;
                        break;
                    }
                    else if (value=='D'||value=='d'){
                        cout<<"\nCurrent Value: "<<emp[b].adrs<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].adrs;
                        break;
                    }
                    else if (value=='E'||value=='e'){
                        cout<<"\nCurrent Value: "<<emp[b].pnum<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].pnum;
                        break;
                    }
                    else if (value=='F'||value=='f'){
                        cout<<"\nCurrent Value: "<<emp[b].email<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].email;
                        break;
                    }
                    else if (value=='G'||value=='g'){
                        cout<<"\nCurrent Value: "<<emp[b].department<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].department;
                        break;
                    }
                    else if (value=='H'||value=='h'){
                        cout<<"\nCurrent Value: "<<emp[b].pos<<endl;
                        cout<<"Enter the new value (either Technology or Finance): ";
                        cin>>emp[b].pos;
                        break;
                    }
                    else if (value=='I'||value=='i'){
                        cout<<"\nCurrent Value: "<<emp[b].salary<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].salary;
                        break;
                    }
                    else if (value=='J'||value=='j'){
                        cout<<"\nCurrent Value: "<<emp[b].status<<endl;
                        cout<<"Enter the new value: ";
                        cin>>emp[b].status;
                        break;
                    }
                    else{
                        cout<<"Invalid choice. Please try again\n\n";
                    }

                }
                    int pos = sizeof(emp[b]);
                    openfile.seekp(-pos,ios::cur);
                    openfile.write((char*)&emp[b],sizeof(Employee));
                    cout<< "\nSuccessfully Updated\n"<<endl;
                    is_found = true;
                    break;
            }
        }

    }
    if(!is_found){
        cout<< "no match found!"<<endl;
    }
    BreakOut("Would you like to edit another employees records?\n[Y]Yes   [N]No");

    }
    openfile.close();
}

else{
    cout<< "error opening file"<<endl;
}

}



Employee Emp ;
void searchview() {
    cout<<"\n\n";
    cout << "ID = " << Emp.ID << endl;
    cout << "First name = " << Emp.name << endl;
    cout << "Father's name = " << Emp.fname << endl;
    cout << "Phone number = " << Emp.pnum << endl;
    cout << "Date of Birth = " << Emp.dob << endl;
    cout << "Date of Hire = " << Emp.doh << endl;
    cout << "Salary = " << Emp.salary << "$" << endl;
    cout << "E-mail = " << Emp.email << endl;
    cout << "Position = " << Emp.pos << endl;
    cout << "Department = " << Emp.department << endl;
    cout << "Address = " << Emp.adrs << endl;
    cout << "Sex = " << Emp.sex << endl;
    cout << "Status = " << Emp.status << endl;
    
}

char param;
char position[50];
char firstname[20];
char lastname[20];
char phno[15];
char addr[20];
char dep[20];
char stas[20];
char Sx;

void searchEmployees(string filename) {
    bool isfound=false;
    infrofile.open(filename, ios::in | ios::binary);
    if (infrofile.is_open()) {
        cout << " What parameters would you like to use to search for employees?" << endl;
        cout << "A.Position    B.First Name    C.Last Name    D.phone number   E.address    F.department    G.status    H.Sex" << endl;
        cin >> param;
        param = toupper(param);
        switch (param) {
            case 'A':
                cout << "Enter the position of the employee that you are searching for" << endl;
                cin >> position;
                for (char& s : position) {
                    s = toupper(s);
                }
            
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        for (char& s : Emp.pos) {
                            s = toupper(s);
                        }
                        if (strcmp(Emp.pos, position) == 0) {
                            searchview();
                            isfound=true;
                        }
                        
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                    }
            

                infrofile.close();
                break;
                case 'B':
                    cout << "Enter the first name of the employee that you are searching for" << endl;
                    cin >> firstname;
                    for (char& s : firstname) {
                        s = toupper(s);
                    }
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        for (char& s : Emp.name) {
                            s = toupper(s);
                        }
                        if (strcmp(Emp.name, firstname) == 0) {
                            searchview();
                            isfound=true;
                        }
                        
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                    }

                    
                    infrofile.close();
                    break;
               case 'C':
                    cout << "Enter the last name of the employee that you are searching for" << endl;
                    cin >> lastname;
                    for (char& s : lastname) {
                        s = toupper(s);
                    }
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        for (char& s : Emp.fname) {
                            s = toupper(s);
                        }
                        if (strcmp(Emp.fname, lastname) == 0) {
                            searchview();
                            isfound=true;
                        }
                        
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                    }


                    infrofile.close();
                    break;
                case 'D':
                    cout << "Enter the phone number name of the employee that you are searching for" << endl;
                    cin >> phno;
                    for (char& s : phno) {
                        s = toupper(s);
                    }
                    
                        while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                            for (char& s : Emp.pnum) {
                                s = toupper(s);
                            }
                            if (strcmp(Emp.pnum, phno) == 0) {
                                searchview();
                                isfound=true;
                            }
                            
                        }
                        if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                        }

                    
                    infrofile.close();
                    break;
                case 'E':
                    cout << "Enter the address name of the employee that you are searching for" << endl;
                    cin >> addr;
                    for (char& s : addr) {
                        s = toupper(s);
                    }
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        for (char& s : Emp.adrs) {
                            s = toupper(s);
                        }
                        if (strcmp(Emp.adrs, addr) == 0) {
                            searchview();
                            isfound=true;
                        }
                        
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                    }


                    infrofile.close();
                    break;
               case 'F':
                    cout << "Enter the departement name of the employee that you are searching for" << endl;
                    cin >> dep;
                    for (char& s : dep) {
                        s = toupper(s);
                    }
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        for (char& s : Emp.department) {
                            s = toupper(s);
                        }
                        if (strcmp(Emp.department, dep) == 0) {
                            searchview();
                            isfound=true;
                        }
                        
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                        }


                    infrofile.close();
                    break;
                case 'G':
                    cout << "Enter the status of the employee that you are searching for" << endl;
                    cin >> stas;
                    for (char& s : stas) {
                        s = toupper(s);
                    }
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        for (char& s : Emp.status) {
                            s = toupper(s);
                        }
                        if (strcmp(Emp.status, stas) == 0) {
                            searchview();
                            isfound=true;
                        }
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                    }


                    infrofile.close();
                    break;
               case 'H':
                    cout << "Enter the SEX of the employee that you are searching for" << endl;
                    cin >> Sx;

                    Sx = toupper(Sx);
                    while (infrofile.read((char*)(&Emp), sizeof(Employee))) {
                        Emp.sex = toupper(Emp.sex);
                        if (Emp.sex == Sx) {
                            searchview();
                            isfound=true;
                        }
                        
                    }
                    if(isfound==false){
                        cout<<"No Employee found with given details."<<endl;
                        }

                    infrofile.close();
                    break;
                default:
                    cout << "Wrong parameter!" << endl;
                    break;
            }
    }
    else {
        cout << "Error!" << endl;
    }
    
}
