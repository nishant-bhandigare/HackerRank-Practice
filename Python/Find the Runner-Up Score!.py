if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    
    arr = list(arr)
    arr.sort(reverse=True)
    
    for i in range(1, n):
        if arr[i] < arr[0]:
            print(arr[i])
            break