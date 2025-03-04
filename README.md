# Arduino Sanitary Napkin Dispenser

## Overview
This project is an Arduino-based sanitary napkin dispenser that uses multiple components such as stepper motors, servos, an LCD, and a sound module. The dispenser allows users to purchase sanitary napkins with coins and provides an interactive display and sound feedback.

## Components
- **Stepper Motor**: Controls the dispensing mechanism.
- **Servos**: Operate two pads for different types of sanitary napkins.
- **Liquid Crystal Display (LCD)**: Displays information to the user.
- **TMRpcm Library**: Plays audio feedback for user interactions.
- **Limit Switches**: Detect coin insertion.
- **SD Card Module**: Stores and plays audio files.

## Prototype and Wiring
The design of the prototype and wiring diagrams are available in the repository:
- **Wiring Design**: Created using Fritzing.
- **3D Design**: Created using 123D Design.

## Code
The main code for the project initializes and controls all the components. It handles the motor movements, updates the display, plays audio, and monitors the limit switches to detect coin insertion.

## Getting Started
### Prerequisites
- Arduino Board
- Stepper Motor
- Servos
- LCD
- SD Card Module
- Limit Switches
- TMRpcm and other relevant libraries

### Installation
1. Clone the repository: `git clone <repository_url>`
2. Open the project in the Arduino IDE.
3. Ensure you have all the necessary libraries installed:
    - `Stepper`
    - `LiquidCrystal`
    - `TMRpcm`
    - `Servo`
    - `SD`
4. Upload the code to the Arduino board.

### Usage
1. Insert the coins as specified (1 Birr or 50 Cent).
2. The LCD will display the current balance and the remaining amount needed.
3. When the required amount is reached, the motor will dispense a sanitary napkin.
4. Audio feedback will be provided during the interaction.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request if you have suggestions for improvements or new features.

## License
This project is licensed under the MIT License.
