// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
// medium
// #linked-list, #two-pointers

#include <iostream>
#include <vector>

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
    ListNode* deleteMiddle(ListNode* head) {
        int n = getLength(head);
        if (n <= 1) return nullptr;
        int m = (n / 2); 
        ListNode* pre_middle = head;
        for(int i = 0; i < m-1; ++i){
            pre_middle = pre_middle->next; 
        }
        ListNode* middle = pre_middle->next;
        pre_middle->next = middle->next;
        return head;
    }
};

class Solution2 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow->next != nullptr && fast->next->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        slow->next = middle->next;
        return head;
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
    ListNode* new_list = Solution().deleteMiddle(list);
    printList(new_list);
    return 0;
}
