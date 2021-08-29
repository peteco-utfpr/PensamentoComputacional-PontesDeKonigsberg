#include "graph.h"
#include <stdio.h>
Node::Node(int dstID, Node* next, Bridge* linkedBridge){
    this->dstID = dstID;
    this->next = next;
    this->linkedBridge = linkedBridge;
}

Node::~Node(){

}

Graph::Graph(int vertices){
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

void Graph::iterateBySource(int srcID){
    it = adjList[srcID];
}

Node* Graph::getNextNode(){
    Node* value = nullptr;

    if(it){
        value = it;
        it = it->next;
    }
    return value;
}