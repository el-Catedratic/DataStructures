#include<bits/stdc++.h>
using namespace std;


class Graph{
    private:
        int N,M;
        list<int> *l;
        vector<int> v;
    public:
        Graph(int ver,int edg){
            N = ver;
            M = edg;
            l = new list<int>[N];
        }    

        void AddEdge(int x,int y,bool bidr){
            if(bidr){
                l[x].push_back(y);
                l[y].push_back(x);
            }
            else{
                l[x].push_back(y);
            }
        }

        void Dfs(int x,vector<int> &vis){
            vis[x] = 1;
            cout<<x<<" ";
            for(auto it = l[x].begin();it!=l[x].end();it++){
                if(!vis[*it]){
                    Dfs(*it,vis);
                }
                else return;
            }
            cout<<endl;
        }

       /* ~Graph(){
            delete(l);
        }
        */
};


int main(){
    int vertex,edges;
    cin>>vertex>>edges;
    vector<int> v(vertex,0);
    Graph g = Graph(vertex,edges);
    while(edges!=0){
        int x,y;
        bool bd;
        cin>>x>>y>>bd;
        g.AddEdge(x,y,bd);
        edges--;
    }
    g.Dfs(0,v);
    g.~Graph();
    return 0;
}
