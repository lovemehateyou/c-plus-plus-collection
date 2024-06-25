#include <iostream>

using namespace std;

struct Student{
    int sID;
    string name;
    string email;
    int age;
    int phone_number;
    Student * next;
};
int count=0 ;

void insertion(Student * &head,int &count){
    Student * newnode = new Student;
    count++;
    if(newnode == nullptr){
        cout<< "MEMORY ALLOCATION FAILED"<<endl;
        return;
    }

    newnode->sID = count;
    cout<< "WHAT IS THE NAME OF THE STUDENT"<<endl;
    cin>>newnode->name;
    cout<<"WHAT IS THE EMAIL OF THE STUDENT"<<endl;
    cin>>newnode->email;
    cout<< "WHAT IS THE AGE OF THE STUDENT"<<endl;
    cin>>newnode->age;
    cout<< "WHAT IS THE PHONE NUMBER OF THE PARENTS "<<endl;
    cin>>newnode->phone_number;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        return;
    }

    else{
    Student*temp = head;
    while(temp != nullptr && temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;

    }
    cout<< "SUCCESSFULLY INTERED"<<endl;
 }

void delet(Student *&head,int target){
    Student *temp = head;
    Student *temp2 = nullptr;

    if(head == nullptr){
        cout<< "IT IS AN EMPTY LIST"<<endl;
    }
    else{
        while(temp!= nullptr && temp->sID != target) {
            temp2 = temp;
            temp = temp->next;
        }
        if(temp== nullptr){
            cout<< "there is no user with this id"<<endl;
        }
        else{
            if(temp2 == nullptr){
                head = temp->next;
            }
            else{
                temp2->next = temp->next;
            }
            delete temp;
        }


    }
}
void searching(Student * &head,int target){
    Student*temp = head;
    if(head == nullptr){
        cout<< "IT IS AN EMPTY LIST"<<endl;
    }
    else{
        while(temp!= nullptr && temp->sID != target) {
            temp = temp->next;
        }
        if(temp == nullptr){
            cout<< "there is no book with this id"<<endl;
        }
        else{
            cout<< "STUDENT ID: "<<temp->sID<<endl;
            cout<< "NAME: "<<temp->name<<endl;
            cout<< "AGE: "<<temp->age<<endl;
            cout<< "PHONE NUMBER: "<<temp->phone_number<<endl;
            cout<< "EMAIL: "<<temp->email<<endl;
        }
    }
}

void Update(Student * &head,int target){
    Student*temp = head;
    if(head == nullptr){
        cout<< "IT IS AN EMPTY LIST"<<endl;
    }
    else{
        while(temp!= nullptr && temp->sID != target) {
            temp = temp->next;
        }
        if(temp == nullptr){
            cout<< "there is no book with this id"<<endl;
        }
        else{
            cout<< "WHAT IS THE NEW NAME OF THE STUDENT"<<endl;
            cin>>temp->name;
            cout<<"WHO IS THE NEW EMAIL OF THE STUDENT"<<endl;
            cin>>temp->email;
            cout<< "WHAT IS NEW THE AGE OF THE STUDENT"<<endl;
            cin>>temp->age;
            cout<< "WHAT IS THE NEW PHONE NUMBER OF THE PARENTS "<<endl;
            cin>>temp->phone_number;

        }
    }
}
void display(Student *&head){

Student*temp = head;
if(head == nullptr){
    cout<< "the list is empty"<<endl;
}
else{
    while(temp != nullptr){
        cout<< "STUDENT ID: "<<temp->sID<<endl;
        cout<< "NAME: "<<temp->name<<endl;
        cout<< "AGE: "<<temp->age<<endl;
        cout<< "PHONE NUMBER: "<<temp->phone_number<<endl;
        cout<< "EMAIL: "<<temp->email<<endl;
        temp = temp->next;
    }

}

}
bool cont = true;
void exiit(){
string ans;
  cout<< "DO YOU WANT TO CONTINUE \n YES \n NO"<<endl;
  cout<< "OPTIONS: ";
  cin>> ans;
  if(ans == "yes"){
    cont = true;
  }
  else if(ans == "no"){
    cont = false;
  }
  else{
    cout<< "INVALID ANSWER"<<endl;
  }
}

int main()
{
Student * head = nullptr;
int choi;

    cout<< "WELCOME TO THE STUDENT MANAGING SYSTEM"<<endl;
    cout<< "======================================"<<endl;
cout<< "WHAT DO YOU WANT TO DO"<<endl;
do{
cout<< "1)INSERT A STUDENT \n 2)DELET A STUDENT \n 3)SEARCH A STUDENT \n 4)UPDATE THE RECORD OF A STUDENT \n 5)DISPLAY ALL THE STUDENTS"<<endl;
cout<< "OPTIONS: ";
cin>>choi;

if(choi == 1){
    insertion(head,count);
    exiit();
}
else if( choi == 2){
int tar;
cout<< "what is the ID OF THE STUDENT YOU WANT TO REMOVE"<<endl;
cin>>tar;
delet(head,tar);
exiit();
}
else if(choi == 3){
int ID;
cout<< "WHAT IS THE ID OF THE STUDENT: "<<endl;
cin>>ID;
searching(head,ID);
exiit();
}
else if (choi == 4){
int ID;
cout<< "WHAT IS THE ID OF THE STUDENT: "<<endl;
cin>>ID;
    searching(head,ID);
    exiit();
}
else if(choi == 5){
    display(head);
    exiit();
}
}while(cont == true);

}

