// https://leetcode.com/problems/total-cost-to-hire-k-workers
// medium
// #array, #two-pointers, #heap, #simulation

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        long long sum = 0;
        if (candidates*2 >= costs.size()){
            // sort costs and pick lowest k candidates
            std::sort(costs.begin(), costs.end());
            for(int i = 0; i < k; ++i)
                sum += costs[i];
            return sum;
        } else if (k == costs.size()){
            for(int i = 0; i < k; ++i)
                sum += costs[i];
            return sum;
        }
        // maintain two min priority queues for head and tail sections
        // maintain two pointers for end of head and start of tail sections
        int head = candidates-1;
        int tail = costs.size()-candidates;
        std::cout << costs.size() << " , " << head << " , " << tail << std::endl;
        std::priority_queue<int,std::vector<int>,std::greater<int>> head_queue;
        std::priority_queue<int,std::vector<int>,std::greater<int>> tail_queue;
        // load queues
        for(int i = 0; i < candidates; ++i){
            head_queue.push(costs[i]);
            tail_queue.push(costs[i+tail]);
        }
        
        for(int i = 0; i < k; ++i){
            int hire_cost = 0;
            if (head_queue.top() <= tail_queue.top() && !head_queue.empty()){
                hire_cost = head_queue.top(); head_queue.pop();
                if (head < tail-1){
                    head++;
                    std::cout << "push " << costs[head] << " to head" << std::endl;
                    head_queue.push(costs[head]);
                    assert(head_queue.size() == candidates);
                }
                std::cout << "from head | ";
            }else{
                hire_cost = tail_queue.top(); tail_queue.pop();
                if (head < tail-1){
                    tail--;
                    std::cout << "push " << costs[tail] << " to tail" << std::endl;
                    tail_queue.push(costs[tail]);
                    assert(tail_queue.size() == candidates);
                }
                std::cout << "from tail | ";
            }
            sum += hire_cost;
            std::cout << head << " , " << tail << " , cost = " << hire_cost << " , sum = " << sum << std::endl;
        }
        return sum; 
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> costs = {25,65,41,31,14,20,59,42,43,57,73,45,30,77,17,38,20,11,17,65,55,85,74,32,84};
    int k = 24, candidates = 8;
    std::cout << Solution().totalCost(costs, k, candidates) << std::endl;
    return 0;
}
