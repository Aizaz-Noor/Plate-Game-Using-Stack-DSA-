# Plate Stack Balancing Game

A console-based menu-driven game written in C++ that demonstrates the practical application of the **Stack Data Structure**.

## Description

The "Plate Stack Balancing Game" simulates the real-life physics of stacking plates. You must build a stack of plates one by one, ensuring that a heavier plate is never placed on top of a lighter one. The underlying mechanic uses a customized Stack data structure constructed via arrays.

## Game Rules
- **Winning Condition**: Successfully stack **5 plates** to win the game.
- **Attempts**: You have a maximum of **10 attempts** (an attempt is consumed by choosing any action from the menu).
- **Balancing Rule**: A new plate's weight must be **less than or equal to** the weight of the top plate.
- **Losing Condition**: If you attempt to place a heavier plate on top of a lighter plate, the stack will collapse and you will lose the game!
- **Scoring System**: 
  - **+2 points** for successfully pushing (adding) a plate.
  - **-1 point** for popping (removing) a plate.

## Features
- **Add Plate (Push)**: Prompts for a positive integer weight to stack a new plate.
- **Remove Plate (Pop)**: Removes the top plate from your stack.
- **View Top Plate (Peek)**: Shows the weight of the plate currently at the top of your stack.
- **Display Stack**: Prints all currently stacked plates from top to bottom.
- **Exit**: Quits the game early.

## Concepts Demonstrated
- **Stack Data Structure**: Custom LIFO (Last-In-First-Out) implementation using an array.
- **Stack Operations**: Custom `push()` (add_Plate), `pop()` (remove_Plate), `peek()` (view_Top_plate), `isEmpty()`, and `display()`.
- **Game Loops & State Management**: Using while-loops and booleans to process player input and progression.

## How to Compile and Run
1. Ensure you have a C++ compiler installed (e.g., GCC/MinGW).
2. Open your terminal or command prompt.
3. Compile the code:
   ```bash
   g++ Plate_game_using_stack.cpp -o PlateGame
   ```
4. Run the executable:
   - On Windows: `PlateGame.exe`
   - On Linux/macOS: `./PlateGame`
