// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
// easy
// #linked-list, #two-pointers
//
#include <iostream>
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* list){
    ListNode *head = list;
    while(head){
        std::cout << head->val << ' ';
        head=head->next;
    }
    std::cout << std::endl;
}

ListNode* make_list(std::vector<int>& flat_list){
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

class Solution {
    int getLength(ListNode* head){
        int n = 1;
        while(head->next) {n++; head = head->next;}
        return n;
    }
public:
    ListNode* reverseList(ListNode* head) {
        std::stack<ListNode*> st;
        if (head == nullptr || head->next == nullptr) return head;
        while(head) {st.push(head); head = head->next;}
        ListNode* new_list = st.top();
        st.pop();
        ListNode* new_head = new_list;
        while(!st.empty()){
            new_head->next = st.top();
            st.pop();
            new_head = new_head->next;
        }
        new_head->next = nullptr;
        return new_list;
    }
};

int main (int argc, char *argv[]) {
    /*vector<int> v = {4,2,2,3};*/
    std::vector<int> v = {1,2,3,4,5};
    v = {2,1,3,5,6,4,7};
    /*v = {1};*/
    /*v = {5,6,4,7};*/
    
    ListNode* list = make_list(v);
    printList(list);
    ListNode* new_list = Solution().reverseList(list);
    printList(new_list);
    return 0;
}
