#include<bits/stdc++.h>
#include<queue>
using namespace std;


class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

class Tree{
    
    public:
        Node* insert(Node *toor,int x);
        void inorder(Node *toor);
        int height(Node*,int,int);  
        Node* minode(Node *);
        Node* deleteNode(Node*,int);
};

Node* Tree::insert(Node *toor,int x){
    Node *new_node = new Node(x);
    if(toor == NULL){
        toor = new_node;
        return toor;
    }
    else{
        Node *cur = toor;
        Node* prev = NULL;
        while(cur!=NULL){
            if(x < cur->data){
                prev = cur;
                cur = cur->left;
            }
            else{
                prev = cur;
                cur = cur->right;
            }
        }
        if(prev == NULL){
            cur = new_node;
        }
        else{
            if(x < prev->data){
                prev->left = new_node;
            }
            else{
                prev->right = new_node;
            }
        }
    }
    return toor;
}

void Tree::inorder(Node *toor){
    if(toor == NULL){
        return ;
    }
    else{
        inorder(toor->left);
        cout<<toor->data<<" ";
        inorder(toor->right);
    }
}

/* void Tree::level_order(Node *toor){
    queue<int> q;
    if(toor == NULL){
        return;
    }
    else{
        q.push(toor->data);
    }
} */
 int Tree::height(Node* toor,int l,int r){
     if(toor == NULL){
         return 0;
     }
     else{
         l = height(toor->left,l,r) ;
         r = height(toor->right,l,r);
         return max(l,r) + 1;
     }
 }

Node* Tree::minode(Node *toor){
    if(toor->left == NULL){
        return toor;
    }
    toor = minode(toor->left);
}



Node* Tree::deleteNode(Node *toor,int val){
    if(toor == NULL){
        return;
    }
    else{

    }
}

int main(){
    Tree *t1 = new Tree();
    Node *root = NULL;

    root = t1->insert(root,30);
    t1->insert(root,40);
    t1->insert(root,20);
    t1->insert(root,50);
    t1->insert(root,10);
    t1->inorder(root);
    cout<<t1->height(root,0,0)<<endl;

    return 0;
}    