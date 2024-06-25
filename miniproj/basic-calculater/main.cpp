#include <iostream>
#include<fstream>
#include<stdlib.h>


using namespace std;
int ADD(int num1 , int num2){
    cout<< num1 + num2<<endl;;
}

int SUB(int num1 , int num2){
    cout<< num1 - num2<<endl;
}

int MULT(int num1 , int num2){
    cout<< num1 * num2<<endl;
}

int DIV(int num1 , int num2){
    cout<< num1 / num2<<endl;
}

int REMEN(int num1 , int num2){
    cout<< num1 % num2<<endl;
}



int main()
{
string choice;
int num1,num2;
char decision;

do{
cout<< "WHAT IS THE OPERATION YOU WHANT TO DO: \n 1) ADD\n 2) SUBTRACT\n 3) MULTIPLY\n 4) DIVIDE\n 5) REMANDER"<<endl;
cout<< "your choice: ";
cin>>choice;
cout<< "what is your first number: "<<endl;
cin>>num1;
cout<< "what is your second number: "<<endl;
cin>>num2;


if(choice == "add"){
    ADD(num1,num2);
}
else if(choice == "subtract"){
    SUB(num1,num2);
}
else if(choice == "multiply"){
    MULT(num1,num2);
}
else if(choice == "divide"){
    DIV(num1,num2);
}
else if(choice == "remainder"){
    REMEN(num1,num2);
}
else{
    cout<< "INVALID ENTRY?"<<endl;
}

cout<< "DO YOU WANT TO CONTINUE\n y) YES or f) FALSE "<<endl;
cin>>decision;

}while(decision == 'y');

    return 0;
}
