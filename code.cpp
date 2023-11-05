#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;

    // Count the frequency of each element in the input array
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Create a min-heap to keep track of the k most frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (const auto& entry : frequencyMap) {
        minHeap.push({entry.second, entry.first});

        // Maintain the min-heap size at k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Extract the k most frequent elements from the min-heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    // Reverse the result to get elements in non-decreasing order of frequency
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = topKFrequent(nums1, k1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = topKFrequent(nums2, k2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
