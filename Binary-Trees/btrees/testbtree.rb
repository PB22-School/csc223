require_relative 'btree'

btree = BTree.new(4)

srand(4032948)

(0..100).each do

  r_n = rand(100)

  if !btree.has?(r_n)
    # puts "inserting #{r_n}"
    btree.insert(r_n)
    # btree.print_tree
    # puts "---------"
  end
end

def is_valid(tree)
  if tree.tree_valid?
    puts "tree is valid."
    return true
  end

  btree.print_tree

end

is_valid(btree)

(0..100).each do
  
  r_n = rand(100)

  until btree.has?(r_n)
    r_n = rand(100)
  end

  is_valid(btree)

end

btree.print_tree
p btree.find_matches(15, 10)