# Snake and Ladder Game

## Introduction

This is a console-based Snake and Ladder game implemented in C++. It supports up to four players and provides a fun, interactive way to play the classic game. Players take turns rolling a dice, and their positions on the board are updated based on the dice roll. The game includes snakes and ladders that alter players' positions on the board.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Rules](#rules)
- [Dependencies](#dependencies)
- [Contributors](#contributors)
- [License](#license)

## Features

- Supports 2 to 4 players.
- Interactive dice rolling.
- Snakes and ladders that modify players' positions.
- Simple console-based user interface.
- Clear display of players' positions on the board.

## Installation

To compile and run the game, follow these steps:

1. Ensure you have a C++ compiler installed on your system.
2. Download the `Snake And Ladder Game.cpp` file.
3. Open a terminal and navigate to the directory containing the downloaded file.
4. Compile the code using the following command:
   ```sh
    g++ -o Snake And Ladder Game.cpp
    ``` 
5. Run the compiled program:
   ```sh
    ./Snake and Ladder Game
    ```

## Usage

1. Run the compiled program.
2. Follow the on-screen instructions to select the number of players (2, 3, or 4).
3. Enter the names of the players.
4. Players take turns rolling the dice by pressing any key.
5. The game displays the current positions of the players after each turn.
6. The game continues until a player reaches or exceeds position 100, at which point the game announces the winner.

## Rules

1. Roll the dice by pressing any character.
2. If you roll three consecutive sixes, your score for that turn is reset to 0.
3. Ladders will boost your score.
4. Snakes will reduce your score.
5. The first player to reach 100 or more wins the game.

## Dependencies

- C++ Standard Library

## Contributors

- [Muhammad Abubakar Saddique](https://github.com/Abubakar-00)

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Additional Information

The positions of the ladders and snakes are as follows:

### Ladders

- Ladder 1: 13 to 57
- Ladder 2: 36 to 62
- Ladder 3: 53 to 93

### Snakes

- Snake 1: 29 to 4
- Snake 2: 66 to 17
- Snake 3: 95 to 41

The board is displayed in a 10x10 grid with positions from 1 to 100. Players' positions are indicated by their respective markers ('A', 'B', 'C', 'D') on the board.

