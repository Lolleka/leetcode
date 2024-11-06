// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
// medium

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int get_length(ListNode* head){
        int n = 1;
        while(head->next) {n++; head = head->next;}
        return n;
    }
public:
    int pairSum(ListNode* head) {
        // maintain a stack of nodes up to n/2
        std::stack<ListNode*> stack;
        int n = get_length(head);
        int max_s = 0; int s = 0;
        for (int i = 0; i < n/2; ++i) {
            stack.push(head);
            head = head->next;
        }
        while(head != nullptr) {
            s = head->val + stack.top()->val;
            if (s > max_s) max_s = s;
            stack.pop(); head = head->next;
        }
        return max_s;
    }
};

void printList(ListNode* list){
    ListNode *head = list;
    while(head){
        cout << head->val << ' ';
        head=head->next;
    }
    cout << endl;
}

ListNode* make_list(vector<int>& flat_list){
    ListNode* head;
    ListNode* new_list = nullptr;
    for (auto val: flat_list){
        if (!new_list){
            head = new_list = new ListNode(val);
        }else{
            new_list->next = new ListNode(val);
            new_list = new_list->next;
        }
    }
    return head;
}

int main (int argc, char *argv[]) {
    /*vector<int> v = {4,2,2,3};*/
    vector<int> v = {10,1};
    
    ListNode* list = make_list(v);
    std::cout <<  Solution().pairSum(list) << std::endl;
    return 0;
}
