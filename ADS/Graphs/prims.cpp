#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

class Graph{
    public:
        unordered_map<int,vector<pi>> map;
        //vector<int> visited;

        void addEdge(int num1,int num2,int wt){
            map[num1].push_back(make_pair(num2,wt));
            map[num2].push_back(make_pair(num1,wt));
        }

        void Prims(int src){
            priority_queue<pi,vector<pi>,greater<pi>> pq;
            unordered_map<int,int> unvis;
            for(auto it = map.begin();it!=map.end();it++){
                unvis[it->first] = INT_MAX;
            }
            pq.push(make_pair(0,src));
            while(!unvis.empty()){
                int tp = pq.top().second;
                int cur_wt = pq.top().first;
                // cout<<"Node"<<tp<<"->"<<"Weight"<<cur_wt<<endl;
                for(auto nbrs: map[tp]){
                    if(unvis.find(nbrs.first) != unvis.end()){
                        if(unvis[nbrs.first] > (cur_wt + nbrs.second)){
                            unvis[nbrs.first] = cur_wt + nbrs.second;
                            //pq.push(make_pair(unvis[nbrs.first],nbrs.first));
                        }
                    }
                }
                unvis.erase(tp);
                pq.pop();
                for(auto nbrs : map[tp]){
                    if(unvis.find(nbrs.first) != unvis.end()){
                        pq.push(make_pair(unvis[nbrs.first],nbrs.first));
                    }
                }
                cout<<"Node"<<tp<<"->"<<"Weight"<<cur_wt<<endl;
            }
        }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(2, 1, 10);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 11);
    g.addEdge(2, 4, 12);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 5, 2);
    g.Prims(0);
    return 0;
}