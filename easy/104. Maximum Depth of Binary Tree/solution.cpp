// https://leetcode.com/problems/maximum-depth-of-binary-tree
// easy
// #tree, #depth-first-search, #breadth-first-search, #binary-tree

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        std::stack<TreeNode*> q;
        std::stack<int> level;
        int max_level = 1;
        TreeNode* current = root;
        q.push(root);
        level.push(1);
        while (!q.empty()){
            current = q.top(); q.pop();
            int current_level = level.top(); level.pop();
            max_level = max_level < current_level ? current_level : max_level; 
            current_level++;
            if (current->right != nullptr){
                q.push(current->right);
                level.push(current_level);
            }
            if (current->left != nullptr){
                q.push(current->left);
                level.push(current_level);
            }
        }
        return max_level;
    }
};


TreeNode* buildTree(std::vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    /*std::cout << "root: " << nums[0] << std::endl;*/
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size()) {
            if (nums[i]){
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
                /*std::cout << "left: " << nums[i] << std::endl;*/
            }
            i++;
        }
        if (i < nums.size()) {
            if (nums[i]){
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
                /*std::cout << "right: " << nums[i] << std::endl;*/
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

int main(){
    std::vector<int> t1 = {3,9,20,0,0,15,7};
    std::vector<int> t2 = {1,0,2};
    TreeNode* tree1 = buildTree(t1);
    TreeNode* tree2 = buildTree(t2);
    std::cout << Solution().maxDepth(tree1) << std::endl;
    std::cout << Solution().maxDepth(tree2) << std::endl;
}
