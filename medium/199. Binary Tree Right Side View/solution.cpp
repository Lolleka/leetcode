// https://leetcode.com/problems/binary-tree-right-side-view/
// medium

#include <iostream>
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

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::queue<int> l;
        std::vector<int> v;
        if (root == nullptr) return v;
        // Enqueue Root
        q.push(root);
        l.push(1);
        v.push_back(root->val);
        while (q.empty() == false) {
            // Print front of queue and remove it from queue
            TreeNode* node = q.front();
            int level = l.front();
            if (v.size() < level) v.push_back(node->val);
            /*std::cout << node->val << " " << std::endl;*/
            q.pop();
            l.pop();
                
            // The following queueing order ensures we are
            // traversing from right to left using a FIFO queue
            
            // Enqueue right child first
            if (node->right != nullptr){
                l.push(level+1);
                q.push(node->right);
            }

            // Enqueue left child second
            if (node->left != nullptr){
                l.push(level+1);
                q.push(node->left);
            }
        }
        return v;
    }
};


int main(){
    std::vector<int> t1 = {1,0,3};
    std::vector<int> t2 = {1,2,3,0,5,0,4};

    TreeNode* tree1 = buildTree(t1);
    TreeNode* tree2 = buildTree(t2);
    std::vector<int> v = Solution().rightSideView(tree2);
    for (int i: v) std::cout << i << std::endl;
    v = Solution().rightSideView(tree1);
    for (int i: v) std::cout << i << std::endl;
}
