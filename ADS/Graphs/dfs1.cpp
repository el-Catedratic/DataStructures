#include<bits/stdc++.h>

using namespace std;

//template<typename T>

class Graph{

    private:
        int V;

    public:
        unordered_map<int,vector<int>> lt;
        vector<bool> visited;

        Graph(int V){
            this->V = V;
            visited = vector<bool>(V,0);
        }

        void add(int num1,int num2){
            if(lt.find(num1) != lt.end()) lt[num1].push_back(num2);
            else{
                lt.insert(make_pair(num1,vector<int>()));
                lt[num1].push_back(num2);
            }
            if(lt.find(num2) != lt.end()) lt[num2].push_back(num1);
            else{
                lt.insert(make_pair(num2,vector<int>()));
                lt[num2].push_back(num1);
            }
        }

        void dfs(int num,vector<bool> &visited){
            visited[num] = true;
            if(visited[num]){
                return;
            }
            else{
                for(int nbrs : lt[num]){
                    cout<<nbrs<<" ";
                    dfs(nbrs,visited);
                }
            }
        }
 };

 int main(){
    Graph g(5);
    int i = 5;
    while(i--){
        int temp,temp1;
        cin>>temp>>temp1;
        g.add(temp,temp1);
    }
    g.dfs(0,g.visited);
    return 0;
 }