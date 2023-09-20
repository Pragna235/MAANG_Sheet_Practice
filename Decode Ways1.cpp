/*
    Time complexity: O(2^N)
    Space complexity: O(N)

    Where 'N' is the size of 'strNum'.
*/

int decodeWaysHelper(string strNum, int n) {
    if (n == 0 or n == 1) {
        return 1;
    }
    int count = 0;
    if (strNum[n - 1] > '0') {
        count = decodeWaysHelper(strNum, n - 1);
    }

    // If 'strNum' is = 11, 12, 13, 14, 15, 16, 17, 18, 19
    if (strNum[n - 2] == '1') {
        count += decodeWaysHelper(strNum, n - 2);
    }

    // if 'strNUm' is = 21, 22, 23, 24, 25, 26
    else if ((strNum[n - 2] == '2' and strNum[n - 1] < '7')) {
        count += decodeWaysHelper(strNum, n - 2);
    }
    return count;
}

int decodeWays(string strNum) {
    int max = 1000000007;
    return decodeWaysHelper(strNum, strNum.size()) % (max);
}
