// https://leetcode.com/problems/delete-node-in-a-bst/
// medium
// #tree, #binary-search, #binary-tree

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        
        if (root->val != key){
            //continue search in both branches
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
        } else {
            // prefer returning right, greater elements
            // we can safely return the left subtree if no right
            // tree is found
            if (root->right == nullptr) return root->left;
            // likewise if no left tree is found, only the right
            // can be returned
            else if (root->left == nullptr) return root->right;
            // if we need to choose, we can find
            // the maximum in the left tree, safely set it as
            // the current root value, and then delete the node
            // with the same key in the subtree
            TreeNode* current = root->left;
            while(current->right != nullptr) current = current->right;
            root->val = current->val;
            root->left = deleteNode(root->left, root->val);
        }
        return root;
    }
};


int main(){
    std::vector<int> t1 = {5,3,6,2,4,0,7};
    TreeNode* tree1 = buildTree(t1);
    printTree(tree1);
    std::cout << std::endl;
    TreeNode* tree2 = Solution().deleteNode(tree1, 5);
    printTree(tree2);
}
