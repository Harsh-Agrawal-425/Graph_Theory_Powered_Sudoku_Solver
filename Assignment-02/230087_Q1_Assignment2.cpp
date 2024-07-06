#include<iostream>
#include<vector>
#include<list>
#include<limits>
#include<queue>
using namespace std;

class Graph{

    public:
        vector<long> dijkstra(list<pair<int,long> > adj[], int N){
            vector<long> dstance(N, numeric_limits<long>::max());
            priority_queue<pair<long,int>, vector<pair<long, int>>, greater<pair<long,int>>> p;
            p.push(make_pair(0, 0));
            dstance[0] = 0;

            while(!p.empty()){
                int u = p.top().second;
                long d = p.top().first;
                p.pop();
                if(dstance[u]<d){
                    continue;
                }

                list<pair<int,long>> :: iterator i;
                for(i = adj[u].begin(); i != adj[u].end(); i++){
                    int v = (*i).first;
                    int wt = (*i).second;

                    if(dstance[v] > dstance[u] + wt){
                        dstance[v] = dstance[u] + wt;
                        p.push(make_pair(dstance[v], v));
                    }
                }
            }
            return dstance;
        }
};

// void printGraph(list<pair<int,int> > adj[], int N)
// {
//     int n, w;
//     for (int u = 0; u < N; u++)
//     {
//         cout << "Node " << u << " makes an edge with \n";
//         for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
//         {
//             n = it->first;
//             w = it->second;
//             cout << "\tNode " << n << " with edge weight = "
//                  << w << "\n";
//         }
//         cout << "\n";
//     }
// }

void add_Edge(list <pair<int, long> > adj[], int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
}

int main(){

    int n, m;
    cin >> n >> m;
    list<pair<int,long>> adj[n];

    for(int i = 0; i < m; i++){
        int u, v;
        long wt;
        cin >> u >> v >> wt;
        add_Edge(adj, u-1, v-1, wt);
    }

    Graph g;

    vector<long> ans = g.dijkstra(adj, n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    // printGraph(adj, n);

    return 0;
}