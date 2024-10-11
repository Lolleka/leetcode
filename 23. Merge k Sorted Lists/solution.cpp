// https://leetcode.com/problems/vt/merge-k-sorted-lists/
// hard

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int total_size = 0;
        bool done = false;
        ListNode* out = nullptr;
        ListNode* ret_out = nullptr;
        while(!done){
            int min_val = 100000;
            int min_i = -1;
            for (int i = 0; i < k; ++i){
                if (lists[i] && (lists[i]->val < min_val)){
                    min_val = lists[i]->val;
                    min_i = i;
                }
            }
            if (min_i >= 0){
                if (!out){
                    out = ret_out = new ListNode(min_val);
                }
                else {
                    out->next = new ListNode(out->val);
                    out->next->val = min_val;
                    out = out->next;

                }
                lists[min_i] = lists[min_i]->next;                
                done = false;
            } else done = true;
        }
        return ret_out;
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

vector<ListNode*>* make_lists(vector<vector<int> >& flat_lists){
    vector<ListNode*>* lists = new vector<ListNode*>;
    for (auto v : flat_lists){
        ListNode* head;
        ListNode* new_list = nullptr;
        for (auto val: v){
            if (!new_list){
                head = new_list = new ListNode(val);
            }else{
                new_list->next = new ListNode(val);
                new_list = new_list->next;
            }
        }
        lists->push_back(head);
        printList(head);
    }
    return lists;
}

int main(){
    vector<vector<int> > flat_lists = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*>* lists = make_lists(flat_lists);
        
    ListNode* merged_list = Solution().mergeKLists(*lists);
    printList(merged_list);
    
    return 0;
}
