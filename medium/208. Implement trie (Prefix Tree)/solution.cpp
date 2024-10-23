// https://leetcode.com/problems/implement-trie-prefix-tree
// medium
#include <iostream>
#include <string>

struct TrieNode{
    char val;
    bool end;
    TrieNode* sibling;
    TrieNode* child;    
    TrieNode() : val(0), sibling(nullptr), child(nullptr), end(false) {}
    TrieNode(char x) : val(x), sibling(nullptr), child(nullptr), end(false) {}
    TrieNode(char x, TrieNode*sibling, TrieNode*child) : val(x), sibling(sibling), child(child), end(false) {}
};

class Trie {
    TrieNode trieroot;

    TrieNode* lookup(TrieNode* parent, char val){
        if (parent->val == val) return parent;
        while(parent->sibling){
            parent = parent->sibling;
            if (parent->val == val) return parent;
        }
        return nullptr;
    }
    void add_sibling(TrieNode* node, TrieNode* sibling){
        while(node->sibling){
            node = node ->sibling;
        }
        node->sibling = sibling;
    }
public:
    Trie() {
        
    }
    
    void insert(std::string word) {
        if (!word.size()) {
            return;
        }
        TrieNode* root = &trieroot;
        for(int i=0; i<word.size(); ++i){
            if(!root->child){
                TrieNode* newnode = new TrieNode(word[i]);
                root->child = newnode;
                root = newnode;
            }else{
                root = root->child;
                TrieNode* next = lookup(root, word[i]);
                if (!next) {
                    TrieNode* node = new TrieNode(word[i]);
                    add_sibling(root, node);
                    root = node;
                } else root = next;
            }
        }
        root->end = true;
    }
    
    bool search(std::string word) {
        if (!word.size()) return false;
        TrieNode* root = &trieroot;
        for(int i=0; i<word.size(); ++i){
            if(root->child){
                TrieNode* next = lookup(root->child, word[i]);
                if (!next) return false;
                else root = next;
            } else return false;
        }
        return root->end;
    }
    
    bool startsWith(std::string prefix) {
        if (!prefix.size()) return false;
        TrieNode* root = &trieroot;
        for(int i=0; i<prefix.size(); ++i){
            if(root->child){
                TrieNode* next = lookup(root->child, prefix[i]);
                if (!next) return false;
                else root = next;
            } else return false;
        }
        return true;
    }
};

int main (int argc, char *argv[]) {
    std::string s = "caro";
    std::string g = "core";
    Trie t;
    t.insert(s); t.insert(g);
    std::cout << std::boolalpha << t.startsWith("cor") << std::endl;
    
    return 0;
}
