#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node * left;
  struct Node * right;
  struct Node * parent;
};

void add(struct Node ** root, struct Node * parent, int val){
  if ((*root) == NULL){
    (*root) = (struct Node *)malloc(sizeof(struct Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->value = val;
    (*root)->parent = parent;
  }else if(val>(*root)->value){
    add(&(*root)->left, (*root), val);
  }else{
    add(&(*root)->right, (*root), val);
  }
  return;
}

void pryunt(struct Node * currnode, struct Node * parent, int pint){
  if (currnode->left != NULL){
    pryunt(currnode->left, currnode, 1);
  }else if(currnode->right == NULL){
    if (pint == 1)printf("%d ", currnode->value);
    if(parent == NULL){return;}else{
    if(parent->left == currnode){
      parent->left = NULL;
      pryunt(parent, parent->parent, 1);
    }else{
      parent->right =NULL;
      pryunt(parent, parent->parent, 0);
    }
    free(currnode);
    }
  }else if(currnode!=NULL){
    printf("%d ", currnode->value);
    pryunt(currnode->right, currnode, 1);
  }else{
    return;
  }
} 

int main(void) {
  struct Node * root=NULL;
  int n, k;
  scanf("%d", &n);
  for (int i=0;i<n;i++){
    scanf("%d", &k);
    add(&root, NULL, k);
  }
  pryunt(root, root->parent, 1);
  return 0;
}
