#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char data[10];
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(char* value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->data, value);
    node->left = NULL;
    node->right = NULL;
    return node;
}


void preorder(struct Node* root) {
    if (root == NULL) return;
    
    printf("%s ", root->data); 
    preorder(root->left);      
    preorder(root->right);     
}

int main() {
    
    struct Node* root = newNode("=");
    
    root->left = newNode("a");
    root->right = newNode("+");
    
    root->right->left = newNode("b");
    root->right->right = newNode("*");
    
    root->right->right->left = newNode("c");
    root->right->right->right = newNode("2");

    printf("AST Preorder Sonucu: ");
    preorder(root);
    printf("\n");

    return 0;
}
