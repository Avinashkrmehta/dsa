# Stack implementation

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
    while p
      print "#{p.data} "
      p = p.next
    end
    puts
  end

  def peek(pos)
    p = @top
    (pos - 1).times do
      p = p.next if p
    end
    p ? p.data : -1
  end

  def stack_top
    @top ? @top.data : -1
  end
end

stk = Stack.new
stk.push(10)
stk.push(20)
stk.push(30)
stk.push(40)
stk.push(50)
stk.display
puts stk.pop
stk.display
puts stk.peek(2)
puts stk.stack_top