// https://leetcode.com/problems/online-stock-span
// medium

#include <iostream>
#include <stack>
#include <utility>

class StockSpanner {
    std::stack<std::pair<int,int>> tally;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int c = 1;       
        while(!tally.empty() && tally.top().first <= price){
            c += tally.top().second;
            tally.pop();            
        }
        tally.push({price, c});
        return c;
    }
};

int main (int argc, char *argv[]) {
    StockSpanner s;
    std::cout << s.next(100) << std::endl;
    std::cout << s.next(80) << std::endl;
    std::cout << s.next(60) << std::endl;
    std::cout << s.next(70) << std::endl;
    std::cout << s.next(60) << std::endl;
    std::cout << s.next(75) << std::endl;
    std::cout << s.next(85) << std::endl;
    
    return 0;
}
