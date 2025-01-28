class Element
  attr_accessor :i, :j, :x

  def initialize(i, j, x)
      @i = i
      @j = j
      @x = x
  end
end

class Sparse
  attr_accessor :m, :n, :num, :ele

  def initialize
      @ele = []
  end

  def create
      print "Enter dimensions: "
      @m, @n = gets.split.map(&:to_i)
      print "Enter number of non-zero elements: "
      @num = gets.to_i
      print "Enter non-zero elements: "
      @num.times do
          i, j, x = gets.split.map(&:to_i)
          @ele << Element.new(i, j, x)
      end
      puts " @ele: #{@ele}"
      puts " @m: #{@m}"
      puts " @n: #{@n}"
  end

  def display
      k = 0
      (0...@m).each do |i|
          (0...@n).each do |j|
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

s = Sparse.new
s.create
s.display
