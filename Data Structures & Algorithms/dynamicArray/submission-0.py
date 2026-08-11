class DynamicArray:
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.elements = []


    def get(self, i: int) -> int:
        #assume valid            
        return self.elements[i]


    def set(self, i: int, n: int) -> None:
        #assume valid
        self.elements[i] = n



    def pushback(self, n: int) -> None:
        self.elements += [n]
        self.size += 1
        print(self.size)
        print(self.capacity)
        if self.size > self.capacity:
            self.resize()


    def popback(self) -> int:
        self.size -=1
        return self.elements[self.size]
 

    def resize(self) -> None:
        self.capacity *=2


    def getSize(self) -> int:
        return self.size
        
    
    def getCapacity(self) -> int:
        return self.capacity
