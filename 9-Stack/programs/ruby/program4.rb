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
    x = nil
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

  def is_empty
    @top.nil? ? 1 : 0
  end

  def is_full
    t = Node.new(nil)
    r = t.nil? ? 1 : 0
    t = nil
    r
  end

  def is_balanced(exp)
    exp.each_char do |char|
      if char == '('
        push(char)
      elsif char == ')'
        return 0 if @top.nil?
        pop
      end
    end
    @top.nil? ? 1 : 0
  end
end

exp = "((a+b)*(c-d))"
stack = Stack.new
puts stack.is_balanced(exp)
