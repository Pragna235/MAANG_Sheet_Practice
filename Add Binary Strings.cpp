/*
    Time Complexity : O(N + M)
    Space Complexity : O(max(N, M))
    
    Where ‘N’ and ‘M’ are the lengths of the string ‘A’ and ‘B’ respectively.
*/

#include <algorithm>

string addBinaryString(string &a, string &b, int n, int m)
{
    //  To store the sum of binary strings.
    string sum = "";

    int i = 0;

    //  To store the carry while adding the bits.
    int carry = 0;

    while (i < max(n, m))
    {

        //  Initialize the current sum of the bits.
        int curSum = carry;

        if (i < n)
        {
            //  Add the value in the current sum.
            curSum = curSum + (a[n - 1 - i] - '0');
        }
        if (i < m)
        {
            //  Add the value in the current sum.
            curSum = curSum + (b[m - 1 - i] - '0');
        }

        //  Append the resulting bit at the end of the string.
        sum.push_back((curSum) % 2 + '0');

        //  Update the carry value.
        carry = curSum / 2;

        i++;
    }
    if (carry != 0)
    {
        sum.push_back('1');
    }

    //  Reverse the binary string to move the least significant bits at the end of the string.
    reverse(sum.begin(), sum.end());

    return sum;
}
