# Studying-English-Vocab-Support-Application (Vocab-Quiz)

## Overview

Vocab Quiz is a simple command-line vocabulary quiz game designed to help users memorize English words. The game randomly displays words from `VOCAB.TXT` and requires users to input their translations. User progress is tracked and stored in `USER.BIN`.

## Features

- Randomly quizzes users on vocabulary.
- Tracks user progress and saves experience points.
- Simple command interface:
  - Enter `/play` to start the game.
  - Enter `/exit` to quit.
  - Instructions available in-game.

## Installation

1. Clone this repository:
   ```sh
   https://github.com/DongQuanz/Studying-English-Vocab-Support-Application
   ```
2. Compile the program:
   ```sh
   g++ main.cpp function.cpp instruction.cpp -o vocab_quiz
   ```
3. Run the program:
   ```sh
   ./vocab_quiz
   ```

## Usage

1. Upon launching the program, instructions will be displayed.
2. Enter `/play` to start the quiz.
3. A word will appear, and you must input the corresponding translation.
4. Your answers will be checked, and the score will be recorded.
5. Enter `/exit` at any time to quit.

## Editing `VOCAB.TXT`

The `VOCAB.TXT` file contains the vocabulary words used in the quiz. The structure follows a specific format:

```
word1
part_of_speech1
meaning1
word2
part_of_speech2
meaning2
...
```

### Example:
```
aberration
noun
a departure from what is normal
benevolent
adjective
well-meaning and kindly
cogent
adjective
clear, logical, and convincing
```
Each word entry consists of three lines:
1. The English word.
2. The part of speech (noun, verb, adjective, etc.).
3. The meaning in English.

Ensure that each entry follows this format to avoid errors when loading the vocabulary.

## File Structure

- `main.cpp` - Handles game flow and user interaction.
- `function.cpp/.h` - Contains game logic and file operations.
- `instruction.cpp/.h` - Displays game instructions.
- `VOCAB.TXT` - Contains vocabulary words for the quiz.
- `USER.BIN` - Stores user progress and experience points.

## License

**Copyright (C) 2025 Ngo Nguyen Dong Quan.** All rights reserved.

