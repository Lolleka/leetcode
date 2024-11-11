// https://leetcode.com/problems/odd-even-linked-list
// medium
// #linked-list

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
public:
    ListNode* oddEvenList(ListNode* head) {
        int i = 2;
        ListNode* odd_head = new ListNode(head->val);
        ListNode* new_list = odd_head;
        ListNode* even_start = nullptr; 
        ListNode* even_head = nullptr; 
        head = head->next;
        while(head != nullptr) {
            printList(new_list);
            ListNode* new_node = new ListNode(head->val);
            if (i % 2 == 0){
                if (even_start == nullptr){
                    even_head = even_start = new_node;
                    odd_head->next = even_start;
                }else{
                    even_head->next = new_node;
                    even_head = new_node;
                }
            } else {
                new_node->next = even_start;
                odd_head->next = new_node;
                odd_head = new_node;
            }
            head = head->next;
            i++;
        }
        return new_list;
    }
};

int main (int argc, char *argv[]) {
    /*vector<int> v = {4,2,2,3};*/
    std::vector<int> v = {1,2,3,4,5};
    v = {2,1,3,5,6,4,7};
    
    ListNode* list = make_list(v);
    printList(list);
    ListNode* new_list = Solution().oddEvenList(list);
    printList(new_list);
    return 0;
}
