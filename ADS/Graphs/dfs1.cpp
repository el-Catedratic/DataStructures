#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> map;
        vector<bool> visited;

        Graph(){
            visited = vector<bool>(7,false);
        }

        void add(int a,int b){
            map[a].push_back(b);
            map[b].push_back(a);
        }

        void Print(){
            for(auto it = map.begin();it!= map.end();it++){
                cout<<((it->first))<<" ";
                for(auto pt = (it->second.begin());pt!=(it->second.end());pt++){
                    cout<<*pt<<" ";
                }
                cout<<endl;
            }
        }

        void dfs(int num){
            cout<<num<<" ";
            visited[num] = true;
            for(auto it = map[num].begin();it!=(map[num].end());it++){
                if(!visited[*it]){
                    dfs(*it);
                }
            }
        }

        void bfs(int num){
            queue<int> q;
            q.push(num);
            while(!q.empty()){
                cout<<q.front()<<" ";
                visited[q.front()] = true;
                for(auto it = map[q.front()].begin();it!=map[q.front()].end();it++){
                    if(!visited[*it]){
                        q.push(*it);
                    }
                }
                q.pop();
            }
            cout<<endl;
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
    //g.Print();
    g.bfs(0);
    return 0;
}