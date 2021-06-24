#include<bits/stdc++.h>
using namespace std;

int main(){
    int rules;
    cin>>rules;
    cout<<"ENTER THE NO OF RULES"<<" "<<":"<<rules<<endl;
    map<int,set<char>> table;

    set<char> chrset; //set of all the itemset
    int min_sup;
    cin>>min_sup;
    int i = 0;
    while(rules){
        int p;
        cout<<"enter the no of elements in the current rule"<<" ";
        cin>>p;
        cout<<endl;
        while(p){
            char element;
            cin>>element;
            table[i].insert(element);
            p--;
        }
        i++;
        rules--;
    }
    for(auto it = table.begin();it!=table.end();it++){
        //cout<<it->first<<":";
        for(auto ij = (it->second).begin();ij!=(it->second).end();ij++){
            //cout<<*ij<<" ";
            chrset.insert(*ij);
        }
        cout<<endl;
    }
    map<set<char>,int> frequent_set;

    for(auto it = chrset.begin();it != chrset.end();it++){
        int count = 0;
        for(auto ip = table.begin(); ip!=table.end();ip++){
            if(binary_search(ip->second.begin(),ip->second.end(),*it)){
                count++;
            }
        }
        set<char> temp;
        if(count >= min_sup){
            temp.insert(*it);
            frequent_set.insert(make_pair(temp,count));
        }
    }
    bool flag = 1;
    if(frequent_set.size()){
        map<set<char>,int> tp;
        while(flag){
            
            for(auto it = frequent_set.begin();it!=frequent_set.end();it++){
                for(auto ij = next(it,1);ij!=frequent_set.end();ij++){
                    set<char> res;
                    set_union(it->first.begin(),it->first.end(),ij->first.begin(),ij->first.end(),inserter(res,res.begin()));
                    tp.insert(make_pair())
                }
            }
        }
    }
    else{

    }
    return 0;
}