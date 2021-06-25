#include <iostream>
#include <stdio.h>

#define MAXX 7

using namespace std;

struct node{
    int data;

    struct node *rightside;
    struct node *leftside;
 };

struct node *root = NULL;

void insertion(int data){
   struct node *temp_node = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *former;

   temp_node->data = data;
   temp_node->leftside = NULL;
   temp_node->rightside = NULL;

   if(root == NULL) {
      root = temp_node;
      }
      else {
      current = root;
      former = NULL;
      }

   while(1){
        former = current;

        //moving through left side of tree

        if(data < former->data){
            current = current->leftside;

            if(current == NULL){
                former->leftside = temp_node;
                return;
            }
        }
        else{
            current = current->rightside;

            if(current == NULL){
                former->rightside = temp_node;
                return;
            }
        }
      }
  }

void prefix(struct node* root){
    if(root != NULL){
        cout<< root->data ;
        prefix(root->leftside);
        prefix(root->rightside);
        }

    }

void infix(struct node* root){
    if(root != NULL){
        infix(root->leftside);
        cout<< root->data;
        infix(root->rightside);
        }
    }

void postfix(struct node* root){
    if(root != NULL){
        postfix(root->leftside);
        postfix(root->rightside);
        cout<<root->data;
       }
    }

 int main(){
     int i;
     int listA[MAXX] = {23,45,3,55,43,37,99};

     for(i=0;i<MAXX;i++){

        insertion(listA[i]);
     }

     cout<<" prefix order is : " ;
     prefix(root);

     cout<<" \n infix order is : " ;
     infix(root);

     cout<<" \n post fix order is : ";
     postfix(root);

     return 0;
}


