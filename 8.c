#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Node{
  int val;
  struct Node *next;
}NODE,*pNODE;

typedef struct List{
  pNODE top;
  int len;
}LIST,*pLIST;

pLIST create_list(){
  pLIST pL;
  pL = (pLIST)malloc(sizeof(LIST));
    if(!pL) return NULL;
    pL->top = NULL;
    pL->len = 0;
    return pL;
}

int isEmpty(pLIST pL){
  if(pL->top && pL->len) return 0;
    return 1;
}

pNODE GetPointer(pLIST pL,int date){
  if(isEmpty(pL)) return NULL;
  pNODE temp = pL->top;
    if(temp->val<=date) return temp;
  while(temp->next && temp->next->val>date)
  temp=temp->next;
    return temp;
}

int addNodeAfter(pLIST pL,pNODE pN, int newdate){
  pNODE pnew = (pNODE)malloc(sizeof(NODE));
  if(pnew){
    pnew->val = newdate;
    if(!pN){
      pnew->next = NULL;
      pL->top = pnew;
    }
    else
    if(pN == pL->top && newdate>pL->top->val){
      pnew->next = pL->top;
      pL->top = pnew;
    }
    else{
      pNODE temp = pN->next;
      pnew->next = temp;
      pN->next = pnew;
    }
    pL->len++;
    return 1;
  }
  return 0;
}

void showList(pLIST pL){
  if(isEmpty(pL)) printf("List is empty!!\n");
  else{
    pNODE temp = pL->top;
    printf("Length List: %d\n",pL->len);
    while(temp){
      printf("adres: %p\t Value: %d\t next:%p\n", temp,temp->val,temp->next);
    }
  }
}

pNODE findNode(pLIST pL,int date){
  if(isEmpty(pL)) return NULL;
  pNODE temp = pL->top;
  if(temp->val==date) return temp;
  while(temp->next && temp->next->val!=date) temp = temp->next;
  if(temp->next) return temp;
  return NULL;
}

int delNode(pLIST pL,pNODE pN){
  if(!pN) return 0;
  pNODE temp = pN->next;
  pN->next = temp->next;
  free(temp);
  pL->len--;
  return 1;
}

void clearLIST(pLIST pL){
  while(pL->top->next) delNode(pL, pL->top);
  free(pL->top);
  pL->len--;
}

void deleteList(pLIST pL){
  if(!isEmpty(pL)) clearLIST(pL);
  free(pL);
}
