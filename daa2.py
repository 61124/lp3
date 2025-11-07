import heapq
from collections import defaultdict

class Node:
    def __init__(self,char,freq):
        self.char=char
        self.freq=freq
        self.left=None
        self.right=None
        
    def __lt__(self,other):
        return self.freq<other.freq

def build_huffmanTree(text):
    freq=defaultdict(int)
    for ch in text:
        freq[ch]+=1
        
    heap=[Node(ch,f) for ch,f in freq.items()]
    heapq.heapify(heap)

    while len(heap)>1:
        left=heapq.heappop(heap)
        right=heapq.heappop(heap)
        merged=Node(None,left.freq+right.freq)
        merged.left=left
        merged.right=right
        heapq.heappush(heap,merged)
    return heap[0]

def generate_codes(root, current_code="", codes=None):
    if codes is None:
        codes = {}
    if root is None:
        return codes
    if root.char is not None:
        codes[root.char] = current_code if current_code else "0"  # Handle single char
        return codes
        
    generate_codes(root.left, current_code + "0", codes)
    generate_codes(root.right, current_code + "1", codes)
    return codes

def encode(text,codes):
    return ''.join(codes[ch] for ch in text) 

def decode(encoded_text, root):
    # Handle single character case
    if root.left is None and root.right is None:
        return root.char * len(encoded_text)
    decoded = ""
    node = root
    for bit in encoded_text:
        node = node.left if bit == "0" else node.right
        if node.char:
            decoded += node.char
            node = root
    return decoded

if __name__=="__main__":
    text=input("Enter the text: ")
    root=build_huffmanTree(text)
    codes=generate_codes(root)
    for ch, code in codes.items():
        print(f"{repr(ch)}:{code}")
    encoding=encode(text,codes)
    print(f"The encoded text is : {encoding}")
    decoding=decode(encoding,root)
    print(f"The decoded text is : {decoding}")