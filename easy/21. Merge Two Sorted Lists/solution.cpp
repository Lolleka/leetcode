// https://leetcode.com/problems/merge-two-sorted-lists/
// easy
// #linked-list, #recursion

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

ListNode* make_list(std::vector<int> flat_list){
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* new_list;
        head = new_list = nullptr;
        while(list1 != nullptr || list2 != nullptr){
            int new_val = 0;

            if(list1 != nullptr && list2 != nullptr){
                if (list1->val < list2->val){
                    new_val = list1->val;
                    list1 = list1->next;
                }else{
                    new_val = list2->val;
                    list2 = list2->next; 
                }
            }else if (list1 != nullptr){
                new_val = list1->val;
                list1 = list1->next;
            }else{
                new_val = list2->val;
                list2 = list2->next;
            }
            if (!head){
                head = new_list = new ListNode(new_val);
            } else{
                new_list->next = new ListNode(new_val);
                new_list = new_list->next;
            }
        }
        return head;     
    }
};

int main (int argc, char *argv[]) {
    ListNode* list1 = make_list({1,2,4});
    ListNode* list2 = make_list({1,3,4});
    ListNode* new_list = Solution().mergeTwoLists(list1, list2);
    printList(new_list);
    return 0;
}
