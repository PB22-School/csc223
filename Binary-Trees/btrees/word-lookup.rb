require_relative 'btree'

NOT_ALLOWED = " '\"\\?/.,<>!@#$%^&*()_=-+{}[]|~`\t\n"

def encode(str)

  str = str.downcase

  NOT_ALLOWED.each_char do |i|
    str = str.gsub(NOT_ALLOWED[i], '')
  end

  sum = 0

  str.each_char do |l_i|
    if str[l_i].ord >= 256
      sum = sum * 256
    else
      sum = sum * 256 + str[l_i].ord
    end
  end

  sum

end

def decode(num)

  str = ""

  while num > 0
    str += (num % 256).chr
    num /= 256
  end

  str.reverse()

end

puts decode(encode("hello world"))

word_tree = BTree.new(4)
lines = File.readlines("words.txt")

a_words = []

(1..10000).each do
  random_number = rand(lines.length)

  while word_tree.has?(encode(lines[random_number]))
    random_number = rand(lines.length)
  end
  
  a_words << lines[random_number]
  word_tree.insert(encode(lines[random_number]))
end

# word_tree.print_tree

# p a_words

loop do
  print "Type word or 'quit' to quit: "
  input = gets.chomp

  if input == "quit"
    break
  end

  tree_words = word_tree.find_matches(encode(input), 10)
  puts tree_words.map {|word| decode(word)}

  # loop_words = a_words.filter {|word| word.start_with?(input) }
  # puts loop_words

end