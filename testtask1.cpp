//kfirgafni2005@gmail.com

#include <iostream>
#include <cassert>
#include "taske1.cpp"  

using namespace std;

void testAddEdge() {
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    Graph g(nodes);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);

    auto adjList = g.getAdjList();
    assert(adjList.at(0).size() == 2);  
    assert(adjList.at(1).size() == 2);  
    cout << "testAddEdge passed!" << endl;
}

void testRemoveEdge() {
    vector<int> nodes = {0, 1, 2, 3};
    Graph g(nodes);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);

    g.removeEdge(0, 1);  

    auto adjList = g.getAdjList();
    assert(adjList.at(0).size() == 1);  
    assert(adjList.at(1).size() == 1);  
    cout << "testRemoveEdge passed!" << endl;
}

void testBFS() {
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    Graph g(nodes);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 5, 5);
    g.addEdge(3, 4, 1);

    Algorithm algo;
    Graph bfsTree = algo.BFS(g, 0, nodes);

    auto adjList = bfsTree.getAdjList();
    assert(adjList.at(0).size() == 2);  
    assert(adjList.at(1).size() == 1);  
    cout << "testBFS passed!" << endl;
}

void testDFS() {
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    Graph g(nodes);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 5, 5);
    g.addEdge(3, 4, 1);

    Algorithm algo;
    Graph dfsTree = algo.DFSHelper(g, 0, nodes);

    auto adjList = dfsTree.getAdjList();
    assert(adjList.at(0).size() == 2);  
    assert(adjList.at(1).size() == 1);  
    cout << "testDFS passed!" << endl;
};
