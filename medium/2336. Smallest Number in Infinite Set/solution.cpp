// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
// easy
// #hash-table, #design, #heap, #ordered-set

#include <iostream>
#include <set>

class SmallestInfiniteSet {
    // let's use std::set for the implementation of the ordered set
    std::set<int> oset;
public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        std::pair<std::set<int>::iterator, bool> num_it;
        auto it = oset.begin();
        /*std::cout << "*it = " << *it << std::endl;*/
        if(oset.empty() || *it > 1) num_it = oset.insert(1);
        else if(oset.size() == 1){
            // only 1 is in oset, add 2;
            num_it = oset.insert(2);
        }else{
            //advance iterator till we find a gap
            auto it_next = it;
            it_next++;
            while(it_next != oset.end() && *it_next - *it == 1) {it++; it_next++;}
            if(it_next !=oset.end())
                // there is enough room
                // add the number at *it
                num_it = oset.insert(*it+1);
            else
                // not enough room
                // add the number at *it
                num_it=oset.insert(*it_next+1);
        }
        /*std::cout << "removing " << *num_it.first << " from the infinite set" << std::endl;*/
        return *num_it.first;
    }

    void addBack(int num) {
        if(!oset.empty()){
            // remove excluded number from oset, if found
            auto it = oset.find(num);
            if (it != oset.end()){
                /*std::cout << "adding " << *it << " to the infinite set" << std::endl;*/
                oset.erase(it);
            }
        }
    }
};

int main (int argc, char *argv[]) {
    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
    obj->addBack(2);
    obj->popSmallest();
    obj->popSmallest();
    obj->popSmallest();
    obj->addBack(1);
    obj->popSmallest();
    obj->popSmallest();
    obj->popSmallest();
    return 0;
}
