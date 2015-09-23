#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    typedef UndirectedGraphNode ug;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        queue<ug *> Q1;
        queue<ug *> Q2;
        map<int, ug *> created;
        set<int> visited;
        
        Q1.push(node);
        ug *G = new ug(node->label);
        created[node->label] = G;
        visited.insert(node->label);
        Q2.push(G);
        
        while (!Q1.empty()) {
            auto cur1 = Q1.front(); Q1.pop();
            auto cur2 = Q2.front(); Q2.pop();
            
            for (int i = 0; i < cur1->neighbors.size(); ++i) {
                ug *tmp = NULL;
                if (created.find(cur1->neighbors[i]->label) == created.end()) {
                    tmp = new ug(cur1->neighbors[i]->label);
                    created[cur1->neighbors[i]->label] = tmp;
                    Q1.push(cur1->neighbors[i]);
                    Q2.push(tmp);
                } else {
                    tmp = created[cur1->neighbors[i]->label];
                }
                cur2->neighbors.push_back(tmp);
            }
        }
        return G;
    }
    
};

//struct UndirectedGraphNode {
//    int label;
//    vector<UndirectedGraphNode *> neighbors;
//    UndirectedGraphNode(int x) : label(x) {};
//};

int main(void)
{
//    UndirectedGraphNode *node = new UndirectedGraphNode(0);
//    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
//    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
//    UndirectedGraphNode *node3 = new UndirectedGraphNode(3);
//    UndirectedGraphNode *node4 = new UndirectedGraphNode(4);
//    UndirectedGraphNode *node5 = new UndirectedGraphNode(5);
//    node->neighbors.push_back(node1);
//    node->neighbors.push_back(node5);
//    
//    node1->neighbors.push_back(node2);
//    node1->neighbors.push_back(node5);
//    
//    node2->neighbors.push_back(node3);
//    
//    
//    node3->neighbors.push_back(node4);
//    node3->neighbors.push_back(node4);
//    
//    node4->neighbors.push_back(node5);
//    node4->neighbors.push_back(node5);
    
        UndirectedGraphNode *node = new UndirectedGraphNode(0);
        UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
        UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
    
    node->neighbors.push_back(node1);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);
    
    
    Solution *so = new Solution;
    
    auto ret = so->cloneGraph(node);
    
    return 0;
}
