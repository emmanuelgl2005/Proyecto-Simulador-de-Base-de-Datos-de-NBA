/*
 * heap.h
 *
 *  Created on: 18/11/2025
 *      Author: Emmanuel Garcia Lopez
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct HeapNode {
    int rk;
    string team;
    float _3Ppercent;
    float _2Ppercent;
    int priority; // 1 si es favorito, 0 si no
    
    HeapNode(int ranking, const string& equipo, float p3, float p2, int prio = 0)
        : rk(ranking), team(equipo), _3Ppercent(p3), _2Ppercent(p2), priority(prio) {}
};

class MaxHeap {
private:
    vector<HeapNode> heap;
    
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    int leftChild(int i) {
        return 2 * i + 1;
    }
    
    int rightChild(int i) {
        return 2 * i + 2;
    }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)].priority < heap[i].priority) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left].priority > heap[largest].priority) {
            largest = left;
        }
        
        if (right < heap.size() && heap[right].priority > heap[largest].priority) {
            largest = right;
        }
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    MaxHeap() {}
    
    void insert(int rk, const string& team, float p3, float p2, int priority = 0) {
        heap.push_back(HeapNode(rk, team, p3, p2, priority));
        heapifyUp(heap.size() - 1);
    }
    
    HeapNode extractMax() {
        if (heap.empty()) {
            throw runtime_error("Heap vacio");
        }
        HeapNode maxNode = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return maxNode;
    }
    
    HeapNode getMax() const {
        if (heap.empty()) {
            throw runtime_error("Heap vacio");
        }
        return heap[0];
    }
    
    bool isEmpty() const {
        return heap.empty();
    }
    
    void updatePriority(const string& teamName, int newPriority) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i].team == teamName) {
                heap[i].priority = newPriority;
                if (newPriority > 0) {
                    heapifyUp(i);
                } else {
                    heapifyDown(i);
                }
                return;
            }
        }
    }
    
    void displayAll() const {
        if (heap.empty()) {
            cout << "No hay equipos en el heap." << endl;
            return;
        }
        cout << "\n==== Equipos (ordenados por prioridad) ====" << endl;
        for (const HeapNode& node : heap) {
            string favorito = (node.priority == 1) ? "[FAVORITO]" : "";
            cout << "Team: " << node.team << " " << favorito 
                << " | 3P%: " << node._3Ppercent 
                << " | 2P%: " << node._2Ppercent 
                << " | Ranking: " << node.rk << endl;
        }
    }
    
    int size() const {
        return heap.size();
    }
};

#endif /* HEAP_H_ */