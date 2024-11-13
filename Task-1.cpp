vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq_map;
    //Counting frequencies
    for (int num : nums) {
        freq_map[num]++;
    }

    // Using a priority queue (max-heap) to store the k most frequent elements
    priority_queue<pair<int, int>> max_heap; // {frequency, element}
    for (auto& entry : freq_map) {
        max_heap.push({entry.second, entry.first});
    }

    // Extracting the top k elements
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(max_heap.top().second);
        max_heap.pop();
    }

    return result;
}


Time Complexity: O(nlogn)
Space Complexity: O(n)