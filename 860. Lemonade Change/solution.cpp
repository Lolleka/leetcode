// https://leetcode.com/problems/lemonade-change/description/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills){
            map<int, int> reg;
            for (int bill : bills){
                switch (bill){
                    case 5:
                        reg[5]++;
                        break;
                    case 10:
                        reg[10]++;
                        if (!reg[5]){
                            return false;
                        } else {
                            reg[5]--;
                        }
                        break;
                    case 20:
                        reg[20]++;
                        if (!(reg[10] > 0 &&reg[5] >0)){
                            return false;
                        } else {
                            reg[10]--;
                            reg[5]--;
                        }
                        break;
                }
            }
            return true;
        }
};

int main(){
    vector<int> bills{5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << boolalpha << Solution().lemonadeChange(bills) << endl;
    return 0;
}
