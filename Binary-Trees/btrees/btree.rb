
def max(x, y)
  if x > y
    return x
  end
  return y
end

def min(x, y)
  if x < y
    return x
  end
  return y
end

class BNode
  def initialize(keys = [], children = [], max_size = 4)
    @max_size = max_size
    @keys = keys
    @children = children ? children : []
  end

  def keys
    @keys
  end

  def keys=(n_keys)
    @keys = n_keys
  end

  def children
    @children
  end

  def children=(n_children)
    @children = n_children
  end

  def to_s

    children = []

    @children.each do |child|
      children.push(child.to_s)
    end

    return "keys: #{@keys} | children: [#{children.join(', ')}]"
  end

end

def insert_sorted(new_value, arr)
  # if (arr.empty?) or (new_value < arr[0])
  #   arr.insert(0, new_value)
  # elsif new_value > arr[-1]
  #   arr.push(new_value)
  # else
  #   0.upto(arr.length - 1) do |i|
  #     if (arr[i] - new_value) > 0
  #       arr.insert(i, new_value)
  #       break
  #     end
  #   end
  # end

  unless arr.empty?
    set = false
    0.upto(arr.length - 1) do |i|
      if new_value < arr[i]
        arr.insert(i, new_value)
        set = true
        break
      end
    end

    unless set
      arr.push(new_value)
    end
  else
    arr.push(new_value)
  end
end

