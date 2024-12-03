// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
// medium
// #dynamic-programming, #dp, #tree, #depth-first-search, #binary-tree

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

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
        bool left;
        int streak;
    };
public:
    int longestZigZag(TreeNode* root) {
        // do a depth-first search to put all leaves in a stack, then compare the stacks. 
        if (root == nullptr) return 0;
        std::stack<dfsItem> stack;
        if(root->left){
            stack.push(dfsItem{root->left, true, 1});
        }
        if(root->right){
            stack.push(dfsItem{root->right, false, 1});
        }

        int max_streak = 0;
        while(!stack.empty()){
            dfsItem current = stack.top();
            stack.pop();
            if(current.streak > max_streak) max_streak = current.streak;
            std::cout << current.streak << " max: " << max_streak << std::endl;
            if (current.left){
                if(current.node->right)
                    stack.push(dfsItem{current.node->right, false, current.streak+1});
                if(current.node->left)
                    stack.push(dfsItem{current.node->left, false, 1});
            }else{
                if(current.node->right)
                    stack.push(dfsItem{current.node->right, false, 1});
                if(current.node->left)
                    stack.push(dfsItem{current.node->left, true, current.streak+1});
            }
        }
        return max_streak;
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
    std::vector<int> t1 = {1,1,1,0,1,0,0,1,1,0,1};
    TreeNode* tree1 = buildTree(t1);
    std::cout << Solution().longestZigZag(tree1) << std::endl;
}
