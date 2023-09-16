def solution(A, X, Y):
    minCost = float('inf')

    i = 0
    n = len(A)


    while(i <= n - X * Y ):
        j = i
        curCost = 0 
        
        while(j < i + X * Y ):
            curCost += A[j] 
            j += Y
        
        minCost = min(curCost, minCost) 
        i += 1
    
    return minCost
    pass
