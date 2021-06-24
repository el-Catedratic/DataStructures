#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node* right;
        int height;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
            height = 1;
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

        int height(Node* toor){
            if(toor == NULL) return 0;
            else return toor->height; 
        }

        int getBalance(Node* toor){
            if(toor == NULL) return 0;
            else return (height(toor->left) - height(toor->right));
        }

        Node* RightRotate(Node* toor){
            Node* y = toor->left;
            Node* t2 = y->right;

            toor->left = t2;
            y->right = toor;
            
            toor->height = max(height(toor->left),height(toor->right));
            y->height =  max(height(y->right),height(y->left));

            return y;
        }

        Node* LeftRotate(Node* toor){
            Node* y = toor->right;
            Node* t2 = y->left;

            toor->right = t2;
            y->left = toor;

            toor->height = max(height(toor->left),height(toor->right));
            y->height = max(height(y->left),height(y->right));

            return y;
        }

        Node* insert(Node* toor,int val){
            if(toor == NULL){
                toor = new Node(val);
                return toor;
            }
            else{
                if(val > toor->data){
                    toor->right = insert(toor->right,val);
                }
                else{
                    toor->left = insert(toor->left,val);
                }
            }
            toor->height = 1 + max(height(toor->left),height(toor->right));

            int balance = getBalance(toor);

            if((balance > 1) && (val < toor->left->data)) return RightRotate(toor);
            else if((balance < -1) && (val > toor->right->data)) return LeftRotate(toor);
            else if((balance > 1) && (val >  toor->left->data)){
                toor->left = LeftRotate(toor->left);
                return RightRotate(toor);
            }
            else if((balance < -1 ) && (val < toor->right->data)){
                toor->right = RightRotate(toor->right);
                return LeftRotate(toor);
            }
            return toor;
        }

        void Print(Node* toor){
            if(toor == NULL) return;
            else{
                Print(toor->left);
                Print(toor->right);
                cout<<toor->data<<" ";
            }
        }
};

int main(){
    BST* temp = new BST(10);
    temp->insert(temp->root,3);
    temp->insert(temp->root,17);
    temp->insert(temp->root,2);
    temp->insert(temp->root,5);
    temp->insert(temp->root,16);
    temp->insert(temp->root,18);
    temp->insert(temp->root,4);
    temp->insert(temp->root,6);
    temp->insert(temp->root,7);
    temp->Print(temp->root);
    //temp->dete(5);
    temp->Print(temp->root);
    //temp->LCA(18,17);
    return 0;
}
