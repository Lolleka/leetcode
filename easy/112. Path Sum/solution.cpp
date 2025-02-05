// https://leetcode.com/problems/path-sum
// easy
// #tree, #depth-first-search, #breadth-first-search, #binary-tree
//
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
    bool hasPathSum(TreeNode* root, int targetSum){
        if (!root) return false;
        std::stack<TreeNode*> q;
        std::stack<int> prev_sum;
        TreeNode* current = root;
        q.push(root);
        prev_sum.push(0);
        while (!q.empty()){
            current = q.top(); q.pop();
            int current_sum = prev_sum.top() + current->val;
            prev_sum.pop();
            if (current_sum == targetSum && !current->right && !current->left) return true;
            if (current->right != nullptr){
                q.push(current->right);
                prev_sum.push(current_sum);
            }
            if (current->left != nullptr){
                q.push(current->left);
                prev_sum.push(current_sum);
            }
        }
        return false;
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
    std::vector<int> t1 = {1,2};
    int targetSum = 1;
    TreeNode* tree1 = buildTree(t1);
    std::cout << std::boolalpha << Solution().hasPathSum(tree1, targetSum) << std::endl;
}
