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
    
    private: void inOrder(Node *no) {
        if (no != NULL) {
            inOrder(no->left);
            cout << no->data << " ";
            inOrder(no->right);
        }
    }
    
    private: void preOrder(Node *no) {
        if (no != NULL) {
            cout << no->data << " ";
            preOrder(no->left);
            preOrder(no->right);
        }
    }
    
    private: void posOrder(Node *no) {
        if (no != NULL) {
            posOrder(no->left);
            posOrder(no->right);
            cout << no->data << " ";
        }
    }
    
    public: void showResults() {
        cout << "Folhas: ";
        folhas(root);
        cout << "\nIn Order: ";
        inOrder(root);
        cout << "\nPre Order: ";
        preOrder(root);
        cout << "\nPos Order: ";
        posOrder(root);
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
