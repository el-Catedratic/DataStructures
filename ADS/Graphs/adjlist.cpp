#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    private:
        int N;
        int M;

    public:
        list<T> *l;
        Graph(int nodes,int edges){
            N = nodes;
            M = edges;
            l = new list<T>[N];
        }    

        void AddEdge(T x,T y,int bidr){
            if(bidr){
                l[x].push_back(y);
                l[y].push_back(x);
            }
            else{
                l[x].push_back(y);
            }
        }
        void printEdge(){
            for(int i=0;i<N;i++){
                cout<<(i)<<"->";
                for(T nbrs:l[i]){
                    cout<<nbrs<<"->";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    Graph<int> g(n,m);
    while(m!=0){
        int i,j;
        int  bidr;
        cin>>i>>j;
        cin>>bidr;
        g.AddEdge(i,j,bidr);
        m--;
    }
    g.printEdge();
    return 0;
}

