import pytest
from sort.heap_sort import heap_sort

class TestHeapSortBasicCases:

    @pytest.mark.parametrize("input_arr, expected", [
        # Arrays with an even number of elements
        ([4, 2, 1, 3], [1, 2, 3, 4]),
        ([6, 3, 8, 1, 5, 2], [1, 2, 3, 5, 6, 8]),
        
        # Arrays with an odd number of elements  
        ([3, 1, 2], [1, 2, 3]),
        ([5, 3, 1, 4, 2], [1, 2, 3, 4, 5]),
    ])
    def test_heap_sort_different_lengths(self, input_arr, expected):
        """Testing arrays of different lengths"""
        result = heap_sort(input_arr)
        assert result == expected

    @pytest.mark.parametrize("input_arr, expected", [
        
        # Already sorted arrays
        ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
        ([1, 2, 3], [1, 2, 3]),
        
        # Back-sorted arrays
        ([5, 4, 3, 2, 1], [1, 2, 3, 4, 5]),
        ([3, 2, 1], [1, 2, 3]),
    ])
    def test_heap_sort_basic_cases(self, input_arr, expected):
        """Testing already sorted arrays"""
        result = heap_sort(input_arr)
        assert result == expected

    @pytest.mark.parametrize("input_arr, expected", [
        # Arrays with duplicates
        ([3, 1, 4, 1, 5], [1, 1, 3, 4, 5]),
        ([2, 2, 1, 1, 3], [1, 1, 2, 2, 3]),
        ([5, 3, 5, 3, 1], [1, 3, 3, 5, 5]),
        
        # All the elements are the same
        ([7, 7, 7, 7], [7, 7, 7, 7]),
        ([1, 1, 1], [1, 1, 1]),
    ])
    def test_heap_sort_with_duplicates(self, input_arr, expected):
        """Testing arrays with duplicate elements"""
        result = heap_sort(input_arr)
        assert result == expected

class TestHeapSortEdgeCases:

    def test_empty_list(self):
        """Testing an empty array"""
        result = heap_sort([])
        assert result == []
    
    @pytest.mark.parametrize("input_arr, expected", [
        ([5], [5]),
        ([0], [0]),
        ([-3], [-3])
    ])
    def test_single_element(self, input_arr, expected):
        """Testing an array with one element"""
        result = heap_sort(input_arr)
        assert result == expected
    
    @pytest.mark.parametrize("input_arr, expected", [
        ([2, 1], [1, 2]),
        ([1, 2], [1, 2]),
        ([3, 3], [3, 3])
    ])
    def test_two_elements(self, input_arr, expected):
        """Testing an array with two elements"""
        result = heap_sort(input_arr)
        assert result == expected
    
    @pytest.mark.parametrize("input_arr, expected", [
        ([-3, -1, -2], [-3, -2, -1]),
        ([-5, -3, -5], [-5, -5, -3]),
        ([-4, -3, -2, -1], [-4, -3, -2, -1]),
        ([-1, -2, -3, -4], [-4, -3, -2, -1])
    ])
    def test_negative_numbers(self, input_arr, expected):
        """Testing negative numbers"""
        result = heap_sort(input_arr)
        assert result == expected
        
    @pytest.mark.parametrize("input_arr, expected", [
        ([3, -2, 1, -5, 4], [-5, -2, 1, 3, 4]),
        ([-10, 15, -3, 0, 7], [-10, -3, 0, 7, 15])
    ])
    def test_mixed_positive_negative(self, input_arr, expected):
        """Testing mixed positive and negative numbers"""
        result = heap_sort(input_arr)
        assert result == expected
    
    @pytest.mark.parametrize("input_arr, expected", [
        ([3.5, 1.2, 2.8], [1.2, 2.8, 3.5]),
        ([1.1, 1.1, 1.0], [1.0, 1.1, 1.1]),
        ([-2.5, 0.0, 1.7], [-2.5, 0.0, 1.7])
    ])
    def test_float_numbers(self, input_arr, expected):
        """Testing fractional numbers"""
        result = heap_sort(input_arr)
        assert result == expected
    
    @pytest.mark.parametrize("input_arr, expected", [
        ([1000000, 999999, 1000001], [999999, 1000000, 1000001]),
        ([10**6, 10**6 - 1, 10**6 + 1], [10**6 - 1, 10**6, 10**6 + 1])
    ])
    def test_large_numbers(self, input_arr, expected):
        """Testing large numbers"""
        result = heap_sort(input_arr)
        assert result == expected
    
    @pytest.mark.parametrize("input_arr, expected", [
        ([0.0001, 0.0002, 0.00005], [0.00005, 0.0001, 0.0002]),
        ([1e-10, 2e-10, 0.5e-10], [0.5e-10, 1e-10, 2e-10])
    ])
    def test_very_small_numbers(self, input_arr, expected):
        """Testing very small numbers"""
        result = heap_sort(input_arr)
        assert result == expected

    @pytest.mark.parametrize("input_arr, expected", [
        ([7, 7, 7, 7, 7], [7, 7, 7, 7, 7]),
        ([0, 0, 0], [0, 0, 0]),
        ([-3, -3, -3], [-3, -3, -3])
    ])
    def test_all_identical_elements(self, input_arr, expected):
        """Testing an array where all the elements are the same"""
        result = heap_sort(input_arr)
        assert result == expected

    def test_large_arrays(self):
        """Testing large arrays"""
        large_array = list(range(1000, 0, -1))
        expected = list(range(1, 1001))
        assert heap_sort(large_array) == expected

    @pytest.mark.parametrize("input_arr, expected", [
        ([1, 100, 2, 99, 3, 98], [1, 2, 3, 98, 99, 100]),
        ([1000, 1, 500], [1, 500, 1000])
    ])
    def test_arrays_with_gaps(self, input_arr, expected):
        """Testing arrays with large gaps between values"""
        result = heap_sort(input_arr)
        assert result == expected 
