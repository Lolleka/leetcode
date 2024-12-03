// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// medium
// #tree, #depth-first-search, #binary-tree

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    struct dfsItem{
        TreeNode* node;
        dfsItem* parent;
        int level;
    };
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // keep a monotonically increasing stack of dynamically
        // instantiated dsfItem objects
        std::stack<dfsItem*> lineage;
        std::stack<dfsItem*> dfs;
        dfsItem* newDfsItem = new dfsItem{root, nullptr, 0};
        dfsItem* pItem = nullptr;
        dfsItem* qItem = nullptr;
        lineage.push(newDfsItem);
        dfs.push(newDfsItem);

        // first of all find the two nodes via dfs
        // the lineage stack will be filled with information on how to backtrack
        // each node to the root
        while(!dfs.empty()){
            dfsItem* current = dfs.top();
            dfs.pop();
            if (current->node == q) qItem = current;
            if (current->node == p) pItem = current;
            if (pItem != nullptr && qItem != nullptr) break;
            if(current->node->right){
                newDfsItem = new dfsItem{current->node->right, current, current->level+1};
                lineage.push(newDfsItem);
                dfs.push(newDfsItem);
            }
            if(current->node->left){
                newDfsItem = new dfsItem{current->node->left, current, current->level+1};
                lineage.push(newDfsItem);
                dfs.push(newDfsItem);
            }
        }
        // compare the level entries for the nodes.
        // if they are not on the same level, first check that the deeper
        // node is a descendant of the shallower node.
        // if not, backtrack till the same level as the shallower node
        // from here on backtrack both lineages to the common ancestor
        //

        dfsItem* deeper = qItem->level < pItem->level ? pItem : qItem;
        dfsItem* shallower = qItem->level < pItem->level ? qItem : pItem;
        while(deeper->level > shallower->level) deeper = deeper->parent;

        // at this point it may be that deeper = shallower
        // in this case, LCA = either deeper or shallower
        // we enforce this case by walking the lineage backwards
        while(deeper != shallower){
            deeper = deeper->parent;
            shallower = shallower->parent;
        }

        TreeNode* LCA = deeper->node;
        // cleanup
        while(!lineage.empty()) {
            delete lineage.top();
            lineage.pop();
        }
        return LCA;
    }
};


TreeNode* buildTree(std::vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size()) {
            if (nums[i]){
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
            }
            i++;
        }
        if (i < nums.size()) {
            if (nums[i]){
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}
 
void printTree(TreeNode* root) {
    if (root == nullptr)
        return;
    // Create an empty queue for level order traversal
    std::queue<TreeNode*> q;
    // Enqueue Root
    q.push(root);
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        TreeNode* node = q.front();
        q.pop();
        if (node != nullptr){
            std::cout << node->val << " " << std::endl;
            if (node->left != nullptr || node->right != nullptr){
                // Enqueue left child
                q.push(node->left);
                // Enqueue right child
                q.push(node->right);
            }
        }else{
            std::cout << "null" << std::endl;
        }
    }
}

int main(){
    std::vector<int> t1 = {3,5,1,6,2,0,8,0,0,7,4};
    TreeNode* tree1 = buildTree(t1);
    TreeNode* LCA = Solution().lowestCommonAncestor(tree1, tree1->left, tree1->right->right);
    std::cout << LCA->val << std::endl;
}
