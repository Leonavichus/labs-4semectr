#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#define N 20

typedef struct node{
  int key;
  struct node *left, *right;
}NODE, *pNODE;

pNODE addnode(int x, pNODE root){
  if (!root){
    root =(pNODE) malloc (sizeof(NODE));
    if (root){
      root->key=x;
      root->left=NULL;
      root->right=NULL;
  }
}
  else
    if (x<root->key)
      root->left=addnode (x,root->left);
    else
      root->right=addnode (x,root->right);
  return root;
}

void preorder (pNODE root){
  if (root){
    printf("%d;",root->key);
    preorder (root->left);
    preorder (root->right);
  }
}

void postorder(pNODE root){
  if (root){
    postorder (root->left);
    postorder (root->right);
    printf("%d;",root->key);
  }
}

void inorder (pNODE root){
  if (root){
    inorder (root->left);
    inorder (root->right);
    printf ("%d;",root->key);
  }
}

pNODE find_tree (pNODE root, int val){
  if (!root) return NULL;
  if(val==root->key) return root;
  if(val< root->key) return find_tree(root->left, val);
  if(val>= root->key) return find_tree(root->right,val);
}

int rightmost (pNODE root){
  while (root->right)
    root=root->right;
  return root->key;
}

pNODE del_tree (pNODE root, int val){
  if (!root) return NULL;
  if (root->key==val){
    if(!(root->left) && !(root->right)){
      free (root);
    return NULL;
    }
    if(!(root->right)&& root->left){
      pNODE temp= root->left;
      free(root);
      return temp;
    }
    if(!(root->left) && root->right){
      pNODE temp= root->right;
      free (root);
      return temp;
    }
    root->key=rightmost(root->left);
    root->left=del_tree(root->left,root->key);
    return root;
  }
  if (val< root->key){
    root->left=del_tree(root->left, val);
    return root;
  }
  if (val>=root->key){
    root->right=del_tree(root->right, val);
    return root;
  }
  return root;
}

void Nnodes (pNODE root, int *p){
  if (!root) return;
    (*p)++;
    Nnodes(root->left, p);
    Nnodes(root->right, p);
}

void Height(pNODE root, int p,int* h){
  if(!root) return;
  p++;
  if(!(root->left) && !(root->right))
    if(p>*h) *h=p;
  Height(root->left,p,h);
  Height(root->right,p,h);
}

void del_all(pNODE *root){
  if (!*root) return;
  del_all (&(*root)->left);
  del_all (&(*root)->right);
  free (*root);
  *root = NULL;
}

int main(void){
  pNODE p, root=NULL;
  int i,k,*h=&k;
  srand (time(NULL));
  root=addnode(rand()%101,root);
  for (i=0; i<N ;i++)
    root=addnode(rand()%101,root);
  i=0; Nnodes(root, &i);
  printf ("\nIn tree %d nodes\n",i);
  *h=0;
  Height(root, 0, h);
  printf ("\nHeight tree = %d\n",*h);
  printf("preorder:");
  preorder (root); printf("\n");
  printf("postorder:");
  postorder (root); printf("\n");
  printf("inorder:");
  inorder (root); printf("\n");
  del_all(&root);
  preorder(root);
  del_all(&root);
  preorder(root);
  printf("\nroot %p\n",root);
  return 0;
}
