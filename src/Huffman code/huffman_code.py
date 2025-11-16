import pickle
import heapq
from collections import Counter

class HuffmanNode:
    def __init__(self, freq, char):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_huffman_tree(msg):
    frequency = Counter(msg)

    heap = [HuffmanNode(freq, char) for char, freq in frequency.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        merged = HuffmanNode(left.freq + right.freq, None)
        merged.left = left
        merged.right = right

        heapq.heappush(heap, merged)

    return heap[0]

def build_codes(node, current_code = "", codes = None):
    if codes is None:
        codes = {}

    if node is None:
        return

    if node.char is not None:
        codes[node.char] = current_code
        return

    build_codes(node.left, current_code + "0", codes)
    build_codes(node.right, current_code + "1", codes)

    return codes

def encode(msg: str) -> tuple[str, dict[str, str]]:
    if not msg:
        return "", {}

    root = build_huffman_tree(msg)
    codes = build_codes(root)

    encoded_text = "".join(codes[char] for char in msg)

    return encoded_text, codes

def decode(encoded: str, table: dict[str, str]) -> str:
    reverse_code = {code: char for char, code in table.items()}

    current_code = ""
    decoded_text = ""

    for bit in encoded:
        current_code += bit
        if current_code in reverse_code:
            decoded_text += reverse_code[current_code]
            current_code = ""
    return decoded_text

def file_encode(msg: str) -> str:
    encoded_text, codes = encode(msg)

    with open("codes.bin", "wb") as file:
        pickle.dump(codes, file)

    return encoded_text

def file_decode(encoded: str) -> str:
    with open("codes.bin", "rb") as file:
        codes = pickle.load(file)

    decoded_text = decode(encoded, codes)

    return decoded_text
