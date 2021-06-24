#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

};

class BST{
    public:
        Node* root;
        BST(){
            root = NULL;
        }
        BST(int val){
            root = new Node(val);
        }

        void Insert(int val){
           Node* curr = root;
            Node* temp = NULL;
            if(root == NULL) root->data = val; 
            else{
                while(curr){
                    if(val > curr->data){
                        temp = curr;
                        curr = curr->right;
                    }
                    else{
                        temp = curr;
                        curr = curr->left;
                    }
                }
                if(val > temp->data) temp->right = new Node(val);
                else temp->left = new Node(val);
            }
        }

        void dete(int val){
            Node* curr = root;
            Node* temp = root;
            while(curr->data != val){
                temp = curr;
                if(val > curr->data) curr = curr->right;
                else curr = curr->left;
            }
            if((curr->left == NULL) && (curr->right == NULL)){
                curr = NULL;
                delete(curr);
            }
            else if(curr->left == NULL || curr->right == NULL){
                if(curr->left == NULL){
                    if(temp->left == curr) temp->left = curr->right;
                    else temp->right = curr->right;
                }
                else{
                    if(temp->left == curr) temp->left = curr->left;
                    else temp->right = curr->left;
                }
                delete(curr);
            }
            else{
                Node* nxtroot = curr;
                nxtroot = nxtroot->left;
                while(nxtroot->left) nxtroot = nxtroot->left;
                curr->data = nxtroot->data;
                delete(nxtroot);
                curr->left = NULL;
            }
        }

        void Print(Node* prt){
            if(prt == NULL) return;
            else{
                Print(prt->left);
                cout<<prt->data<<" ";
                Print(prt->right);
            }
        }

        void LCA(int val1,int val2){
            Node* ptr1 = root;
            Node* ptr2 = root;
            Node* temp = NULL;
            while((ptr1 == ptr2) && (ptr1->data != val1 && ptr2->data != val2)){
                temp = ptr1;
                if(val1 > ptr1->data) ptr1 = ptr1->right;
                else ptr1 = ptr1->left;
                if(val2 > ptr2->data) ptr2 = ptr2->right;
                else ptr2 = ptr2->left;
            }
            cout<<temp->data<<endl;
        }
};

int main(){
    BST* temp = new BST(10);
    temp->Insert(3);
    temp->Insert(17);
    temp->Insert(2);
    temp->Insert(5);
    temp->Insert(16);
    temp->Insert(18);
    temp->Insert(4);
    temp->Insert(6);
    temp->Insert(7);
    //temp->Print(temp->root);
    temp->dete(5);
    temp->Print(temp->root);
    temp->LCA(18,17);
    return 0;
}