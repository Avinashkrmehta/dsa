# Creating binary tree in ruby

class Node
    attr_accessor :left, :right, :data
    
    def initialize(data)
        @data = data
        @left = nil
        @right = nil
    end
end
    
class BinaryTree
    def initialize
        @root = nil
    end
    
    def insert(data)
        if @root.nil?
        @root = Node.new(data)
        else
        insert_node(@root, data)
        end
    end
    
    def insert_node(node, data)
        if data < node.data
        if node.left.nil?
            node.left = Node.new(data)
        else
            insert_node(node.left, data)
        end
        else
        if node.right.nil?
            node.right = Node.new(data)
        else
            insert_node(node.right, data)
        end
        end
    end
    
    def inorder(node)
        if node.nil?
        return
        end
        inorder(node.left)
        print "#{node.data} "
        inorder(node.right)
    end
    
    def preorder(node)
        if node.nil?
        return
        end
        print "#{node.data} "
        preorder(node.left)
        preorder(node.right)
    end
    
    def postorder(node)
        if node.nil?
        return
        end
        postorder(node.left)
        postorder(node.right)
        print "#{node.data} "
    end
end
    
    tree = BinaryTree.new
    tree.insert(10)
    tree.insert(5)
    tree.insert(15)
    tree.insert(3)
    tree.insert(7)
    tree.insert(12)
    tree.insert(18)
    
    puts "Inorder Traversal"
    tree.inorder(tree.instance_variable_get(:@root))
    puts "\nPreorder Traversal"
    tree.preorder(tree.instance_variable_get(:@root))
    puts "\nPostorder Traversal"
    tree.postorder(tree.instance_variable_get(:@root))
    
    # Output
    # Inorder Traversal
    # 3 5 7 10 12 15 18
    # Preorder Traversal
    # 10 5 3 7 15 12 18
    # Postorder Traversal
    # 3 7 5 12 18 15 10
    
    # Time Complexity
    # Insertion: O(log n)
    # Traversal: O(n)
    
    # Space Complexity
    # O(n) where n is the number of nodes in the tree
    
    # Pros
    # - Easy to implement
    # -  