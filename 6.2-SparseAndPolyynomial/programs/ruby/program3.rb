
class Element
  attr_accessor :i, :j, :x

  def initialize(i = 0, j = 0, x = 0)
    @i = i
    @j = j
    @x = x
  end
end

class Sparse
  attr_accessor :m, :n, :num, :ele

  def initialize(m, n, num)
    @m = m
    @n = n
    @num = num
    @ele = Array.new(num) { Element.new }
  end

  def +(s)
    return Sparse.new(0, 0, 0) if @m != s.m || @n != s.n

    sum = Sparse.new(@m, @n, @num + s.num)
    i = j = k = 0

    while i < @num && j < s.num
      if @ele[i].i < s.ele[j].i
        sum.ele[k] = @ele[i]
        i += 1
      elsif @ele[i].i > s.ele[j].i
        sum.ele[k] = s.ele[j]
        j += 1
      else
        if @ele[i].j < s.ele[j].j
          sum.ele[k] = @ele[i]
          i += 1
        elsif @ele[i].j > s.ele[j].j
          sum.ele[k] = s.ele[j]
          j += 1
        else
          sum.ele[k] = Element.new(@ele[i].i, @ele[i].j, @ele[i].x + s.ele[j].x)
          i += 1
          j += 1
        end
      end
      k += 1
    end

    while i < @num
      sum.ele[k] = @ele[i]
      i += 1
      k += 1
    end

    while j < s.num
      sum.ele[k] = s.ele[j]
      j += 1
      k += 1
    end

    sum.num = k
    sum
  end

  def read
    puts "Enter non-zero elements: "
    @num.times do |i|
      @ele[i].i, @ele[i].j, @ele[i].x = gets.split.map(&:to_i)
    end
  end

  def prints
    k = 0
    @m.times do |i|
      @n.times do |j|
        if k < @num && i == @ele[k].i && j == @ele[k].j
          print "#{@ele[k].x} "
          k += 1
        else
          print "0 "
        end
      end
      puts
    end
  end
end

s1 = Sparse.new(3, 3, 2)
s2 = Sparse.new(3, 3, 2)
puts "Enter first matrix: "
s1.read
puts "Enter second matrix: "
s2.read
sum = s1 + s2
puts "First matrix: "
s1.prints
puts "Second matrix: "
s2.prints
puts "Sum matrix: "
sum.prints