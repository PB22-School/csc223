class Node
  def initialize(val, left = nil, right = nil)
    @val = val
    @value = val
    @left = left
    @right = right
  end

  def val
    @val
  end

  def value
    @value
  end

  def left
    @left
  end

  def right
    @right
  end
end

def max(a, b)
  if a > b
    return a
  end
  return b
end

def _build_tree_string(root, curr_index, include_index, delimiter = '-')

  if not root
    return [], 0, 0, 0
  end

  line1 = []
  line2 = []

  if include_index
    node_repr = "#{curr_index}#{delimiter}#{root.val}"
  else
    node_repr = root.val.to_s
  end

  gap_size = node_repr.length
  new_root_width = gap_size

  l_box, l_box_width, l_root_start, l_root_end = _build_tree_string(root.left, 2 * curr_index + 1, include_index, delimiter)

  r_box, r_box_width, r_root_start, r_root_end = _build_tree_string(root.right, 2 * curr_index + 2, include_index, delimiter)

  if l_box_width > 0
    l_root = ((l_root_start + l_root_end) / 2).to_i + 1
    line1.push(" " * (l_root + 1))
    line1.push("_" * (l_box_width - l_root))
    line2.push(" " * l_root + "/")
    line2.push(" " * (l_box_width - l_root))
    new_root_start = l_box_width + 1
    gap_size += 1
  else
    new_root_start = 0
  end

  line1.push(node_repr)
  line2.push(" " * new_root_width)

  if r_box_width > 0
    r_root = ((r_root_start + r_root_end) / 2).to_i
    line1.push("_" * r_root)
    line1.push(" " * (r_box_width - r_root + 1))
    line2.push(" " * r_root + "\\")
    line2.push(" " * (r_box_width - r_root))
    gap_size += 1
  end

  new_root_end = new_root_start + new_root_width - 1

  gap = " " * gap_size
  new_box = [line1.join(""), line2.join("")]
  # new_box = ["".join(line1), "".join(line2)]
  0.upto(max(l_box.length, r_box.length)) do |i|
    l_line = i < l_box.length ? l_box[i] : (" " * l_box_width)
    r_line = i < r_box.length ? r_box[i] : (" " * r_box_width)
    new_box.push(l_line + gap + r_line)
  end

  # Return the new box, its width and its root repr positions
  return new_box, new_box[0].length, new_root_start, new_root_end
end

def pprint(n, index = false, delimiter = '-')
  lines = _build_tree_string(n, 0, index, delimiter)[0]
  # print("\n" + "\n".join((line.rstrip() for line in lines)))

  print_arr = []
  for i in lines
    print_arr.push(i.rstrip)
  end

  print("\n" + print_arr.join("\n"))
end

# tree = Node.new(18, Node.new(8, Node.new(2), Node.new(3)), Node.new(5, Node.new(4)))

# pprint(tree, false)