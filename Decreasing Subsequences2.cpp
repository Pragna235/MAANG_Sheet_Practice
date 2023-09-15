

int decreasingSubsequences(int n, vector<int>& arr) {

    vector<vector<int>> subsequences; // Stores the subsequences

    for (int num : arr) {
        bool placed = false;

        // Try to place the current number in an existing subsequence
        for (vector<int>& subsequence : subsequences) {
            if (subsequence.back() > num) {
                subsequence.push_back(num);
                placed = true;
                break;
            }
        }

        // If not placed in an existing subsequence, create a new one
        if (!placed) {
            subsequences.push_back({num});
        }
    }

    return subsequences.size();
}
