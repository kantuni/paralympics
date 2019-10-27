def king(n, original):
    if n == 1:
        return 0
    if n == 2:
        return original[0] == original[1]
    
    increasing_arr = original[::]
    increasing_cost = [0] * n
    decreacing_arr = original[::]
    decreasing_cost = [0] * n

    for i in range(1, n):
        diff = 0
        if increasing_arr[i-1] >= increasing_arr[i]:
            diff = (increasing_arr[i-1] - increasing_arr[i]) + 1
            increasing_arr[i] += diff
        increasing_cost[i] = increasing_cost[i-1] + diff

    for i in range(n - 2, -1, -1):
        diff = 0
        if decreacing_arr[i] <= decreacing_arr[i+1]:
            diff = (decreacing_arr[i+1] - decreacing_arr[i]) + 1
            decreacing_arr[i] += diff
        decreasing_cost[i] = decreasing_cost[i+1] + diff
    
    bitonic_cost = [0] * n
    bitonic_cost[0] = decreasing_cost[0]
    bitonic_cost[-1] = increasing_cost[-1]
    for i in range(1, n-1):
        if increasing_arr[i] > decreacing_arr[i+1]:
            bitonic_cost[i] = increasing_cost[i] + decreasing_cost[i+1]
        else:
            bitonic_cost[i] = increasing_cost[i-1] + decreasing_cost[i]
    return min(bitonic_cost)

    
n = int(input())
arr = [int(x) for  x in input().split()]
print(king(n, arr))