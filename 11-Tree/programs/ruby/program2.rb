class Node
    attr_accessor :lchild, :data, :rchild

    def initialize(data)
        @data = data
        @lchild = nil
        @rchild = nil
    end
end

class Queue
    def initialize(size)
        @size = size
        @front = @rear = 0
        @q = Array.new(size)
    end

    def enqueue(x)
        if (@rear + 1) % @size == @front
            puts "Queue is full"
        else
            @rear = (@rear + 1) % @size
            @q[@rear] = x
        end
    end

    def dequeue
        if @front == @rear
            puts "Queue is empty"
            nil
        else
            @front = (@front + 1) % @size
            @q[@front]
        end
    end

    def is_empty?
        @front == @rear
    end
end

class BinaryTree
    def initialize
        @root = nil
    end

    def create_tree
        q = Queue.new(100)
        puts "Enter root value: "
        x = gets.to_i
        @root = Node.new(x)
        q.enqueue(@root)
        while !q.is_empty?
            p = q.dequeue
            puts "Enter left child of #{p.data}: "
            x = gets.to_i
            if x != -1
                t = Node.new(x)
                p.lchild = t
                q.enqueue(t)
            end
            puts "Enter right child of #{p.data}: "
            x = gets.to_i
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

    def display_traversals
        puts "Preorder: "
        pre_order(@root)
        puts "\nInorder: "
        in_order(@root)
        puts "\nPostorder: "
        post_order(@root)
        puts
    end
end

tree = BinaryTree.new
tree.create_tree
tree.display_traversals
