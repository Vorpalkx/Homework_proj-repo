class BinTree:
    def __init__(self, key):
        self.key = key
        self.degree = 0
        self.parent = None
        self.child = None
        self.sibling = None

class BinHeap:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def get_min(self):
        if BinHeap.is_empty(self):
            return None

        min_node = self.head
        current = self.head.sibling
        while current is not None:
            if current.key < min_node.key:
                min_node = current
            current = current.sibling

        return min_node.key

    @staticmethod
    def merge(H1, H2):
        if H1.head is None:
            return H2
        if H2.head is None:
            return H1

        H = BinHeap()

        curH = None
        curH1 = H1.head
        curH2 = H2.head

        if curH1.degree < curH2.degree:
            H.head = curH1
            curH = curH1
            curH1 = curH1.sibling
        else:
            H.head = curH2
            curH = curH2
            curH2 = curH2.sibling

        while curH1 is not None and curH2 is not None:
            if curH1.degree < curH2.degree:
                curH.sibling = curH1
                curH = curH1
                curH1 = curH1.sibling
            else:
                curH.sibling = curH2
                curH = curH2
                curH2 = curH2.sibling

        if curH1 is not None:
            while curH1 is not None:
                curH.sibling = curH1
                curH = curH1
                curH1 = curH1.sibling
        else:
            while curH2 is not None:
                curH.sibling = curH2
                curH = curH2
                curH2 = curH2.sibling

        curH = H.head
        prev = None

        while curH is not None and curH.sibling is not None:
            next_node = curH.sibling

            if curH.degree == next_node.degree:
                if curH.key <= next_node.key:
                    curH.sibling = next_node.sibling

                    next_node.parent = curH
                    next_node.sibling = curH.child
                    curH.child = next_node
                    curH.degree += 1

                    if prev is not None:
                        curH = prev
                        continue
                else:
                    if prev is not None:
                        prev.sibling = next_node
                    else:
                        H.head = next_node

                    curH.parent = next_node
                    curH.sibling = next_node.child
                    next_node.child = curH
                    next_node.degree += 1

                    curH = next_node
                    continue

            prev = curH
            curH = curH.sibling

        return H

    def insert(self, key):
        new_tree = BinTree(key)
        new_heap = BinHeap()
        new_heap.head = new_tree

        result = BinHeap.merge(self, new_heap)
        self.head = result.head

    def extract_min(self):
        if self.head is None:
            return None

        min_prev = None
        min_node = self.head
        prev = None
        current = self.head

        while current is not None:
            if current.key < min_node.key:
                min_node = current
                min_prev = prev
            prev = current
            current = current.sibling

        if min_prev is None:
            self.head = min_node.sibling
        else:
            min_prev.sibling = min_node.sibling

        child_heap = BinHeap()

        child = min_node.child
        while child is not None:
            next_child = child.sibling
            child.sibling = child_heap.head
            child.parent = None
            child_heap.head = child
            child = next_child

        result = BinHeap.merge(self, child_heap)
        self.head = result.head

        return min_node.key

    def __iter__(self):
        heap_copy = BinHeap()
        current = self.head
        while current is not None:
            heap_copy.insert(current.key)
            current = current.sibling

        while not heap_copy.is_empty():
            yield heap_copy.extract_min()
