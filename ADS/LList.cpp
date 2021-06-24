#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            data = val;
            next = NULL;
        }
};        

class LList{
    public:
        Node *head;

    public:
        void insert(int x);
        void delete_ll(int x);
        void print();
        void rem_dupli();
        void getkend(int n);
        void partition(int n);
       
    ~LList(){
        delete head;
    }    

};

void sum_lists(Node* head1,Node* head2){
    Node* curr1 = head1;
    Node* curr2 = head2;
    vector<int> temp1;
    vector<int> temp2;
    int len1 = 0;
    int len2 = 0;

    while(curr1){
        len1++;
        temp1.push_back(curr1->data);
    }
    while(curr2){
        len2++;
        temp2.push_back(curr2->data);
    }
    if(len1 < len2){
        
    }
}

void LList :: rem_dupli(){
    Node* curr = head;
    Node* prev = head;
    unordered_set<int> ll;
    while(curr){
        if(ll.find(curr->data) == ll.end()){
            ll.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
        else{
            Node *temp = curr->next;
            prev->next = curr->next;
            delete curr;
            curr = temp;
        }
    }
}

void LList :: partition(int n){
    Node* cur = head;
    Node* pos = head;
    while(cur){
        if(cur->data < n){
            int temp;
            temp = pos->data;
            pos->data = cur->data;
            cur->data = temp;
            pos = pos->next;
        }
        cur = cur->next;
    }
}

void LList::getkend(int k){
	int len = 0;
	Node *temp = head;
	while(temp){
        len++;
		temp = temp->next;
		
	}
    temp = head;
	if(len >= k){
        int tp = 1;
        while(tp!=len - k +1){
            temp = temp->next;
            tp++;
        }
    }
	
	cout<<temp->data<<endl;
}

void  LList::insert(int x){
    Node *new_node = new Node(x);
        
        if(head == NULL){
            head = new_node;
        }
        else{
            Node *cur;
            cur = head;
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = new_node;
            new_node->next = NULL;
        }
}


void LList::print(){
    if(head == NULL){
        cout<<"Empty List"<<endl;
    }
    else{
        Node *cur;
        cur = head;
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

}

void LList::delete_ll(int x){
    Node *cur = head;
    Node *prev = head;
    if(head == NULL){
        cout<<"Empty List"<<endl;
    }
    else{
        while(cur->data!=x){
            prev = cur;
            cur = cur->next;
        }
        if(cur == NULL){
            cout<<"NO such element exists"<<endl;
        }
        else{
            prev->next = cur->next;
            delete cur;
        }
    }
}

int main(){
    LList *list = new LList();
    LList *list1 = new LList();
    list1->insert(3);
    list1->insert(5);
    list1->insert(8);
    list1->insert(5);
    list1->insert(10);
    list1->insert(2);
    list1->insert(1);
    list1->insert(50);
    list1->partition(5);
    list1->print();
    return 0;
}
