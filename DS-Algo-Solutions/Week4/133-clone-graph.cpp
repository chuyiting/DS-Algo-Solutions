//
//  133-clone-graph.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/27.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Edge {
public:
    int n1;
    int n2;
    Edge(int n1, int n2) {
        this->n1 = min(n1, n2);
        this->n2 = max(n1, n2);
    }
    
    bool operator==(const Edge& other) const {
        return this->n1 == other.n1 && this->n2 == other.n2;
    }
    
    struct Hash {
        size_t operator()(const Edge& e) const {
            if (e.n1 < e.n2) {
                return (e.n1 << 16) | e.n2;
            }
            
            return (e.n2 << 16) | e.n1;
        }
    };
    
};


class Solution {
public:
    
    unordered_set<Edge, Edge::Hash> visited;
    unordered_map<int, Node*> clone_nodes;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (clone_nodes.find(node->val) != clone_nodes.end()) {
            return clone_nodes[node->val];
        }
        Node* clone = new Node(node->val);
        clone_nodes[node->val] = clone;
        
        for (auto *neighbor: node->neighbors) {
            Edge edge{node->val, neighbor->val};
            if (visited.find(edge) != visited.end()) continue;
            visited.insert(edge);
            Node *clone_child = cloneGraph(neighbor);
            if (clone_child) {
                clone->neighbors.push_back(clone_child);
                clone_child->neighbors.push_back(clone);
            }
        }
        
        return clone;
    }
};

// shorter solution
class Solution2 {
public:
    
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.find(node) != visited.end()) return visited[node];
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        for (auto *neighbor: node->neighbors) {
            Node *clone_child = cloneGraph(neighbor);
            if (clone_child) {
                clone->neighbors.push_back(clone_child);
            }
        }
        
        return clone;
    }
};
