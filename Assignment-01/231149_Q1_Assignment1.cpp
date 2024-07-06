#include<iostream>
#include<vector>
#define NUM 15
#define start 9 

using namespace std;

vector<vector<int>> adj(NUM);
vector<int> visited(NUM, 0);

void dfs(int cur){
    cout<<cur<<endl;

    visited[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if(!visited[adj[cur][i]]){
            dfs(adj[cur][i]);
        }
    }
}

int main(){
    adj[0] = vector<int>{1,2};
    adj[1] = vector<int>{0,3,4};
    adj[2] = vector<int>{0,5,6,10};
    adj[3] = vector<int>{1,7,8};
    adj[4] = vector<int>{1,9};
    adj[5] = vector<int>{2,10};
    adj[6] = vector<int>{2,11,12};
    adj[7] = vector<int>{3};
    adj[8] = vector<int>{3};
    adj[9] = vector<int>{4,13,14};
    adj[10] = vector<int>{2,5};
    adj[11] = vector<int>{6};
    adj[12] = vector<int>{6};
    adj[13] = vector<int>{9};
    adj[14] = vector<int>{9};

    dfs(start);
}