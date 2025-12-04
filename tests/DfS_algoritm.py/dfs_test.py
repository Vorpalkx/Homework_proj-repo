import pytest

from dfs.DFS_algoritm import Graph, DFS_step

class TestGraph:
    def test_create_single_node(self):
        """Checking the creation of a node without children"""
        g = Graph(1)
        assert g.value == 1
        assert g.childrens == []

    def test_create_node_with_children(self):
        """Checking the creation of a node with preset children"""
        child1 = Graph(2)
        child2 = Graph(3)
        g = Graph(1, [child1, child2])
        
        assert g.value == 1
        assert len(g.childrens) == 2
        assert g.childrens[0].value == 2
        assert g.childrens[1].value == 3
    
    def test_linear_graph(self):
        """A test for a linear graph"""
        c = Graph(3)
        b = Graph(2, [c])
        a = Graph(1, [b])

        result = list(a)
        assert result == [1, 2, 3]

    def test_branching_graph(self):
        """A test for a branched graph"""
        d = Graph(4)
        e = Graph(5)
        b = Graph(2, [d, e])
        c = Graph(3, [d])
        a = Graph(1, [b, c])

        result = list(a)
        assert result == [1, 2, 4, 5, 3]

    def test_cyclic_graph(self):
        """A test for a cyclic graph"""
        a = Graph(1)
        b = Graph(2)
        c = Graph(3)
        
        a.childrens = [b]
        b.childrens = [c]
        c.childrens = [a]

        result = list(a)
        assert len(result) == 3
        assert set(result) == {1, 2, 3}
        assert result[0] == 1

    def test_single_node_traversal(self):
        """Isolated node traversal test"""
        g = Graph(42)
        result = list(g)
        assert result == [42]

    def test_dfs_function(self):
        """Test the function DFS_step(), which returns a list"""
        b = Graph(2)
        c = Graph(3)
        a = Graph(1, [b, c])
        
        result = DFS_step(a)
        assert result == [1, 2, 3]
    
    def test_tree_structure(self):
        """A test for a tree structure"""
        node4 = Graph(4)
        node5 = Graph(5)
        node6 = Graph(6)
        node2 = Graph(2, [node4, node5])
        node3 = Graph(3, [node6])
        node1 = Graph(1, [node2, node3])
        
        result = list(node1)
        assert result == [1, 2, 4, 5, 3, 6]

    def test_multiple_iterations(self):
        """A test that the iterator can be called repeatedly"""
        b = Graph(2)
        a = Graph(1, [b])
        
        result1 = list(a)
        result2 = list(a)
        
        assert result1 == [1, 2]
        assert result2 == [1, 2]
        assert result1 == result2

    def test_duplicate_values(self):
        """A graph test where different nodes have the same values"""
        b = Graph(2)
        c = Graph(2)
        a = Graph(1, [b, c])
        
        result = list(a)
        assert len(result) == 3
        assert result.count(2) == 2

    def test_large_Graph(self):
        """A test for a graph with a large number of nodes"""
        node4 = Graph(4)
        node5 = Graph(5)
        node6 = Graph(6)
        node7 = Graph(7)
        node2 = Graph(2, [node4, node5])
        node3 = Graph(3, [node6, node7])
        node1 = Graph(1, [node2, node3])
        
        result = list(node1)
        assert len(result) == 7
        assert result[0] == 1
        assert len(set(result)) == 7

class TestGraphEdgeCases:
    def test_empty_children_list(self):
        """A test with an empty list of children when creating"""
        g = Graph(1, [])
        assert g.childrens == []
        assert list(g) == [1]
    
    def test_none_children(self):
        """If the childrens method has None, it is initialized with an empty list."""
        g = Graph(1, None)
        assert g.childrens == []
    
    def test_modify_children_after_creation(self):
        """Test changing the list of children after creating a node"""
        g = Graph(1)
        child = Graph(2)
        g.childrens.append(child)
        
        assert list(g) == [1, 2]
    
    def test_Graph_with_no_edges(self):
        """Testing multiple isolated nodes"""
        a = Graph(1)
        b = Graph(2)
        c = Graph(3)

        assert list(a) == [1]
        assert list(b) == [2]
        assert list(c) == [3]
