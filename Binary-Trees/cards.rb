
module Rank
    ACE = 0
    TWO = 1
    THREE = 2
    FOUR = 3
    FIVE = 4
    SIX = 5
    SEVEN = 6
    EIGHT = 7
    NINE = 8
    TEN = 9
    JACK = 10
    QUEEN = 11
    KING = 12
    JOKER = 13
    NULL = 14
end

module Suit
    HEARTS = 0
    SPADES = 1
    DIAMONDS = 2
    CLUBS = 3
    NULL = 4
end

class Card

    @@suit = Suit::NULL
    @@rank = Rank::NULL

    @@ranks = ["Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Jack", "Queen", "King", "Joker", "NULL"]
    @@suits = ["Hearts", "Spades", "Diamonds", "Clubs", "NULL"]

    def initialize(sSuit, rRank)
        @@suit = sSuit
        @@rank = rRank
    end

    def print()
        puts @@ranks[@@rank] + " of " + @@suits[@@suit]
    end
        

end

@rng = Random.new

20.times do 
    @suit = @rng.rand(Suit::NULL - 1)
    @rank = @rng.rand(Rank::NULL - 1)

    @card = Card.new(@suit, @rank)
    @card.print
end