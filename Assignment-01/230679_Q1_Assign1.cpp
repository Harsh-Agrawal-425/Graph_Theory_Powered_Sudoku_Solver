
// Name-Naman Patidar         Roll No-230679        Assignment 1 (ACA Project)

#include<iostream>
#include<vector>
using namespace std;

void DFS1(vector<int>adj[],int start,bool visited[]){   //DFS function
    visited[start]=true;       // Initialises start of visited array as true
    cout<<start<<" ";
    for(int u:adj[start]){     //checks every adjacent element of start
        if(visited[u]==false){      //If the adjacent element is visited, it does nothing, if not, traverse for that unvisited element
            DFS1(adj,u,visited);
        }
    }

}

void DFS(vector<int>adj[],int n,int start){
    bool visited[n];
    for(int i=0;i<n;i++){   //Initialising all the elements to zero
        visited[i]=false;
    }
    DFS1(adj,start,visited);  //Calling DFS function
}


int main(){


    int n,m;
    cout<<"Enter no of nodes- ";
    cin>>n; //No of nodes
    cout<<"Enter no of edges- ";
    cin>>m; //No of edges
    cout<<"Enter the elements of adjacency list- ";



    vector<int>adj[n+1];
    for(int i=0;i<m;i++){   //Creating adjacency list
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    /* For the given graph, the list is as follows-0
       0 -1 2
       1 - 3 4
       2 - 0 5 10 6
       3 - 7 8
       4 - 1 9             // No of nodes and edges for the given graph is 15
       5 - 2 10
       6 - 2 11 12
       7 - 3
       8 - 3
       9 - 4 13 14
      10 - 5 2
      11 - 6
      12 - 6
      13 - 9
      14 - 9 
    */

 
   // Last digit of my roll no (230679) is 9 and m(no of edges for given graph) is 15. Thus the starting node=9.
    cout<<"The DFS traversal is- ";
    DFS(adj,m,9); // Calling the DFS function which initialises a bool visited array to zero
    return 0;
}