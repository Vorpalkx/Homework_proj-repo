import pytest

from sort.quick_sort import quick_sort
from sort.heap_sort import heap_sort
from sort.gnome_sort import gnome_sort

@pytest.mark.parametrize(
    'func_sort',
    [
        quick_sort,
        heap_sort,
        gnome_sort
    ]
)
@pytest.mark.parametrize(
    'arr',
    [
        ([1, 7, 3, 12, 0]),
        ([1, 2, 3, 4, 5]),
        ([5, 4, 3, 2, 1]),
        ([-1, -7, -3, -12, 0]),
        ([4, 4, 4, 4, 4])
    ]
)
class TestPropertyBasedCases:
    
    def test_length_preservation(self, func_sort, arr):
        """Property: the length of the array is preserved"""
        result = func_sort(arr)
        assert len(result) == len(arr)
        
    def test_sorted_order(self, func_sort, arr):
        """Property: the result is sorted"""
        result = func_sort(arr)
        for i in range(len(result) - 1):
            assert result[i] <= result[i + 1]

    def test_elements_preservation(self, func_sort, arr):
        """Property: all elements are saved"""
        result = func_sort(arr)
        assert sorted(arr) == result

    def test_min_max_preservation(self, func_sort, arr):
        """Property: minimum and maximum elements are saved"""
        result = func_sort(arr)
        assert min(arr) == min(result)
        assert max(arr) == max(result)

    def test_idempotence(self, func_sort, arr):
        """Property: repeated application does not change the result"""
        once = func_sort(arr)
        twice = func_sort(once)
        assert once == twice
