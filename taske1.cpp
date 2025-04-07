//kfirgafni2005@gmail.com

#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>  
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    unordered_map<int, list<pair<int, int>>> adjList;
    unordered_set<int> validNodes;

public:
    Graph(const vector<int>& nodes) {
        for (int node : nodes) {
            validNodes.insert(node);
            adjList[node] = list<pair<int, int>>();
        }
    }

    void addEdge(int u, int v, int weight) {
        if (validNodes.count(u) == 0 || validNodes.count(v) == 0) {
            cout << "Error: One or both nodes are not in the graph. Edge not added." << endl;
            return;
        }
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    void removeEdge(int u, int v) {
        if (validNodes.count(u) == 0 || validNodes.count(v) == 0) {
            cout << "Error: One or both nodes are not in the graph. Edge not removed." << endl;
            return;
        }

        auto removeIfExists = [](auto& list, int vertex) {
            list.remove_if([vertex](const pair<int, int>& edge) { return edge.first == vertex; });
        };

        removeIfExists(adjList[u], v);
        removeIfExists(adjList[v], u);
    }

    void printGraph() const {
        for (auto& pair : adjList) {
            int vertex = pair.first;
            cout << "Vertex " << vertex << " has neighbors: ";
            for (auto& neighbor : pair.second) {
                cout << "(" << neighbor.first << ", weight = " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    const unordered_map<int, list<pair<int, int>>>& getAdjList() const {
        return adjList;
    }
};

class Algorithm {
public:
    Graph BFS(Graph& g, int root, const vector<int>& nodes) {
        Graph bfsGraph(nodes);
        unordered_map<int, bool> visited;
        queue<int> q;

        visited[root] = true;
        q.push(root);

        const auto& adj = g.getAdjList();

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& neighbor : adj.at(node)) {
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

    void DFS(const Graph& g, int node, Graph& dfsGraph, unordered_map<int, bool>& visited) {
        visited[node] = true;

        const auto& adj = g.getAdjList();

        for (auto& neighbor : adj.at(node)) {
            int adjNode = neighbor.first;
            if (!visited[adjNode]) {
                dfsGraph.addEdge(node, adjNode, neighbor.second);
                DFS(g, adjNode, dfsGraph, visited);
            }
        }
    }

    Graph DFSHelper(Graph& g, int root, const vector<int>& nodes) {
        Graph dfsGraph(nodes);
        unordered_map<int, bool> visited;
        DFS(g, root, dfsGraph, visited);
        return dfsGraph;
    }
};

int main() {
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    Graph g(nodes);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 5, 5);
    g.addEdge(3, 4, 1);

    cout << "Original Graph:" << endl;
    g.printGraph();
    cout << "-----------------------------" << endl;

    Algorithm algo;

    Graph bfsTree = algo.BFS(g, 0, nodes);
    cout << "BFS Tree from node 0:" << endl;
    bfsTree.printGraph();
    cout << "-----------------------------" << endl;

    Graph dfsTree = algo.DFSHelper(g, 0, nodes);
    cout << "DFS Tree from node 0:" << endl;
    dfsTree.printGraph();
    cout << "-----------------------------" << endl;

    return 0;
}