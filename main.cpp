#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;
static int MAX = 50;

struct NODE{
  char let;
  NODE *next;
};

void driver();
void printOUT();
NODE *buildList();
NODE *removeNode(NODE *head); 
void printList(NODE *head);

int main(){
  
  driver(); 
  

  return 0;
}

void driver(){
  NODE *head;
  head = new NODE;
  printOUT();
  head = buildList();
  printList(head);
  head = removeNode(head);
  printList(head);
  cout << "finished" << endl;
}
void printOUT(){
  cout << "This function removes the final node of a linked list of letters" << endl;
  cout << "and returns the result. Enter a list of letters to place in the" << endl;
  cout << "list (or press ENTER for an empty list): " << endl;
}
NODE *buildList(){
  NODE *pNEW;
  pNEW = new NODE;
  NODE *pPRE;
  pPRE = new NODE;
  char input[MAX];
  int alpha = 0;   
  cin.getline(input,MAX);

  while(input[alpha] != '\0'){
    pNEW->let = input[alpha];
    pNEW->next = pPRE;
    pPRE = pNEW;
    pNEW = pNEW->next;
    pNEW = new NODE;
    alpha++;
  }
    
  return pPRE;
}
NODE *removeNode(NODE *head){
NODE *temp;
   
 if(head->next->let != '\0'){
   temp = head;
   head = head->next;
   removeNode(head);
 }
 else{
   delete head;
   head->next = 0;
 }
  
  return temp;
}
void printList(NODE *head){

  if(head->next != 0){
    cout << setw(4)<< head->let;
    head = head->next;
    printList(head);
  }
  else{
    cout << endl;
  }

}
