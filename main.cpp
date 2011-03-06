#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
static int MAX = 50;

struct NODE{
  char let;
  NODE *next;
};

void driver();
void printOUT();
NODE *buildList(); 

int main(){
  
  driver(); 
  

  return 0;
}

void driver(){
  NODE *head;
  head = new NODE;
  printOUT();
  head = buildList();
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
    if(alpha < 1){ 
      pNEW->next = pPRE;
      pPRE = pNEW;
    }
    else{
      pNEW->next = pPRE->next;
      pPRE->next = pNEW;
    }
    pNEW = pNEW->next;
    pNEW = new NODE;
    alpha++;
  }
  return pPRE;
}
