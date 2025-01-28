class Term
  attr_accessor :coeff, :exp

  def initialize(coeff, exp)
    @coeff = coeff
    @exp = exp
  end
end

class Poly
  attr_accessor :terms

  def initialize
    @terms = []
  end

  def create
    print "Enter number of terms: "
    n = gets.to_i
    print "Enter terms: "
    n.times do
      coeff, exp = gets.split.map(&:to_i)
      @terms << Term.new(coeff, exp)
    end
  end

  def display
    @terms.each do |term|
      print "#{term.coeff}x#{term.exp} + "
    end
    puts
  end

  def self.add_poly(p1, p2)
    sum = Poly.new
    i, j = 0, 0
    while i < p1.terms.size && j < p2.terms.size
      if p1.terms[i].exp > p2.terms[j].exp
        sum.terms << p1.terms[i]
        i += 1
      elsif p1.terms[i].exp < p2.terms[j].exp
        sum.terms << p2.terms[j]
        j += 1
      else
        sum.terms << Term.new(p1.terms[i].coeff + p2.terms[j].coeff, p1.terms[i].exp)
        i += 1
        j += 1
      end
    end
    while i < p1.terms.size
      sum.terms << p1.terms[i]
      i += 1
    end
    while j < p2.terms.size
      sum.terms << p2.terms[j]
      j += 1
    end
    sum
  end
end

p = Poly.new
p.create
p.display

p1 = Poly.new
p1.create
p1.display

p2 = Poly.add_poly(p, p1)
p2.display