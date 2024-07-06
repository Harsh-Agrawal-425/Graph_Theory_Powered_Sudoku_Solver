// i treat the current symptoms as a binary number and the medicine changes the number from one to aother our goal is to reach the number 0 so i apply djikstra to reach in min days

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int d;
    int heal;
    int cause;
};

int convert(long long x){
    int ans = 0;
    int i = 0;
    while(x){
        if(x%10) ans|=1<<i;
        i++;
        x/=10;
    }
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        long long s;cin>>s;
        int initial = convert(s);

        struct edge edges[m];
        for (int i = 0; i < m; i++){
            int d;cin>>d;
            long long heal;cin>>heal;
            long long cause;cin>>cause;
            struct edge new_edge;
            new_edge.d = d;
            new_edge.heal = convert(heal);
            new_edge.cause = convert(cause);
            edges[i] = new_edge;
        }

        vector<int32_t> shortest(1<<(n), INT32_MAX);
        shortest[initial] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({-shortest[initial], initial});

        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();

            for (int i = 0; i < m; i++){
                int a = top.second;
                int b = a & (~edges[i].heal);
                b |= edges[i].cause;
                // cout<<b<<endl;

                if(shortest[b]>(-top.first + edges[i].d)){
                    shortest[b] = (-top.first + edges[i].d);
                    pq.push({-shortest[b], b});
                }
            }
            
        }
        if(shortest[0] == INT32_MAX) cout<<-1<<endl;
        else cout<<shortest[0]<<endl;      
    }
}