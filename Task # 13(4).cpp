#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS_Graph(int start, vector<vector<int>> &adj, vector<bool>  &visited){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout << node << " ";
		
		for (int neighbor : adj[node]) {
			if(!visited[neighbor]){
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

int main (){
	int V = 5;
	vector<vector<int>> adj(V);
	adj[0] = {1, 2};
	adj[1] = {1, 3};
	adj[2] = {0, 4};
	adj[3] = {1};
	adj[4] = {2};
	
	vector<bool> visited(V, false);
	cout << "BFS IN Graph: ";
	return 0;
}

