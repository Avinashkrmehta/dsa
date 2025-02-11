# Program to convert  Infix to postfix Conversion

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

  def top
    @top ? @top.data : nil
  end
end

def precedence(x)
  case x
  when '+', '-'
    1
  when '*', '/'
    2
  else
    0
  end
end

def is_operand(x)
  !['+', '-', '*', '/'].include?(x)
end

def infix_to_postfix(infix)
  stack = Stack.new
  postfix = ""
  stack.push('#')
  infix.each_char do |char|
    if is_operand(char)
      postfix += char
    else
      while precedence(char) <= precedence(stack.top)
        postfix += stack.pop
      end
      stack.push(char)
    end
  end
  while stack.top != '#'
    postfix += stack.pop
  end
  postfix
end

infix = "a+b*c-d/e"
puts infix_to_postfix(infix)