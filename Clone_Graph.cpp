class Solution {
public:
    
    Node* dfs(Node* current, unordered_map<Node*,Node*> &mp){
        Node* node = new Node(current->val);
        mp[current] = node;
        for(auto it: current->neighbors){
            if(mp.find(it) != mp.end()){
                node->neighbors.push_back(mp[it]);
            }
            else{
               node->neighbors.push_back(dfs(it,mp));
            }
        }
        return node; 
    }
    
    Node* cloneGraph(Node* node){
        unordered_map<Node*,Node*> mp;
        if(node == NULL){
            return NULL;
        }
        return dfs(node,mp);
    }
};