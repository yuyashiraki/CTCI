/*
Q: Design the data structures for a deck of cards. How you would subclass the data structures to implement blackjack.
Step 1. Handle ambiguity
Step 2. Define Core Objects
    - card
    - deck
    - person
    - player
    - dealer
    - hand
    - chip
    - bet
Step 3. Analyze Relationship
    - person
        - dealer
            - deck
                - card[]
            - chip
        - player
            - hand
                - card[]
            - chip
            - bet
Step 4. Investigate Actions
    - deck
        void shuffle()
        void add(position, card)
        card pop()
    - dealer
        - pass(card, person)
        - get(card)
    - player
        - void bet(int)
*/
