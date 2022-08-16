/*
// Definition for a Node.
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
*/

class Solution {
public:
    map<Node*,Node*> CopiedNode;
    Node* dfs(Node* node,vector<bool>& visited){
        visited[node->val] = true;
        Node* newNode = new Node(node->val);
        CopiedNode[node] = newNode;
        for(int i = 0 ; i < node->neighbors.size() ; i++){
            if(!visited[node->neighbors[i]->val])
                newNode->neighbors.push_back(dfs(node->neighbors[i],visited));
            else
                newNode->neighbors.push_back(CopiedNode[node->neighbors[i]]);
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        vector<bool> visited(101,false);
        return dfs(node,visited);
    }
};