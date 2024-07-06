/*
There are n cities and m flight connections between them. 
Your task is to determine the length of the shortest route 
from Syrjälä to every city.

Input
The first input line has two integers n and m: 
the number of cities and flight connections. 

The cities are numbered 1,2,...,n, and city 1 is Syrjälä.
After that, there are m lines describing the flight connections. 
Each line has three integers a, b and c: 
a flight begins at city a, ends at city b, and its length is c. 
Each flight is a one-way flight.
You can assume that it is possible to travel from Syrjälä 
to all other cities.

Output
Print n integers: 
the shortest route lengths from Syrjälä to cities 1,2,...,n.

Example
Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void dijkstra(const vector<vector<pair<int, int> > >& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max()); // everything initialized to inf
    dist[src] = 0; // except starting point

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, src)); // stores the dist to starting pt: (dist, node)

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
    for (int i = 1; i < n; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Node " << i << ": unreachable";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main(){

    int cities, flights;

    cin >> cities >> flights;

    vector<vector<pair<int, int> > > chart(cities + 1);
    int c1, c2, l;

    for (int i = 0; i<flights; i++){

        cin >> c1 >> c2 >> l ;
        chart[c1].push_back(make_pair(c2, l));
        //cout << c1 << c2 << l << endl;

    }

    dijkstra(chart, 1);
    //bellmanford(chart,1);

    return 0 ;
}

