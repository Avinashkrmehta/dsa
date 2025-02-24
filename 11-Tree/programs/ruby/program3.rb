class Node
    attr_accessor :lchild, :data, :rchild

    def initialize(data)
        @data = data
        @lchild = nil
        @rchild = nil
    end
end

class Queue
    def initialize(size = 10)
        @size = size
        @front = @rear = -1
        @q = Array.new(@size)
    end

    def enqueue(x)
        if @rear == @size - 1
            puts "Queue is full"
        else
            @rear += 1
            @q[@rear] = x
        end
    end

    def dequeue
        if @front == @rear
            puts "Queue is empty"
            nil
        else
            @front += 1
            @q[@front]
        end
    end

    def is_empty
        @front == @rear
    end
end

class Tree
    attr_accessor :root

    def initialize
        @root = nil
    end

    def create_tree
        q = Queue.new(100)
        puts "Enter root value: "
        x = gets.chomp.to_i
        @root = Node.new(x)
        q.enqueue(@root)
        while !q.is_empty
            p = q.dequeue
            puts "Enter left child of #{p.data}: "
            x = gets.chomp.to_i
            if x != -1
                t = Node.new(x)
                p.lchild = t
                q.enqueue(t)
            end
            puts "Enter right child of #{p.data}: "
            x = gets.chomp.to_i
            if x != -1
                t = Node.new(x)
                p.rchild = t
                q.enqueue(t)
            end
        end
    end

    def pre_order(p)
        if p
            print "#{p.data} "
            pre_order(p.lchild)
            pre_order(p.rchild)
        end
    end

    def in_order(p)
        if p
            in_order(p.lchild)
            print "#{p.data} "
            in_order(p.rchild)
        end
    end

    def post_order(p)
        if p
            post_order(p.lchild)
            post_order(p.rchild)
            print "#{p.data} "
        end
    end

    def level_order(p)
        q = Queue.new(100)
        print "#{@root.data} "
        q.enqueue(@root)
        while !q.is_empty
            p = q.dequeue
            if p.lchild
                print "#{p.lchild.data} "
                q.enqueue(p.lchild)
            end
            if p.rchild
                print "#{p.rchild.data} "
                q.enqueue(p.rchild)
            end
        end
    end

    def height(p)
        return 0 if p.nil?

        x = height(p.lchild)
        y = height(p.rchild)
        x > y ? x + 1 : y + 1
    end
end

t = Tree.new
t.create_tree
t.pre_order(t.root)
puts
t.in_order(t.root)
puts
t.post_order(t.root)
puts
t.level_order(t.root)
puts
puts t.height(t.root)
