#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct NODE{
  char let;
  NODE *next;
};

void driver();
void printOUT();
void getLetter(NODE *head);
NODE *getUserData(char letter); 

int main(){
  
  driver(); 
  

  return 0;
}

void driver(){
 NODE *head;
  head = new NODE;

  printOUT();
  getLetter(head);
  cout << "finished" << endl;
}
void printOUT(){
  cout << "This function removes the final node of a linked list of letters" << endl;
  cout << "and returns the result. Enter a list of letters to place in the" << endl;
  cout << "list (or press ENTER for an empty list): " << endl;
}
void getLetter(NODE *head){
  
  char newLet;

  cin >> newLet;
  if(newLet != '\n'){
    head = getUserData(newLet);
  }
}
NODE *getUserData(char letter){  
  NODE *Letters;
  Letters = new NODE;
  NODE *pre;
  pre = new NODE;
  //get data
  Letters->let = letter;
  //add to front
  Letters->next = pre;
  pre = Letters;
  pre = pre->next;
  
  return pre;
}
