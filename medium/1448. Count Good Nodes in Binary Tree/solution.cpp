// https://leetcode.com/problems/count-good-nodes-in-binary-tree
// medium
// #tree, #depth-first-search, #breadth-first-search, #binary-tree
//
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

truct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {

        std::stack<TreeNode*> q;
        std::stack<int> max;
        int current_max;
        TreeNode* current = root;
        int good = 0;
        q.push(root);
        max.push(root->val);
        while (!q.empty()){
            current = q.top(); q.pop();
            current_max = max.top(); max.pop();
            int new_max = current_max < current->val ? current->val : current_max; 
            std::cout << current->val << "," << current_max; 
            if (current->val >= current_max){
                good++;
                std::cout << " good";
            }
            std::cout << std::endl;
            if (current->right != nullptr){
                q.push(current->right);
                max.push(new_max);
            }
            if (current->left != nullptr){
                q.push(current->left);
                max.push(new_max);
            }
        }
        return good;
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
    std::vector<int> t1 = {3,1,4,3,0,1,5};
    std::vector<int> t2 = {4,2,6,0,3,5,7};
    TreeNode* tree1 = buildTree(t1);
    TreeNode* tree2 = buildTree(t2);
    std::cout << Solution().goodNodes(tree1) << std::endl;
}
