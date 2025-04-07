#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));  
        adjList[v].push_back(make_pair(u, weight));  
    }

    void removeEdge(int u, int v) {
        auto removeIfExists = [](auto& list, int vertex) {
            list.remove_if([vertex](const pair<int, int>& edge) { return edge.first == vertex; });
        };
    
        removeIfExists(adjList[u], v);
        removeIfExists(adjList[v], u);
    }

    void printGraph() {
        for (auto& pair : adjList) {
            int vertex = pair.first;
            cout << "Vertex " << vertex << " has neighbors: ";
            for (auto& neighbor : pair.second) {
                cout << "(" << neighbor.first << ", weight = " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

class Algorithm {
public:
    Graph BFS(Graph& g, int root) {
        Graph bfsGraph;
        unordered_map<int, bool> visited;
        queue<int> q;

        visited[root] = true;
        q.push(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& neighbor : g.adjList[node]) {
                int adjNode = neighbor.first;
                if (!visited[adjNode]) {
                    visited[adjNode] = true;
                    bfsGraph.addEdge(node, adjNode, neighbor.second); 
                    q.push(adjNode);
                }
            }
        }
        return bfsGraph;  
    }

    void DFS(Graph& g, int node, Graph& dfsGraph, unordered_map<int, bool>& visited) {
        visited[node] = true;

        for (auto& neighbor : g.adjList[node]) {
            int adjNode = neighbor.first;
            if (!visited[adjNode]) {
                dfsGraph.addEdge(node, adjNode, neighbor.second);  
                DFS(g, adjNode, dfsGraph, visited);
            }
        }
    }

    Graph DFSHelper(Graph& g, int root) {
        Graph dfsGraph;
        unordered_map<int, bool> visited;

        DFS(g, root, dfsGraph, visited); 
        return dfsGraph;  
    }

};


