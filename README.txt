GoFish! README
Author: Nicholas Taylor
Date: 11/05/2019

How to Use:
 - Either use this unzipped folder as a directory or 
   create a new one called GoFish and copy the contents of this over
 - Type "make" into the command line after moving to the directory with the files from the zip
 - Start the program with "./GoFish"
 - The game will output all actions taken by each of the two computer players to the output file "go_fish.txt"
 - The Rules that the computers play by are:
        1. Each player is dealt 5 cards
        2. Two cards of the same rank form a book which you take out of your hand and "place on the table" (a vector in this case)
        3. Player 1 starts, they ask player 2 if they have a card that is to match one in their hand
        4. If player 2 has a card, they have to give it to player 1 who then books their new pair
        5. If player 2 doesn't have the card, they say "Go Fish!" and player 1 draws a card
        6. If in your turn you book cards, you keep playing until you can't book anymore cards
        7. The game ends when all 26 pairs are booked, player with the most books wins