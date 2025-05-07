require_relative 'binary-search-trees.rb'

# tree = Tree.new()

# tree.pretty_print

file = File.read("testfile.txt")

# bag of characters
bow = {}

file.split('').each do |i|
  if bow.key?(i)
    bow[i] += 1
  else
    bow[i] = 1
  end
end

# puts bow

class Huffman_Node
  def initialize(weight, data)
    @weight = weight
    @data = data
  end

  # def (obj)>
  #   obj > @weight
  # end

  def >(obj)
    if @weight > obj.weight
      return @weight
    end
    return obj
  end

  # def (obj)<
  #   obj < @weight
  # end

  def <(obj)
    if @weight < obj.weight
      return @weight
    end
    return obj.weight
  end

  def weight
    @weight
  end

  def data
    @data
  end

end

queue_of_nodes = []

bow.keys.each do |key|
  queue_of_nodes.push(Huffman_Node.new(bow[key], key))
end

# p merge_sort(queue_of_nodes)

tree = Tree.new(queue_of_nodes)
tree.pretty_print