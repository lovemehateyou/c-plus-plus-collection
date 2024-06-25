#include <iostream>

using namespace std;
struct Books{
   string title;
   string author;
   string published_year;
   int ISBN;
   Books * next;
};

void insertion(Books * &head){
    Books * newnode = new Books;

    if(newnode == nullptr){
        cout<< "MEMORY ALLOCATION FAILED"<<endl;
        return;
    }

    cout<< "WHAT IS THE TITLE OF THE BOOK"<<endl;
    cin>>newnode->title;
    cout<<"WHO IS THE AUTHOR OF THE BOOK"<<endl;
    cin>>newnode->author;
    cout<< "WHAT IS THE PUBLISHING YEAR OF THE BOOK"<<endl;
    cin>>newnode->published_year;
    cout<< "WHAT IS THE ISBN OF THE BOOK"<<endl;
    cin>>newnode->ISBN;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        return;
    }

    else{
    Books*temp = head;
    while(temp != nullptr && temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;

    }
    cout<< "SUCCESSFULLY INTERED"<<endl;
 }

void delet(Books *&head,int target){
    Books *temp = head;
    Books *temp2 = nullptr;

    if(head == nullptr){
        cout<< "IT IS AN EMPTY LIST"<<endl;
    }
    else{
        while(temp!= nullptr && temp->ISBN != target) {
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
void searching(Books * &head,int target){
    Books*temp = head;
    if(head == nullptr){
        cout<< "IT IS AN EMPTY LIST"<<endl;
    }
    else{
        while(temp!= nullptr && temp->ISBN != target) {
            temp = temp->next;
        }
        if(temp == nullptr){
            cout<< "there is no book with this id"<<endl;
        }
        else{
            cout<<temp->title<<endl;
            cout<< temp->author<<endl;
            cout<< temp->published_year<<endl;
            cout<< temp->ISBN<<endl;

        }
    }
}

void searching(Books * &head,string target){
    Books*temp = head;
    if(head == nullptr){
        cout<< "IT IS AN EMPTY LIST"<<endl;
    }
    else{
        while(temp!= nullptr && temp->title != target) {
            temp = temp->next;
        }
        if(temp == nullptr){
            cout<< "there is no book with this id"<<endl;
        }
        else{
            cout<<temp->title<<endl;
            cout<< temp->author<<endl;
            cout<< temp->published_year<<endl;
            cout<< temp->ISBN<<endl;

        }
    }
}
void display(Books *&head){

Books*temp = head;
if(head == nullptr){
    cout<< "the list is empty"<<endl;
}
else{
    while(temp != nullptr){
        cout<< "TITLE: "<<temp->title<<endl;
        cout<< "AUTHOR: "<<temp->author<<endl;
        cout<< "PUBLISHED YEAR: "<<temp->published_year<<endl;
        cout<< "ISBN: "<<temp->ISBN<<endl;
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
Books * head = nullptr;
int choi;


cout<< "WHAT DO YOU WANT TO DO"<<endl;
do{
cout<< "1)INSERT A BOOK \n 2)DELET A BOOK \n 3)SEARCH A BOOK \n 4)DISPLAY ALL THE BOOKS"<<endl;
cout<< "OPTIONS: ";
cin>>choi;

if(choi == 1){
    insertion(head);
    exiit();
}
else if( choi == 2){
int tar;
cout<< "what is the ISBN OF THE BOOK YOU WANT TO REMOVE"<<endl;
cin>>tar;
delet(head,tar);
exiit();
}
else if(choi == 3){
cout<< "WITH WHAT DO YOU WANT TO SEARCH \n 1)ISBN \n 2)TITEL"<<endl;
cin>>choi;
if(choi ==1){
int ISBN;
cout<< "WHAT IS THE ISBN OF THE BOOK: "<<endl;
cin>>ISBN;
searching(head,ISBN);
exiit();
}
else{
string title ;
cout<< "WHAT IS THE TITLE OF THE BOOK: "<<endl;
cin>>title;
    searching(head,title);
    exiit();
}
}
else if(choi == 4){
    display(head);
    exiit();
}
}while(cont == true);

}
