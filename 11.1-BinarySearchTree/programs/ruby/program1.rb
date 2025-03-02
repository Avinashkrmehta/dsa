# Binary search tree implementation in C++


class Node
  attr_accessor :data, :lchild, :rchild

  def initialize(data)
    @data = data
    @lchild = nil
    @rchild = nil
  end
end

class BinarySearchTree
  def initialize
    @root = nil
  end

  def insert(key)
    if @root.nil?
      @root = Node.new(key)
      return
    end

    t = @root
    r = nil

    while t
      r = t
      if key < t.data
        t = t.lchild
      elsif key > t.data
        t = t.rchild
      else
        return
      end
    end

    p = Node.new(key)
    if key < r.data
      r.lchild = p
    else
      r.rchild = p
    end
  end

  def inorder(p)
    if p
      inorder(p.lchild)
      print "#{p.data}, "
      inorder(p.rchild)
    end
  end

  def search(key)
    t = @root

    while t
      if key == t.data
        return t
      elsif key < t.data
        t = t.lchild
      else
        t = t.rchild
      end
    end
    nil
  end

  def display_inorder
    inorder(@root)
    puts
  end
end

bst = BinarySearchTree.new
bst.insert(10)
bst.insert(5)
bst.insert(20)
bst.insert(8)
bst.insert(30)

bst.display_inorder

temp = bst.search(10)
if temp
  puts "#{temp.data} is found"
else
  puts "Key not found"
end
