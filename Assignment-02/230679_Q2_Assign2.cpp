#include<bits/stdc++.h>
using namespace std;
 
#define INF 1000000000000000

void dijkstra(long long int N,vector<pair<long long int,long long int >>adj[]){
    vector<long long int>distance(N,INF);
    distance[0]=0;
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        long long int node=pq.top().first;
        long long int dist=pq.top().second;
        pq.pop();
        if(dist>distance[node])continue;
        for(auto u:adj[node]){
           long long int v=u.first;
            long long int weight=u.second;
            if(distance[v]>dist+weight){
                distance[v]=dist+weight;
                pq.push({v,distance[v]});
            }

        }

    }
    for(long long int i=0;i<N;i++){
        cout<<distance[i]<<" ";
    }

}


int32_t main(){
    long long int n,m;
    cin>>n>>m;
    vector<pair<long long int,long long int>>adj[n];
    for(long long int i=0;i<m;i++){
        long long int a,b,wt;
        cin>>a>>b>>wt;
        a--,b--;
        adj[a].push_back({b,wt});
    }

    dijkstra(n,adj);
    return 0;
    
}