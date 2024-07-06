#include<iostream>
#include<vector>
#include <vector>
#include <queue> // for priority_queue
#include <utility> // for std::pair

using namespace std;

void dijkstra(const vector<vector<pair<int, int> > >& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max()); // everything intialised to inf
    dist[src] = 0; // except startign point

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, src)); // stores the dist to starting pt : (dist, node)

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // shortest distances from the source node
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Node " << i << ": unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

}


int main(){
    // Using a small graph
    // Graph in adjacency list format
    vector<vector<pair<int, int> > > adj(7); // Initialize with 7 empty vectors for 7 nodes (0 to 6)

    // Adding edges (node, weight)
    
    adj[0].push_back(make_pair(1, 2));
    adj[0].push_back(make_pair(2, 4));         // Node 0

    adj[1].push_back(make_pair(0, 2));
    adj[1].push_back(make_pair(5, 5));         // Node 1

    adj[2].push_back(make_pair(0, 4));
    adj[2].push_back(make_pair(3, 3));         // Node 2

    adj[3].push_back(make_pair(2, 3));
    adj[3].push_back(make_pair(4, 5));
    adj[3].push_back(make_pair(5, 2));
    adj[3].push_back(make_pair(6, 4));         // Node 3

    adj[4].push_back(make_pair(3, 5));         // Node 4

    adj[5].push_back(make_pair(1, 5)); 
    adj[5].push_back(make_pair(3, 2));
    adj[5].push_back(make_pair(6, 1));         // Node 5

    adj[6].push_back(make_pair(3, 4));
    adj[6].push_back(make_pair(5, 1));  

    // the adjacency list
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Node " << i << ":";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << " (" << adj[i][j].first << ", " << adj[i][j].second << ")";
        }
        cout << endl;
    }

    dijkstra(adj, 0);

    return 0;
}


/*
OUTPUT:

cd "/Users/anishananda/Desktop/C++/Sudoku solver/Assignment 2/code/" && g++ a2_q1.cpp -o a2_q1 && "/Users/anishananda/Desktop/C++/Sudoku solver/Assignment 2/code/"a2_q1
a2_q1.cpp:21:20: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
        for (const auto& neighbor : adj[u]) {
                   ^
a2_q1.cpp:21:35: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (const auto& neighbor : adj[u]) {
                                  ^
2 warnings generated.
Node 0: (1, 2) (2, 4)
Node 1: (0, 2) (5, 5)
Node 2: (0, 4) (3, 3)
Node 3: (2, 3) (4, 5) (5, 2) (6, 4)
Node 4: (3, 5)
Node 5: (1, 5) (3, 2) (6, 1)
Node 6: (3, 4) (5, 1)
Shortest distances from node 0:
Node 0: 0
Node 1: 2
Node 2: 4
Node 3: 7
Node 4: 12
Node 5: 7
Node 6: 8

[Done] exited with code=0 in 1.098 seconds
*/