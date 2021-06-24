class stack:
    def __init__(self):
        self.top = -1
        self.arr = []
        self.size = 0

    def isEmpty(self):
        if self.top == -1:
            return True
        else:
            return False    

    def push(self,ele):
            self.top +=1
            self.size += 1
            self.arr.insert(self.top,ele)

    def pop(self):
        if self.isEmpty():
            return -1
        else:
            temp = self.arr[self.top]
            self.top -= 1
            self.size -= 1
            return temp    

    def wh_top(self):
        return self.arr[self.top]



