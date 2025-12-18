## Drops a new item in the heap to the correct location
def sift_down(arr, n, i):
    largest = i
    left = i * 2 + 1
    right = i * 2 + 2

    if (left < n) and (arr[left] > arr[largest]):
        largest = left

    if (right < n) and (arr[right] > arr[largest]):
        largest = right

    if largest != i:
        arr[largest], arr[i] = arr[i], arr[largest]
        sift_down(arr, n, largest)


## Creates a binary max-heap from an array
def heapify(arr, n):
    for i in range(n // 2 - 1, -1, -1):
        sift_down(arr, n, i)


## Implementation of heap-sort
def heap_sort(massive):
    n = len(massive)
    heapify(massive, n)

    ## Move max element to the end and reduces the max-heap
    while n > 0:
        tmp = massive[n - 1]
        massive[n - 1] = massive[0]
        massive[0] = tmp
        n -= 1
        sift_down(massive, n, 0)

    return massive
