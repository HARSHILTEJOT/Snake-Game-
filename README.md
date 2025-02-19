# 🐍 Snake Game

Welcome to the **Snake Game**! This is a console-based snake game built using **C++** with support for both **Windows** and **Linux** systems.

## 📌 Features
- 🎮 **Smooth Movement** 
- 🏆 **Scoring System**
- 🌟 **Customizable Difficulty Levels**
- 🎨 **ANSI Escape Sequences for Colors and Cursor Manipulation**
- 🔲 **Dynamic Terminal Size Adjustments**
- 🚀 **Cross-Platform Support**

## 📥 Installation
### Prerequisites
- Ensure you have a **C++ compiler** (g++ or MSVC)
- **Linux Users**: Ensure `termios.h`, `sys/ioctl.h` headers are available

### Steps
1. Clone the repository from GitHub:
   ```sh
   git clone https://github.com/HARSHILTEJOT/Snake-Game-
   ```
 
2. Change directory
   ```sh
   cd Snake_Game
   ```
   
3. Compile the game:
   ```sh
   g++ Snake_Game.cpp -o Snake_Game
   ```
   **For Windows (MinGW users)**:
   ```sh
   g++ Snake_Game.cpp -o Snake_Game.exe -static-libstdc++ -static-libgcc
   ```

4. Run the game:
   - *On Linux/macOS*:
     ```sh
     ./Snake_Game
     ```
   - *On Windows*:
     ```sh
     ./Snake_Game.exe
      ```

## 🎮 Usage
1. Run the game and enter your name.
2. Select a difficulty level:
   - `1` Easy
   - `2` Medium
   - `3` Hard
   - `4` Expert
3. *Control the Snake*:

| Key | Action |
|-----|--------|
| W | Move Up |
| A | Move Left |
| S | Move Down |
| D | Move Right |

4. Eat the `#` food item to grow your snake and increase your score.
5. Avoid colliding with the walls and your own body.

## 📊 Data Structure Analysis
### **Data Structures Used**
1. **Linked List**
  - Implemented using a Node structure.
  - The snake's body is represented as a dynamic linked list, where each segment is a node.
  - The head represents the snake’s current position, while tail represents the last segment.
  - Allows efficient insertion and deletion of snake segments, ensuring smooth gameplay.

2. **Enum (`enum SnakeDirection`)**
   - Defines possible movement directions: `Up`, `Down`, `Left`, and `Right`.
   - Helps in maintaining game logic for movement.

3. **Pair (`std::pair<int, int>`)**
   - Represents the position `(x, y)` of the snake's head and body segments.
   - Allows structured access to coordinates without needing a separate `struct`.

4. **Custom Classes (`Snake`, `Food`,`Game`)**
   - `Snake` class:
     - Stores body segments in form of a linked list.
     - Handles movement logic and collision detection.
     - Also Handle growth of snake.
   - `Food` class:
     - Randomly generates food positions within game boundaries.
     - Uses `rand()` for randomization.
   - `Game` class:
      - Store the game controls and updates game accordingly.

### **Object-Oriented Approach**
- **Encapsulation**: The Snake and Food classes encapsulate game-related data and logic, preventing direct access to internal attributes and ensuring better control over game mechanics.
- **Abstraction**: The complexity of the game mechanics is hidden within well-defined classes, allowing users to interact with high-level methods without worrying about implementation details.
- **Polymorphism**: By defining virtual functions (if needed), the game can support different behaviors for various objects, such as different types of food with unique effects on the snake.
- **Modularity**: Game logic is separated into different functions.
- **Cross-Platform Compatibility**: Uses `#ifdef _WIN32` for Windows-specific code and `termios.h` for Linux.
- **Dynamic Memory Allocation**:
   - The Snake class uses a linked list to dynamically allocate memory for each new segment.
   - Memory is managed properly using constructors and destructors to prevent memory leaks.

## 🤝 Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

### Contributors
-HARSHILTEJOT-(https://github.com/HARSHILTEJOT)

## 📜 License
This project is licensed under the **MIT License**.
