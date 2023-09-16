/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where, N is the size of the array.
*/

int totalSteps(int n, int k, vector < int > & flowers) {

    // Take an integer to count the total steps taken.
    int steps = 0;

    /*
        Take an integer to store the amount of water
        present in the container.
    */
    int cap = k;
    for (int i = 0; i < n; i++) {
        if (flowers[i] <= cap) {

            /*
                If there is enough water for the current
                flower, water that flower.
            */
            cap -= flowers[i];
        } else {

            /*
                If there is not enough water, then go to the
                starting point and refill the container
            */
            steps += (2 * i);
            cap = k - flowers[i];
        }
        ++steps;
    }

    return steps;
}
