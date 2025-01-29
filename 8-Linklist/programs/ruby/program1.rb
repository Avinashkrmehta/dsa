class Node
  attr_accessor :data, :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

def create(arr)
  first = Node.new(arr[0])
  last = first

  arr[1..-1].each do |value|
    t = Node.new(value)
    last.next = t
    last = t
  end

  first
end

def display(node)
  while node
    print "#{node.data} "
    node = node.next
  end
end

def recursiveDisplay(node)
  return if node.nil?

  print "#{node.data} "
  recursiveDisplay(node.next)
end

def recursiveDisplay1(node)
  return if node.nil?

  recursiveDisplay1(node.next)
  print "#{node.data} "
end

arr = [3, 5, 7, 10, 15]
first = create(arr)
display(first)
puts
recursiveDisplay(first)
puts
recursiveDisplay1(first)