# Program for evaluation of postfix expression

class Stack
  def initialize
    @stack = []
  end

  def push(x)
    @stack.push(x)
  end

  def pop
    if @stack.empty?
      puts "Stack is Empty"
      return -1
    else
      return @stack.pop
    end
  end

  def display
    puts @stack.join(' ')
  end
end

def is_operand(x)
  !['+', '-', '*', '/'].include?(x)
end

def eval_postfix(postfix)
  stack = Stack.new
  postfix.each_char do |char|
    if is_operand(char)
      stack.push(char.to_i)
    else
      x2 = stack.pop
      x1 = stack.pop
      result = case char
               when '+' then x1 + x2
               when '-' then x1 - x2
               when '*' then x1 * x2
               when '/' then x1 / x2
               end
      stack.push(result)
    end
  end
  stack.pop
end

postfix = "234*+82/-"
puts "Result is #{eval_postfix(postfix)}"