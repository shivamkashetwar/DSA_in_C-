def merge(arr, st, mid, end):
    temp = []
    i = st
    j = mid + 1

    while i <= mid and j <= end:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1

    while i <= mid:
        temp.append(arr[i])
        i += 1

    while j <= end:
        temp.append(arr[j])
        j += 1

    for idx in range(len(temp)):
        arr[idx + st] = temp[idx]


def merge_sort(arr, st, end):
    if st < end:
        mid = st + (end - st) // 2

        merge_sort(arr, st, mid)
        merge_sort(arr, mid + 1, end)

        merge(arr, st, mid, end)


arr = [12, 31, 35, 8, 34, 21]

merge_sort(arr, 0, len(arr) - 1)

print(arr)