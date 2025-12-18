def sort_step(current_arr, index=0):
    if index == len(current_arr):
        return current_arr

    if index == 0:
        return sort_step(current_arr, 1)

    if current_arr[index] >= current_arr[index - 1]:
        return sort_step(current_arr, index + 1)

    else:
        new_arr = current_arr.copy()
        new_arr[index], new_arr[index - 1] = new_arr[index - 1], new_arr[index]
        return sort_step(new_arr, index - 1)


def gnome_sort(arr):
    massive = sort_step(arr)
    return massive
