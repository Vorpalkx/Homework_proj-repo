import pytest

from control_work import *

def test_empty_heap():
    """Empty Pile Test"""
    heap = BinHeap()
    assert heap.is_empty()
    assert heap.get_min() is None
    assert heap.extract_min() is None

def test_single_element():
    """A single-element heap test"""
    heap = BinHeap()
    value = 42
    heap.insert(value)

    assert not heap.is_empty()
    assert heap.get_min() == value
    assert heap.extract_min() == value
    assert heap.is_empty()

def test_insert_and_extract_min():
    """The minimum element insertion and extraction test"""
    heap = BinHeap()
    test_data = [5, 2, 8, 1, 3, 7, 4, 6]

    for num in test_data:
        heap.insert(num)

    assert heap.get_min() == 1
