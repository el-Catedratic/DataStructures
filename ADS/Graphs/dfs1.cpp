#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> map;
        vector<bool> visited;

        void add(int a,int b){
            map[a].push_back(b);
            map[b].push_back(a);
        }

        void dfs(int num){
            cout<<num<<" ";
            visited[num] = true;
            for(auto it = map[num].begin();it!=(map[num].end());it++){
                if(!visited[*it]){
                    dfs(*it);
                }
                else{
                    return;
                }
            }
        }
};

int main(){
    Graph g;
    g.add(0,2);
    g.add(1,3);
    g.add(0,4);
    g.add(1,5);
    g.add(4,6);
    g.add(5,2);
    g.dfs(0);
    return 0;
}