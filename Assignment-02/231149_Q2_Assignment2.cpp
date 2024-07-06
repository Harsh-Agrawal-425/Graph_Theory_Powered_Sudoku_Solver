//simple djikstra
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include <bits/stdc++.h> 
#define mod (1000000007)
#define int long long
#define rep(i, a, b) for(long long i = a; i < b; i++)
using namespace std;
 
int n, m;
vector<vector<pair<int, int> > > adj_list(100000);
vector<char> visited(100000,0);
vector<int> shortest(100000, INT64_MAX);
set<pair<int, int > > pq;
 
int32_t  main(){
    shortest[0] = 0;
    scanf("%lld %lld", &n, &m);
    
    rep(i,0,m){
        int a,b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        a--,b--;
        adj_list[a].push_back(make_pair(b, c));
    }
 
    rep(i, 0, n)
        pq.insert(make_pair(shortest[i], i));
 
    while(!pq.empty()){
 
 
        auto it = pq.begin();
        for(auto each : adj_list[(*it).second]){
            if(min(shortest[each.first], shortest[(*it).second]+each.second)<shortest[each.first])
            {pq.erase(pq.find(make_pair(shortest[each.first], each.first)));
            shortest[each.first] = min(shortest[each.first], shortest[(*it).second]+each.second);
            pq.insert(make_pair(shortest[each.first], each.first));}
        }
 
        pq.erase(it);
 
    }
    rep(i,0,n)
    printf("%lld ", shortest[i]);
}