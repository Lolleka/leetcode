// https://leetcode.com/problems/max-chunks-to-make-sorted-ii
// hard
// #array, #stack, #greedy, #sorting, #monotonic-stack

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    private:
        bool chunk_is_sortable (vector<int>& arr,
                                vector<int>& sorted_arr,
                                int start_idx,
                                int end_idx){
            auto arr_chunk = vector<int>(arr.begin()+start_idx,
                                         arr.begin()+end_idx);
            sort(arr_chunk.begin(), arr_chunk.end());
            auto sorted_arr_chunk = vector<int>(sorted_arr.begin()+start_idx,
                                                sorted_arr.begin()+end_idx);
            /* for (int i : arr_chunk) cout << i; */
            /* cout << endl; */
            /* for (int i : sorted_arr_chunk) cout << i; */
            /* cout << endl; */
            return sorted_arr_chunk == arr_chunk;
        }

    void printChunks(vector<int>& arr, vector<int>& chunks){
        int start_idx = 0;
        cout << "|";
        for (int j = 0; j < chunks.size(); j++){
            int end_idx = chunks[j];
            for (int i = start_idx; i < end_idx; i++) cout << arr[i];
            cout << "|";
            start_idx = end_idx;
        }
        cout << endl;
    }

    public:
        int maxChunksToSorted(vector<int>& arr){
            // have a copy of the sorted array
            vector<int> sorted_arr = arr;
            sort(sorted_arr.begin(), sorted_arr.end());
            // maintain a vector with chunk indexes
            vector<int> chunks;
            int end_idx = 0;
            while(end_idx < arr.size()){
                int start_idx = chunks.size() > 0 ? *chunks.end() : 0;
                end_idx++;
                if (this->chunk_is_sortable (arr, sorted_arr, start_idx, end_idx)){
                    chunks.push_back(end_idx);
                    this->printChunks(arr, chunks);
                } else {
                    // if we are at the end of the array
                    // we have two subcases
                    if (end_idx == arr.size()){
                        // if we can increase the last chunk index, do so
                        if (chunks.size() > 0){
                            end_idx = *chunks.end();
                            chunks.pop_back();
                        } else {
                            // we only have one chunk;
                            return 1;
                        }
                    }
                }
            }
            return chunks.size();
        }
};


int main(){
    /* vector<int> arr{2,1,3,4,4}; */
    vector<int> arr{5,4,3,2,1,5};
    cout << Solution().maxChunksToSorted(arr) << endl;
    return 0;
}
