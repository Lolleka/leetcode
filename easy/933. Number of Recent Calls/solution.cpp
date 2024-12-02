// https://leetcode.com/problems/number-of-recent-calls
// easy
// #design, #queue, #data-stream

#include <iostream>
#include <queue>

class RecentCounter {
    std::queue<int> q;
public:
    int ping(int t) {
        q.push(t); 
        while(q.front() <t-3000){
            q.pop();
        }
        return q.size();
    }
};


int main (int argc, char *argv[]) {
    RecentCounter c;
    std::cout << c.ping(1) << std::endl;
    std::cout << c.ping(100) << std::endl;
    std::cout << c.ping(3001) << std::endl;
    std::cout << c.ping(3002) << std::endl;
    return 0;
}
