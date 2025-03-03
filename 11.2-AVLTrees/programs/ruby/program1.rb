class Node
  attr_accessor :lchild, :data, :height, :rchild

  def initialize(data)
    @data = data
    @height = 1
    @lchild = @rchild = nil
  end
end

class AVLTree
  attr_accessor :root

  def initialize
    @root = nil
  end

  def node_height(p)
    hl = p && p.lchild ? p.lchild.height : 0
    hr = p && p.rchild ? p.rchild.height : 0
    [hl, hr].max + 1
  end

  def balance_factor(p)
    hl = p && p.lchild ? p.lchild.height : 0
    hr = p && p.rchild ? p.rchild.height : 0
    hl - hr
  end

  def ll_rotation(p)
    pl = p.lchild
    plr = pl.rchild

    pl.rchild = p
    p.lchild = plr

    p.height = node_height(p)
    pl.height = node_height(pl)

    @root = pl if @root == p

    pl
  end

  def lr_rotation(p)
    pl = p.lchild
    plr = pl.rchild

    pl.rchild = plr.lchild
    p.lchild = plr.rchild

    plr.lchild = pl
    plr.rchild = p

    pl.height = node_height(pl)
    p.height = node_height(p)
    plr.height = node_height(plr)

    @root = plr if @root == p

    plr
  end

  def rr_rotation(p)
    pr = p.rchild
    prl = pr.lchild

    pr.lchild = p
    p.rchild = prl

    p.height = node_height(p)
    pr.height = node_height(pr)

    @root = pr if @root == p

    pr
  end

  def rl_rotation(p)
    pr = p.rchild
    prl = pr.lchild

    pr.lchild = prl.rchild
    p.rchild = prl.lchild

    prl.rchild = pr
    prl.lchild = p

    pr.height = node_height(pr)
    p.height = node_height(p)
    prl.height = node_height(prl)

    @root = prl if @root == p

    prl
  end

  def r_insert(p, key)
    if p.nil?
      return Node.new(key)
    end

    if key < p.data
      p.lchild = r_insert(p.lchild, key)
    elsif key > p.data
      p.rchild = r_insert(p.rchild, key)
    end

    p.height = node_height(p)

    if balance_factor(p) == 2 && balance_factor(p.lchild) == 1
      return ll_rotation(p)
    elsif balance_factor(p) == -2 && balance_factor(p.rchild) == -1
      return rr_rotation(p)
    elsif balance_factor(p) == 2 && balance_factor(p.lchild) == -1
      return lr_rotation(p)
    elsif balance_factor(p) == -2 && balance_factor(p.rchild) == 1
      return rl_rotation(p)
    end

    p
  end

  def inorder(p)
    if p
      inorder(p.lchild)
      print "#{p.data}, "
      inorder(p.rchild)
    end
  end
end

tree = AVLTree.new
tree.root = tree.r_insert(tree.root, 10)
tree.r_insert(tree.root, 5)
tree.r_insert(tree.root, 2)
tree.r_insert(tree.root, 20)
tree.r_insert(tree.root, 1)

tree.inorder(tree.root)


