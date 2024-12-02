// https://leetcode.com/problems/path-sum-iii
// medium
// #tree, #depth-first-search, #binary-tree

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
    int rootPathSum(TreeNode* root, int targetSum){
        int good = 0;
        std::stack<TreeNode*> q;
        std::stack<int> prev_sum;
        TreeNode* current = root;
        q.push(root);
        prev_sum.push(0);
        while (!q.empty()){
            current = q.top(); q.pop();
            int current_sum = prev_sum.top() + current->val;
            prev_sum.pop();
            if (current_sum == targetSum) good++;
            if (current->right != nullptr){
                q.push(current->right);
                prev_sum.push(current_sum);
            }
            if (current->left != nullptr){
                q.push(current->left);
                prev_sum.push(current_sum);
            }
        }
        return good;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int tot_good = 0;
        std::stack<TreeNode*> q;
        TreeNode* current = root;
        q.push(root);
        while (!q.empty()){
            current = q.top(); q.pop();
            tot_good += rootPathSum(current, targetSum);
            if (current->right != nullptr){
                q.push(current->right);
            }
            if (current->left != nullptr){
                q.push(current->left);
            }
        }
        return tot_good;
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
    std::vector<int> t1 = {10,5,-3,3,2,0,11,3,-2,0,1};
    std::vector<int> t2 = {5,4,8,11,0,13,4,7,2,0,0,5,1};
    TreeNode* tree1 = buildTree(t1);
    TreeNode* tree2 = buildTree(t2);
    std::cout << Solution().pathSum(tree1, 8) << std::endl;
    std::cout << Solution().pathSum(tree2, 22) << std::endl;
}
