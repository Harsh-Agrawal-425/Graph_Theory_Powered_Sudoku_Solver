/*
1. Construct an adjacency list representation of the given graph.
2. Implement the DFS algorithm to traverse the graph starting from a vertex determined 
by the last digit of your roll number. Specifically, if the last digit of your 
roll number is i, start the DFS traversal from vertex i.
Example: If your roll number is 220425, 
you should start the DFS traversal from vertex 5.
3. Print the order of vertices visited during the DFS traversal.
*/

#include<iostream>
#include<vector>
#include <list>
#include <stack>

using namespace std;

// function to traverse the graph using a stack
void DFS(vector<vector<int> >& adj, int start) {
    // array of 0/1 to track what node has been visited
    vector<bool> visited(adj.size(), false);
    // stack to keep track of path
    stack<int> s;
    // we start at one node (here, 5)
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            // we print the node we're at
            cout << node << " ";
            // and record that we visited it
            visited[node] = true;
        }

        // now, from the adjacency list, 
        // we explore the neighbours not visited
        for (int subnodes : adj[node]) {
            if (!visited[subnodes]) {
                s.push(subnodes);
        // now, in the next iterations, 
        // one of the neighbours, and their tree
        // will be visited
        // when we exhaust that tree
        // next neighbour's tree is visited
    }
        }
    }
}

/*
recursive implementation

logic: print a node, call neighbour, print, neighbour... return 
*/

void DFS_recc(vector<vector<int> >& adj, int start, vector<bool>& visited ){
    cout << start << " ";
    visited[start] = true;

    for (int nbs : adj[start]){
        if (!visited[nbs]){
            DFS_recc(adj, nbs, visited);
        }   
    }
}


int main(){

    // graph in adjacency list
    vector<vector<int> > adj(15); // Initialize with 15 empty vectors
    adj[0].push_back(1);
    adj[0].push_back(2);         // node 0

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);         // node 1

    adj[2].push_back(0);
    adj[2].push_back(5);
    adj[2].push_back(6);         // node 2

    adj[3].push_back(1);
    adj[3].push_back(7);
    adj[3].push_back(8);         

    adj[4].push_back(1);
    adj[4].push_back(9);         

    adj[5].push_back(2);
    adj[5].push_back(10);        

    adj[6].push_back(2);
    adj[6].push_back(11);
    adj[6].push_back(12);        

    adj[7].push_back(3);         

    adj[8].push_back(3);         

    adj[9].push_back(4);
    adj[9].push_back(13);
    adj[9].push_back(14);        

    adj[10].push_back(5);        

    adj[11].push_back(6);        

    adj[12].push_back(6);        

    adj[13].push_back(9);        

    adj[14].push_back(9);        // node 14

    // printing 
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Node " << i << ":";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << " " << adj[i][j];
        }
        cout << endl;
    }

    // calling
    // roll num 230145

    cout << "Stack implementation :" << endl;
    DFS(adj, 5);

    cout << "" << endl;

    cout << "Recursive implementation :" << endl;
    vector<bool> visited(adj.size(), false);
    DFS_recc(adj, 5, visited);

    return 0;
}

/*
OUTPUT:

[Running] cd "/Users/anishananda/Desktop/C++/Sudoku solver/Assignment1_DFS/" && g++ ACA_GTPSS_A1.cpp -o ACA_GTPSS_A1 && "/Users/anishananda/Desktop/C++/Sudoku solver/Assignment1_DFS/"ACA_GTPSS_A1
ACA_GTPSS_A1.cpp:40:27: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (int subnodes : adj[node]) {
                          ^
ACA_GTPSS_A1.cpp:63:18: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
    for (int nbs : adj[start]){
                 ^
2 warnings generated.
Node 0: 1 2
Node 1: 0 3 4
Node 2: 0 5 6
Node 3: 1 7 8
Node 4: 1 9
Node 5: 2 10
Node 6: 2 11 12
Node 7: 3
Node 8: 3
Node 9: 4 13 14
Node 10: 5
Node 11: 6
Node 12: 6
Node 13: 9
Node 14: 9
Stack implementation :
5 10 2 6 12 11 0 1 4 9 14 13 3 8 7 
Recursive implementation :
5 2 0 1 3 7 8 4 9 13 14 6 11 12 10 
[Done] exited with code=0 in 0.609 seconds
*/
