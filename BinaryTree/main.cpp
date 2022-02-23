/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

class Tree {
    private: Node *root; //declara root
    
    public: Tree() {
        root = NULL; // inicializa a árvore
    }
    
    public: void insert(int value) {
        Node *novo = new Node(); //cria um novo nó
        novo->data = value;
        novo->right = NULL;
        novo->left = NULL;
        
        if(root == NULL) {
            root = novo;
        } else {
            Node *atual = root;
            Node *aux;
            while(true) {
                aux = atual;
                if (value < atual->data) {
                    atual = atual->left;
                    if (atual == NULL) {
                        aux->left = novo;
                        return;
                    }
                } else {
                    atual = atual->right;
                    if (atual ==  NULL) {
                        aux->right = novo;
                        return;
                    }
                }
            }
        }
    }
    
    private: void folhas(Node *no){
        if (no == NULL) {
            cout << "Tree is empty.";
        } if (no->left == NULL && no->right == NULL) {
            cout << no->data << " ";
        }else {
            if (no->left != NULL) {
                folhas(no->left);
            }
            if (no->right != NULL) {
                folhas(no->right);
            }
        }
    }
    
    public: void showResults() {
        cout << "Folhas: ";
        folhas(root);
    }
};

int main() {
    Tree tree = Tree();
    tree.insert(10);
    tree.insert(7);
    tree.insert(9);
    tree.insert(12);
    tree.insert(3);
    tree.insert(11);
    tree.insert(14);
    

    tree.showResults();
}



