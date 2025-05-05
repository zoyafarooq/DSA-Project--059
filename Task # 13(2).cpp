#include <iostream>
#include <vector>
using namespace std;

void DFS_Graph(int node, vector<vector<int>> &adj, vector<bool> &visited){
	visited[node] = true;
	cout << node << " ";
	
	for(int neighbor : adj[node]){
		if(!visited[neighbor])
			DFS_Graph(neighbor, adj, visited);
	}
}

int main(){

	int V = 5;
	vector<vector<int>> adj(V);
	
	adj[0] = {1,2};
	adj[1] = {0,3};
	adj[2] = {0,4};
	adj[3] = {1};
	adj[4] = {2};
	
	vector<bool> visited(V, false);
	cout << " DFS in Graph: " ;
	DFS_Graph(0, adj, visited);
	cout <<  endl;
	return 0;
}

