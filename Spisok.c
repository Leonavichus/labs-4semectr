#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <time.h>

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
      temp = temp->next;
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

int main(void){
  pLIST pL = create_list();
  pNODE p;
  char exit = 0;
  int com;
  while(1){
    puts("1-add element");
    puts("2-find the element");
    puts("3-delete the element");
    puts("4-show list");
    puts("5-clear list");
    puts("6 - random elements");
    puts("0-end of work");
    scanf("%d",&com);
    switch(com){
      case 0: exit = 1;break;
      case 1: printf("vvedite chislo:");
              scanf("%d",&com);
              addNodeAfter(pL,GetPointer(pL,com),com);
              break;
      case 2: printf("Enter chislo:");
              scanf("%d",&com);
              p = findNode(pL,com);
              if(p){
                p = (p==pL->top && com==pL->top->val) ? p:p->next;
                printf("chislo %d in list, address: %p/n", com,p);
              }
              else
                printf("Chislo %d not find in list!\n",com);
              break;
      case 3: printf("Enter chislo:");
              scanf("%d",&com);
              p = findNode(pL,com);
              if(p){
                if(p==pL->top && com==pL->top->val){
                  pL->top = p->next;
                  pL->len--;
                  free(p);
                  printf("Delete complete!\n\n");
                }
                else
                if(delNode(pL,p))printf("Delete complete!\n\n");
              }
              else
                printf("A integer %d does not contain in list!\n",com);
              break;
      case 4: showList(pL); break;
      case 5: clearLIST(pL); showList(pL);
      case 6: printf("Kolichestvo chisel:");
              scanf("%d", &com);
              srand(time(NULL));
              while(com--){
              addNodeAfter(pL,GetPointer(pL,rand()%101),rand()%101);
              }
    };
    if(exit) break;
  }
  deleteList(pL);
  return 0;
}
