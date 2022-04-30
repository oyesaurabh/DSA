// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include<bits/stdc++.h> 
using namespace std; 

bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool>& visited) {
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);
 
    queue<int> q;

    visited[s] = true;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if(parent[u] != v)
                return true;
        }
    }
    return false;
}
 
 
bool isCyclicDisconntected(vector<int> adj[], int V) {
    
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for(int i = 0; i < V; i++)
        if(!visited[i] && isCyclicConntected(adj, i, V, visited))
            return true;
    return false;
}


void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main() { 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	// addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,3,5);
	// addEdge(adj,2,3);

    if (isCyclicDisconntected(adj, V))
        cout << "Yes";
    else
        cout << "No";

	return 0; 
} 