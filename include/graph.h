#ifndef GRAPH_H
#define GRAPH_H

class Bridge;

struct Node{
    int dstID;
    Node* next;
    Bridge* linkedBridge;

    Node(int dstID = -1, Node* next = nullptr, Bridge* linkedBridge = nullptr);
    ~Node();
};


class Graph{

    private:
        int vertices;
        Node** adjList;
        Node* it;

    public:
        Graph(int vertices = 0);
        ~Graph();

        void addEdge(int srcID, int dstID, bool directed, Bridge* linkedBridge);
        void iterateBySource(int srcID);
        Node* getNextNode();


};

#endif