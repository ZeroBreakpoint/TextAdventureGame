# TextAdventureGame

This project is my C++ console-based text adventure game created for an assessment at the Academy of Interactive Entertainment (AIE).  It features a 3x3 grid of rooms that the player can explore, interactive items implemented with class inheritance and use of my 'customstringutilityclass' project used for input handling and spellbook management.  The player can move, interact with objects, and use commands processed through custom string utilities.

## Features

- **Grid-Based World**: A 3x3 room map is displayed using ASCII art. The player navigates with directional commands (`north`, `south`, `east`, `west`).
- **Item System with Inheritance**:
  - Base class: `Item`
  - Derived classes:
    - `BoxOfDonuts` – lets the player consume donuts until empty.
    - `Lamp` – toggles on and off with state tracking.
    - `Cat` – starts purring when interacted with.
- **Spellbook Functionality**:
  - `Player` class holds a sorted list of spells.
  - Spells can be searched using **binary search**.
  - Supports commands like `book` to open the spellbook and check known spells interactively.

## Object-Oriented Design

- Demonstrates **multiple levels of inheritance** via `Item -> DerivedItems`.
- Clean modular structure: `Game`, `Room`, `Player`, `Item`, `String` classes.
- Emphasis on **encapsulation** and **polymorphism** through virtual `Use()` and `Description()` methods.

## Custom String Class
A fully custom `String` class is used instead of `std::string` for:
- Input handling
- Case-insensitive comparisons
- Searching (`Find`, `Replace`, etc.)
- Command interpretation (`ToLower`, `ReadFromConsole`, `CStr`, etc.)

## Spell System
Player spells include:
"fairy", "fire", "thunder", "water", "wind", 
"ascend", "recall", "ultrahand"
Players can view the list via the book command.

Input a spell name to check if it's known using a binary search.

The spell system demonstrates efficient searching and use of the custom string class for interaction.

## This project demonstrates:

Inheritance and virtual function overriding

Text parsing with a custom-built string class

Game state handling via encapsulated class structures

Binary search applied to player state for efficiency

