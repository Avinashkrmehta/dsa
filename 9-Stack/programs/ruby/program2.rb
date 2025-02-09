class Node
  attr_accessor :data, :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

class Stack
  def initialize
    @top = nil
  end

  def push(x)
    t = Node.new(x)
    if t.nil?
      puts "Stack is full"
    else
      t.next = @top
      @top = t
    end
  end

  def pop
    x = -1
    if @top.nil?
      puts "Stack is Empty"
    else
      t = @top
      @top = @top.next
      x = t.data
    end
    x
  end

  def display
    p = @top
    while !p.nil?
      print "#{p.data} "
      p = p.next
    end
    puts
  end

  def peek(pos)
    p = @top
    (pos - 1).times do
      p = p.next unless p.nil?
    end
    p.nil? ? -1 : p.data
  end

  def stack_top
    @top.nil? ? -1 : @top.data
  end

  def is_empty
    @top.nil? ? 1 : 0
  end

  def is_full
    t = Node.new(0)
    r = t.nil? ? 1 : 0
    r
  end
end

stack = Stack.new
stack.push(10)
stack.push(20)
stack.push(30)
stack.display
puts stack.pop
stack.display
puts "Element at position 2 is: #{stack.peek(2)}"
puts "Top element is: #{stack.stack_top}"
puts "Is stack empty: #{stack.is_empty}"
puts "Is stack full: #{stack.is_full}"