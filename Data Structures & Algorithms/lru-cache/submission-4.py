# DLL Type
class Node:
    def __init__(self, k, v):
        self.k = k
        self.v = v
        self.prev = self.nxt = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.cap = capacity
        # Init Head and Tail
        self.h, self.t = Node(0,0),Node(0,0)
        self.h.nxt,self.t.prev = self.t,self.h

    def remove(self,node):
        prev,nxt = node.prev,node.nxt
        prev.nxt, nxt.prev = nxt,prev

    def insert(self,node):
        prev,nxt = self.t.prev,self.t
        prev.nxt = nxt.prev = node
        node.nxt, node.prev = nxt,prev

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].v
        return -1
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        newN = Node(key,value)
        self.cache[key] = newN
        self.insert(newN)
        if len(self.cache) > self.cap:
            lru = self.h.nxt
            self.remove(lru)
            del self.cache[lru.k]

        
