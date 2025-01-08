// https://leetcode.com/problems/search-suggestions-system
// medium
// #array, #string, #binary-search, #trie, #sorting, #heap

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
#include <queue>

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
    void add_sibling(TrieNode* parent, TrieNode*node, TrieNode* sibling){
        // maintain lexographic order
        assert(node == parent->child);
        if (sibling->val < node->val){
            //swap child with sibling
            parent->child = sibling;
            sibling->sibling = node;
        }else{
            while(node->sibling && node->val < sibling->val){
                parent = node;
                node = node->sibling;
            } 
            if(node->val > sibling->val){
                parent->sibling=sibling;
                sibling->sibling=node;
            }else{
                if (node->sibling != nullptr){
                sibling->sibling = node->sibling;
                }
                node->sibling = sibling;
            }
        }
    }
    struct bfsItem{
        std::string word;
        TrieNode* node;
    };
public:
    Trie() {}

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
                TrieNode* next = lookup(root->child, word[i]);
                if (!next) {
                    TrieNode* node = new TrieNode(word[i]);
                    add_sibling(root, root->child, node);
                    root = node;
                } else root = next;
            }
        }
        root->end = true;
    }
    
    bool search(const std::string& word){
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
    
    bool startsWith(const std::string& prefix) {
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

    TrieNode* goTo(const std::string& prefix){
        if(!startsWith(prefix)) return nullptr;
        TrieNode* root = &trieroot;
        for(int i=0; i<prefix.size(); ++i)
            root = lookup(root->child, prefix[i]);
        return root;
    }

    std::vector<std::string> findAll(const std::string& prefix, const int n = 1){
        std::vector<std::string> words = {};
        std::stack<bfsItem> s;
        if(!startsWith(prefix)) return words;
        TrieNode* root = goTo(prefix);
        if (root->end)
            words.push_back(prefix);
        if (root->child !=nullptr){
            root = root->child;
            s.push({std::string(prefix)+root->val, root});
        }

        while(!s.empty()){
            bfsItem item = s.top();
            s.pop();
            if (item.node->end){
                words.push_back(item.word);
                if (words.size() == n) break;
            }
            if(item.node->sibling){
                // enqueue sibling
                std::string new_word = item.word.substr(0,item.word.size()-1)+item.node->sibling->val;
                s.push({new_word, item.node->sibling});
            }
            if(item.node->child) // enqueue child
                s.push({item.word+item.node->child->val, item.node->child});
            
        }
        return words;
    }
};

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string& searchWord) {
        Trie trie;
        for(std::string product: products) trie.insert(product);
        std::vector<std::vector<std::string>> res;
        for(int i = 1; i <= searchWord.size(); ++i){

            res.push_back(trie.findAll(searchWord.substr(0,i), 3));
        }
        return res;
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::string> products{"mobile","mouse","monitor","moneypot","mousepad"};
    std::string searchWord = "mouse";
    products = {"jhljd","e","jhljd","jyutg","crkvw","jeljd","sawxf"};
    searchWord = "j";
    for(auto list: Solution().suggestedProducts(products,searchWord)){
        for(std::string res: list){
            std::cout << res << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