class BTree < BNode
  def initialize(max_size = 4)
    @max_size = max_size
    @root_node = BNode.new([], [], max_size)
  end

  def insert(ins_val, node = @root_node)

    # first we need to loop until we get to a place where we can insert.

    ret_val = nil
    ret_insert_loc = -1

    unless node.children.empty?
      
      # if this node has a child, figure out which child to go to

      #   22
      # 20  25  30

      insertted = false

      0.upto(node.keys.length - 1) do |i|

        if ins_val < node.keys[i]
          insertted = true
          ret_val = insert(ins_val, node.children[i])
          ret_insert_loc = i

          # if ret_val
          #   insert_sorted(ret_val[0], node.keys)
          #   node.children.insert(i + 1, ret_val[1])
          # end

          break

        end

      end

      unless insertted
        ret_val = insert(ins_val, node.children[-1])
        ret_insert_loc = node.children.length - 1

        # if ret_val
        #   insert_sorted(ret_val[0], node.keys)
        #   node.children.push(ret_val[1])
        # end
      end
    else
      # if we're at a leaf node

      # add ins_val to node's keys
      insert_sorted(ins_val, node.keys)
    end

    if ret_val
      insert_sorted(ret_val[0], node.keys)
      node.children.insert(ret_insert_loc + 1, ret_val[1])
    end


    # now that we've inserted, we want to reorganize the tree if the size > max_size:

    if node.keys.length > @max_size

      # two cases, insert & create new root node or just create new node

      half_max = (@max_size / 2).to_i

      first_half_keys = node.keys.slice(0, half_max)
      second_half_keys = node.keys.slice(half_max + 1, node.keys.length - half_max)

      first_half_children = node.children.slice(0, half_max + 1)
      second_half_children = node.children.slice(half_max + 1, node.keys.length - half_max)

      if node == @root_node

        # puts "root insert + overflow"
        # puts "self"
        # puts node.to_s
        # puts "children:"
        # puts node.children
        # puts "half: #{half_max}\nsize: #{node.children.length}"

        new_root = BNode.new([node.keys[half_max]], [], @max_size)

        # node.keys = [node.keys[half_max]]

        # new_root.children.push(BNode.new(first_half))
        node.keys = first_half_keys
        node.children = first_half_children
        new_root.children.push(node)

        other_node = BNode.new(second_half_keys, second_half_children, @max_size)
        new_root.children.push(other_node)

        @root_node = new_root

      else
        
        # cut the keys in half, create a new node containing the second half, set this node's keys to the first half.
        # then push the value in the middle of this node's keys and the new node to the parent.

        # puts node
        # puts first_half_children
        # puts "middle"
        # puts second_half_children

        half_val = node.keys[half_max]
        node.keys = first_half_keys
        node.children = first_half_children

        return [half_val, BNode.new(second_half_keys, second_half_children, @max_size)]
      end

    end

  end

  def has?(value, node = @root_node)

    # p node.keys

    if node.keys.include?(value)
      return true
    end

    if node.children.empty?
      return false
    end

    0.upto(node.keys.length - 1) do |i|
      if value < node.keys[i]
        return has?(value, node.children[i])
      end
    end

    return has?(value, node.children[-1])
  end

  def remove(value, node = @root_node, parent_node = nil, child_index = -1)

    # first we need to find the value

    unless node.keys.include?(value)

      found = false

      0.upto(node.keys.length - 1) do |i|
        if value < node.keys[i]
          remove(value, node.children[i], node, i)
          found = true
          break
        end
      end

      if (not found) and (not node.children.empty?)
        remove(value, node.children[-1], node, node.children.length - 1)
      end

    else
      # the key to delete is here

      # if (node != @root_node and node.keys.length < 2 and not node.children.empty?) or (node == @root_node and node.keys.length < 1)
      #   index = node.keys.index(value)
      #   node.keys.delete(value)

      #   take_from_left = false

      #   if node.children[index].keys.length > 2
      #     # take from left
      #     take_from_left = true
      #   elsif node.children[index + 1].keys.length > 2
      #     # take from right
      #     take_from_left = false
      #   else
      #     # both have two keys, take from either
      #     take_from_left = (rand() % 1) == 1 ? true : false
      #   end
          
      #   if take_from_left
      #     new_key = node.children[index].keys.delete_at(-1)
      #   else
      #     new_key = node.children[index + 1].keys.delete_at(-1)
      #   end

      #   insert_sorted(new_key, node.keys)

      #   return
      # end

      deleted_from = node.keys.index(value)
      node.keys.delete(value)
      
      # p node.keys

    end

    if node == @root_node and node.keys.length < 1

    elsif node != @root_node and node.keys.length < 2

      # deletion from non leaf node, take from child
      unless node.children.empty?
        # non-leaf node

        take_from_left = false

        if node.children[deleted_from].keys.length > 2
          # take from left
          take_from_left = true
        elsif node.children[deleted_from + 1].keys.length > 2
          # take from right
          take_from_left = false
        else
          # both have two keys, take from either
          take_from_left = (rand() % 1) == 1 ? true : false
        end
          
        if take_from_left
          new_key = node.children[deleted_from].keys.delete_at(-1)
        else
          new_key = node.children[deleted_from + 1].keys.delete_at(-1)
        end

        insert_sorted(new_key, node.keys)

        return

      end



      # prevent wrap arounds
      if child_index == 0
        left_sibling = nil
      else
        left_sibling = parent_node.children[child_index - 1]
      end

      right_sibling = parent_node.children[child_index + 1]
      
      # take from sibling node

      # can we take from the left sibling?
      if left_sibling and left_sibling.keys.length > 2

        parent_take = max(0, child_index - 1)

        cur_middle = parent_node.keys.delete_at(parent_take)
        new_middle = left_sibling.keys.delete_at(-1)
        parent_node.keys.insert(child_index - 1, new_middle)
        node.keys.insert(0, cur_middle)

      elsif right_sibling and right_sibling.keys.length > 2

        parent_take = min(child_index, child_index + 1)

        cur_middle = parent_node.keys.delete_at(parent_take)
        new_middle = right_sibling.keys.delete_at(0)
        parent_node.keys.insert(child_index, new_middle)
        node.keys.insert(node.keys.length, cur_middle)

      else

        # merge with sibling node (if can't take from left or right sibling)

        if child_index == 0
          merge_with_left = false
        elsif child_index == (parent_node.children.length - 1)
          merge_with_left = true
        else
          merge_with_left = (rand() % 1) == 1 ? true : false
        end

        if merge_with_left

          parent_take = max(0, child_index - 1)

          insert_sorted(node.keys[0], left_sibling.keys)
          parent_key = parent_node.keys.delete_at(parent_take)
          insert_sorted(parent_key, left_sibling.keys)
          parent_node.children.delete_at(child_index)
          
        else

          parent_take = min(child_index, child_index + 1)

          insert_sorted(node.keys[0], right_sibling.keys)
          parent_key = parent_node.keys.delete_at(parent_take)
          insert_sorted(parent_key, right_sibling.keys)
          parent_node.children.delete_at(child_index)
          
        end

      end

    end

    # p node.keys

    # deletion from middle (non-leaf), take from child

    # unless node.children.empty?


    # take from sibling node

    # merge with sibling node

  end

  def print_tree(node = @root_node, level = 0, levels = [])

    # puts level

    if level >= levels.length
      levels.push(node.keys.to_s)
    else
      levels[level] += " " + node.keys.to_s
    end

    # print node.keys.to_s

    # puts

    node.children.each do |child|
      print_tree(child, level + 1, levels)
    end

    if (level + 1) < levels.length()
      levels[level + 1] += " | "
    end

    if node == @root_node
      # p node
      puts levels

      # max_line = levels.reduce(0) {|result, current| return (current.length > result ? current.length : result)}
      # puts "max: #{max_line}"

      # 0.upto(levels.length - 1) do |i|
      #   levels[i] = levels[i]
      # end
    end

  end

  def tree_valid?(node = @root_node, l_parent = nil, r_parent = nil)

    last_iter_key = -1

    0.upto(node.keys.length - 1) do |i|

      if l_parent
        # btree definition says left parent key should be less than all of the children's keys.
        if l_parent > node.keys[i]
          puts "left parent key's value (#{l_parent}) is greater than child (#{node.keys[i]})."
          return false
        end
      end

      if r_parent
        # btree definition says right parent key should be greater than all of the children's keys.
        if r_parent < node.keys[i]
          puts "right parent key's value (#{r_parent}) is less than child (#{node.keys[i]})."
          return false
        end
      end

      if node.keys[i] < last_iter_key
        puts "keys not sorted (#{node.keys[i]} < #{last_iter_key})."
        return false
      end

      last_iter_key = node.keys[i]

      left_parent = (i - 1) < 0 ? nil : node.keys[i - 1]

      unless node.children.empty?
        if not tree_valid?(node.children[i], left_parent, node.keys[i])
          return false
        end
      end
      
    end

    if node.children.empty?
      return true
    end

    return tree_valid?(node.children[-1])

  end

  def find_matches(value, total, node = @root_node, matches = [])

    if not(value) or matches.length >= total
      return matches
    end

    0.upto(node.keys.length - 1) do |i|

      if not(node.children.empty?)
        find_matches(value, total, node.children[i], matches)
        
        if matches.length >= total
          return matches
        end

      end

      if node.keys[i] >= value
        matches << node.keys[i]
        
        if matches.length >= total
          return matches
        end
      end
    end

    if matches.length < total and not(node.children.empty?)
      find_matches(value, total, node.children[-1], matches)
    end

    return matches
  end
    
end