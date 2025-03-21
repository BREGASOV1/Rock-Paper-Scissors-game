# Rocket-Paper-Scissors Game (C++)

A feature-rich console implementation of the classic game with enhanced visual feedback and statistical tracking.

## Features
- 🎮 **Extended Gameplay**: Play Rocket-Paper-Scissors (3-choice variant)
- 🖥️ **Interactive Interface**: 
  - Color-coded round results
  - System sound effects for key events
  - Clear round-by-round statistics
- 📊 **Comprehensive Tracking**:
  - Detailed per-round results
  - Final game statistics summary
  - Multi-round session support
- 🔒 **Input Validation**: Robust error handling for user inputs

## Technical Implementation
- **Core C++ Concepts**:
  - Enum classes for game state management
  - Struct-based data organization
  - Modular function architecture
  - System console manipulation (`system()` calls)
- **Key Algorithms**:
  - Random number generation for AI choices
  - Game logic matrix for winner determination
  - Recursive menu system

## How to Run
1. **Clone repository**:
   ```bash
   git clone https://github.com/BREGASOV1/rocket-paper-scissors.git
Compile:
g++ RockPaperScissors.cpp -o rps_game
Run:
# Windows
rps_game.exe
# Linux/macOS (requires terminal color support)
./rps_game
