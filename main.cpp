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
char getInput(char input[]);
NODE *buildList(char input[]);
NODE *removeNode(NODE *head); 
void printList(NODE *head);

int main(){
  
  driver(); 
  

  return 0;
}

void driver(){
  NODE *head;
  head = new NODE;
  char input[MAX];

  getInput(input);
  head = buildList(input);
  if(head->let != '\0'){
    cout << "Before removing the last node, the letters in the list are: " << endl;
    printList(head);
    head = removeNode(head);
    cout << "After removing the last node, the letters in the list are: " << endl;
    printList(head);
  }
}
char getInput(char input[]){
 
  int index = 0;
  cout << "This function removes the final node of a linked list of letters" << endl;
  cout << "and returns the result. Enter a list of letters to place in the" << endl;
  cout << "list (or press ENTER for an empty list): " << endl;
  cin.getline(input,MAX);
  while(input[index] != '\0'){
    if(!isalpha(input[index])){
      cout << "ERROR!: only use alphabetic characters please." << endl << endl;
      getInput(input);
    }
    index++;
  }

  return *input;
}
NODE *buildList(char input[]){
  NODE *pNEW;
  pNEW = new NODE;
  NODE *pPRE;
  pPRE = new NODE;
  int alpha = 0;   
  

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
