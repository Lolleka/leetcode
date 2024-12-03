//
// medium
//  #tree, #depth-first-search, #breadth-first-search, #binary-tree

#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(std::vector<std::string>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(std::stoi(nums[0]));
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size()) {
            if (nums[i]!="null"){
                curr->left = new TreeNode(std::stoi(nums[i]));
                q.push(curr->left);
            }
            i++;
        }
        if (i < nums.size()) {
            if (nums[i]!="null"){
                curr->right = new TreeNode(std::stoi(nums[i]));
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
        std::cout << node->val << " " << std::endl;
        q.pop();
        // Enqueue left child
        if (node->left != nullptr)
            q.push(node->left);
        // Enqueue right child
        if (node->right != nullptr)
            q.push(node->right);
    }
}

class Solution {
    struct bfsNode{
        TreeNode* node;
        int level;
    };
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<bfsNode> q;
        std::vector<int> sums;
        if (root == nullptr) return 0;
        // Enqueue Root
        q.push(bfsNode{root, 0});
        while (q.empty() == false) {
            // Print front of queue and remove it from queue
            bfsNode node = q.front();
            if (sums.size() <= node.level) sums.push_back(node.node->val);
            else sums[node.level] += node.node->val;
            q.pop();
                
            // Enqueue right child first
            if (node.node->right != nullptr){
                q.push(bfsNode{node.node->right, node.level+1});
            }

            // Enqueue left child second
            if (node.node->left != nullptr){
                q.push(bfsNode{node.node->left, node.level+1});
            }
        }
        int max = -100000;
        int maxLevel = 0;
        for(int i = sums.size()-1; i >= 0; --i){
            std::cout << i+1 << ": " << sums[i] << std::endl;
            if(sums[i] >= max){
                max = sums[i];
                maxLevel = i;
            }
        }

        return maxLevel+1;
    }
};


int main (int argc, char *argv[]) {
    std::vector<std::string> t = {"1","7","0","7","-8","null","null"};
    t = {"989","null","10250","98693","-89388","null","null","null","-32127"};
    t = {"-100","-200","-300","-20","-5","-10","null"};
    TreeNode* tree = buildTree(t);
    std::cout << Solution().maxLevelSum(tree) << std::endl;
    return 0;
}
