/*
    Time Complexity : O(N)
    Space Complexity : O(K)

    Where, N is the size of the vector and K is the number of elements which are non zero.
*/

class sparseVector {

public:
    vector<pair<int, int>> vecToPair;

    // Constructor for sparseVector.
    sparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {

            // If the current position in vector is empty.
            if (nums[i] == 0) {
                continue;
            }

            // convert the sparse vector into pair.
            vecToPair.push_back({i, nums[i]});
        }
    }

    // Function to compute dot Product.
    int dotProduct(sparseVector& vec) {
        int i = 0, j = 0;
        int result = 0;

        // Check if the current index of both the pair is same or not.
        while (i < vecToPair.size() && j < vec.vecToPair.size()) {

            if (vecToPair[i].first < vec.vecToPair[j].first) {
                i++;
            } else if (vecToPair[i].first > vec.vecToPair[j].first) {
                j++;
            }

            // If both the indexes are same, Update result.
            else {
                result += (vecToPair[i].second * vec.vecToPair[j].second);
                i++;
                j++;
            }
        }

        return result;
    }
};
