# Top K Frequent Elements

This repository contains a C++ implementation to find the top K most frequent elements in an integer array. It provides a solution with a time complexity better than O(n log n) by using a hash map and a min-heap.

## Problem Statement

Given an integer array and an integer K, the goal is to find the K most frequent elements in the array. The solution returns the K most frequent elements in any order.

## Solution Overview

1. Create a hash map to count the frequency of each element in the input array.
2. Use a min-heap (priority queue) to keep track of the K most frequent elements.
3. Iterate through the hash map entries and push them into the min-heap, maintaining its size at K.
4. Extract the K most frequent elements from the min-heap, ensuring they are in non-decreasing order of frequency.

## Example Usage

#include <iostream>
#include <vector>
#include "TopKFrequentElements.h"

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " most frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
