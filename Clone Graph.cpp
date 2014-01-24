/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
这里只能克隆连通图（当然）
方法：从一个点开始克隆，然后开始neighbor的克隆，用一个map记录visited，避免重复访问
*/
class Solution {
private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        if(visited[node]){
            return visited[node];
        }
        UndirectedGraphNode *first_node = new UndirectedGraphNode(node->label);
        visited[node] = first_node;
        for(int i=0; i<node->neighbors.size(); i++){
            first_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        
        return first_node;
    }
};