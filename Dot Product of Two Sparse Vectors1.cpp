/*
    Time Complexity : O(N)
    Space Complexity : O(K)

    Where, N is the size of the vector and K is the number of elements which are non zero.
*/

#include<map>
class sparseVector {
public:
    map<int, int> vecToMap;

    // Constructor for sparseVector.
    sparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {

            // If the current position in vector is empty skip it.
            if (nums[i] == 0) {
                continue;
            }

            // convert the sparse vector into map.
            vecToMap[i] = nums[i];
        }
    }

    // Function to compute dot Product.
    int dotProduct(sparseVector& vec) {
        int result = 0;

        map<int, int>::iterator i;
        for (i = vecToMap.begin(); i != vecToMap.end(); i++) {

            /*
                Check if the current index is also present
                in the other vector or not.
            */
            if (vec.vecToMap[i->first] > 0) {
                result += i->second * vec.vecToMap[i->first];
            }
        }

        return result;
    }
};
