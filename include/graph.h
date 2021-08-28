#ifndef GRAPH_H
#define GRAPH_H

class Bridge;

struct Node{
    int id;
    Node* next;
    Bridge* linkedBridge;

    Node(int id = -1, Node* next = nullptr, Bridge* linkedBridge = nullptr);
    ~Node();
};


class Graph{

    private:
        int vertices;
        Node** adjList;

    public:
        Graph(int vertices = 0);
        ~Graph();

        void addEdge(int srcID, int dstID, bool directed, Bridge* linkedBridge);


};

#endif