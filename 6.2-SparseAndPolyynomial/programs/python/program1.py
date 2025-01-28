class Element:
  def __init__(self, i, j, x):
    self.i = i
    self.j = j
    self.x = x

class Sparse:
  def __init__(self):
    self.ele = []

  def create(self):
    self.m, self.n = map(int, input("Enter dimensions: ").split())
    self.num = int(input("Enter number of non-zero elements: "))
    print("Enter non-zero elements: ")
    for _ in range(self.num):
      i, j, x = map(int, input().split())
      self.ele.append(Element(i, j, x))

  def display(self):
    k = 0
    for i in range(self.m):
      for j in range(self.n):
        if k < self.num and i == self.ele[k].i and j == self.ele[k].j:
          print(self.ele[k].x, end=" ")
          k += 1
        else:
          print("0", end=" ")
      print()

s = Sparse()
s.create()
s.display()