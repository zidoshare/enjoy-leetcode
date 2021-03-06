#include <malloc.h>
struct Node{
  int flag;
  int score;
  struct Node* parent;
  struct Node* child;
};
struct Node* createRoot(){
  struct Node* root = (struct Node*)malloc(sizeof(struct Node));
  root->flag = 0;
  root->score = 0;
  root->parent = NULL;
  root->child = NULL;
  return root;
}
struct Node* addChild(struct Node* parent){
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->flag = 0;
  node->score = 0;

  node->parent = parent;
  parent->child = node;
  node->child = NULL;

  return node;
}
int scoreOfParentheses(char* s) {
  int i = 0;
  struct Node* root = createRoot();
  struct Node* current = root;
  while(s[i] != '\0'){
    if(s[i] == '('){
      current = addChild(current);
    }else{
      if(current->score == 0){
        current->score = 1;
      }
      current->flag = 1;

      while(current->parent != NULL && current->flag == 1){
        if(current->parent == root){
          current->parent->score += current->score;
        }else{
          current->parent->score = 2 * (((current->parent->score) / 2) + current->score);
        }
        current = current->parent;
      }
    }
    i++;
  }
  return root->score;
}


