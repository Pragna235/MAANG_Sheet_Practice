/*
    Time complexity: O(L * M)
    Space complexity: O(M)
    
    Where 'L' is the number of levels and 'M' is the given modulo integer.
*/

int countMonsters(int l, int m){
    
    // Create queue.
    queue<int> q;
    q.push(2);
    q.push(-1);
    
    // To store monsters.
    int count = 1;
    
    // To store number of monsters for each 'M'.
    int dp[m] = {0};
    
    // Pre-computation.
    for(int i = 0; i < m; ++i){
        dp[i] += ((i * i) + 1) % m;
    }
    
    // Traverse all levels.
    while(l > 1){
        while(q.front() != -1){
            int x = q.front();
            q.pop();
            
            // Update count.
            count += dp[x];
            for(int i = 0; i < dp[x]; ++i){
                q.push(i);
            }
        }
        q.pop();
        q.push(-1);
        --l;
    }
    return (count % m);
}
