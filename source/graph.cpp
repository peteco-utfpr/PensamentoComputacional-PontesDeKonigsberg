#include "graph.h"

Node::Node(int id, Node* next, Bridge* linkedBridge){
    this->id = id;
    this->next = nullptr;
    this->linkedBridge = nullptr;
}

Node::~Node(){

}

Graph::Graph(int vertices = 0){
    this->vertices = vertices;

    adjList = new Node*[vertices];
    
    for(int i = 0; i < vertices; i++)
        adjList[i] = nullptr;
}

Graph::~Graph(){
    for(int i = 0; i < vertices; i++){//deletes every node in the list
        Node* it = adjList[i];
        Node* prv;
        while(it != nullptr){
            prv = it;
            it  = it->next;
            delete prv;     
        }
    }

    delete[] adjList;
}

void Graph::addEdge(int srcID, int dstID, bool directed, Bridge* linkedBridge){

    Node* newNode = new Node(dstID, adjList[srcID], linkedBridge);
    adjList[srcID] = newNode;

    if(!directed){
        Node* newNode = new Node(srcID, adjList[dstID], linkedBridge);
        adjList[dstID] = newNode;
    }
}