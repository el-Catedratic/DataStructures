#include<bits/stdc++.h>

using namespace std;

class Heap{
    public:
        int* arr;
        int len;
        int data;
        int size;

        Heap(){
           arr = new int[10]();
           size = 1;
        } 

        void UpHeapify(int i){
            if(i==1){
                return;
            }
            else{
                if(arr[i] < arr[(i/2)]) return;
                else{
                    swap(arr[i],arr[(i/2)]);
                    UpHeapify((i/2));
                }
            }
        }

        void DownHeapify(int i){
            if((2*i > size)) return;
            else if((2*i == size)){
                if(arr[i] > arr[2*i]) return;
                else{
                   swap(arr[i],arr[2*i]);
                   return;
                }
            }
            else{
                if((arr[i]>max(arr[2*i],arr[2*i+1]))) return;
                else{
                    if(max(arr[2*i],arr[2*i+1]) == arr[2*i]){
                        swap(arr[i],arr[2*i]);
                        DownHeapify(2*i);
                    }
                    else{
                        swap(arr[i],arr[2*i+1]);
                        DownHeapify(2*i+1);
                    }
                }
            }
        }

        void add_data(int val){
           if(size == (len-1)) cout<<"HeapOverflow"<<endl;
           else{
               arr[size] = val;
               UpHeapify(size);
           }
           size++;
        }

        void pop(){
            if(size == 1) return;
            else{
                int temp = arr[1];
                swap(arr[1],arr[--size]);
                //Print();
                size--;
                DownHeapify(1);
                size++;
                //Print();
                cout<<temp<<endl;
            }
        }

        void Print(){
            for(int i = 1;i<size;i++){
                cout<<arr[i]<<"  ";
            }
            cout<<endl;
        }

};

int main(){
    Heap* hp = new Heap();
    hp->len = 10;
    hp->add_data(10);
    //hp->Print();
    hp->add_data(2);
    //hp->Print();
    hp->add_data(3);
    hp->add_data(7);
    //hp->Print();
    hp->add_data(4);
    //hp->Print();
    hp->add_data(1);
    //hp->Print();
    hp->add_data(5);
    //hp->Print();
    hp->add_data(8);
    //hp->Print();
    //hp->add_data(6);
   // hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    hp->pop();
    //hp->Print();
    
    return 0;
}