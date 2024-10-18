// https://leetcode.com/problems/leaf-similar-trees
// easy

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
    std::stack<TreeNode*> getLeavesStack(TreeNode* root){
        std::stack<TreeNode*> q;
        std::stack<TreeNode*> leaves;
        TreeNode* current = root;
        q.push(root);
        int i = 1;
        while (!q.empty()){
            current = q.top(); q.pop();
            if ((current->left == nullptr) && (current->right == nullptr)){
                leaves.push(current);
            }
            if (current->right != nullptr){
                q.push(current->right);
            }
            if (current->left != nullptr){
                q.push(current->left);
            }
        }
        return leaves;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // do a depth-first search to put all leaves in a stack, then compare the stacks. 
        std::stack<TreeNode*> leaves1, leaves2;
        leaves1 = getLeavesStack(root1);
        leaves2 = getLeavesStack(root2);
        while(!leaves1.empty() && !leaves2.empty()){
            if(leaves1.top()->val == leaves2.top()->val){
                leaves1.pop();
                leaves2.pop();
            }else break;
        }
        return leaves1.empty() && leaves2.empty();
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
    std::vector<int> t1 = {4,2,6,1,3,5,7};
    std::vector<int> t2 = {4,2,6,0,3,5,7};
    TreeNode* tree1 = buildTree(t1);
    TreeNode* tree2 = buildTree(t2);
    std::cout << std::boolalpha << Solution().leafSimilar(tree1, tree2) << std::endl;
}
