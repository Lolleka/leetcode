//
// medium
#include <iostream>
#include <string>

struct TrieNode{
    char val;
    bool end;
    TrieNode* sibling;
    TrieNode* child;    
    TrieNode(char x) : val(x), sibling(nullptr), child(nullptr), end(false) {}
    TrieNode(char x, TrieNode*sibling, TrieNode*child) : val(x), sibling(sibling), child(child), end(false) {}
};

class Trie {
    TrieNode* trieroot;

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
        TrieNode* root = trieroot;
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
        return false;
    }
    
    bool startsWith(std::string prefix) {
        return false;
    }
};

int main (int argc, char *argv[]) {
    std::string s = "caro";
    std::string g = "core";
    Trie t;
    t.insert(s); t.insert(g);
    
    return 0;
}
