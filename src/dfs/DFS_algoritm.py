class Graph:
    def __init__(self, value, childrens=None, status=0):
        self.value = value
        self.childrens = childrens if childrens is not None else []
        self.status = status

    def __iter__(self):
        visited = set()
        stack = [self]

        while stack:
            node = stack.pop()
            if node not in visited:
                visited.add(node)
                for child in reversed(node.childrens):
                    if child not in visited:
                        stack.append(child)
                yield node.value


def DFS_step(node, arr=None):
    UNVISITED = 0
    VISITING = 1
    VISITED = 2

    if arr is None:
        arr = []

    if node.status == UNVISITED:
        node.status = VISITING
        arr.append(node.value)

    for i in node.childrens:
        if i.status == UNVISITED:
            arr = DFS_step(i, arr)

    node.status = VISITED
    return arr
