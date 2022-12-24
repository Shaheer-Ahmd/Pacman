
Game instructions:
1- Move the Pacman with arrow keys.
2- Eat the specified amount of food in the given time whilst avoiding the ghost.

my Approach:
 
PACMAN mechanics:
Basically I have made a map at the beginning and displayed it. I give the pacman a random position in the last row, and I change its rows and columns depending on the user input.
When I have the new position of the pacman, I move the cursor to that (x,y) cordinate and print the pacman (char 'C' in my case) and go back to its initial position and print a space there.

GHOST mechanics:
Ghost's procedude or movement is similar to pacman hoIver, instead of user input, it tracks the pacman itself by comparing its rows and columns. I have tackled the possibility of collision
with a wall using if conditions. For instance, if there is a wall upwards, I further check if there is a wall right , then left and if the three sides are blocked, the ghost goes down.
