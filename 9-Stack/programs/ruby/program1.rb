# Stack implementation

class Stack
  def initialize(size)
    @size = size
    @top = -1
    @stack = Array.new(size)
  end

  def push(x)
    if @top == @size - 1
      puts "Stack Overflow"
    else
      @top += 1
      @stack[@top] = x
    end
  end

  def pop
    if @top == -1
      puts "Stack Underflow"
      -1
    else
      x = @stack[@top]
      @top -= 1
      x
    end
  end

  def peek(index)
    if @top - index + 1 < 0
      puts "Invalid Index"
      -1
    else
      @stack[@top - index + 1]
    end
  end

  def stack_top
    @top == -1 ? -1 : @stack[@top]
  end

  def is_empty
    @top == -1
  end

  def is_full
    @top == @size - 1
  end

  def display
    for i in (0..@top).reverse_each
      print "#{@stack[i]} "
    end
    puts
  end
end

stack = Stack.new(5)
stack.push(10)
stack.push(20)
stack.push(30)
stack.push(40)
stack.push(50)
stack.push(60)

puts "Popped: #{stack.pop}"
puts "Peek: #{stack.peek(2)}"
stack.display