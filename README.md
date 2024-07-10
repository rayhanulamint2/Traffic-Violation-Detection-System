# Traffic Violation Detection System

This project detects traffic rule violations using an Arduino and ESP32-CAM. The system changes traffic lights at set intervals and uses an ultrasonic sensor to detect vehicles passing during a red light. When a violation is detected, a photo of the vehicle is captured and sent to a Telegram bot for real-time monitoring and documentation.

## Components

- Arduino UNO
- ESP32-CAM
- Ultrasonic Sensor (HC-SR04)
- Traffic lights (Red, Yellow, Green LEDs)
- Jumper Wires
- Breadboard
- 5V Power Supply
- Wi-Fi network
- Telegram account

## Installation

### 1. Setting Up the Telegram Bot

#### Create a Telegram Bot:

1. Open Telegram and search for "BotFather".
2. Start a chat with BotFather and type `/start`.
3. Create a new bot by typing `/newbot`. Follow the prompts to give your bot a name (e.g., "TrafficViolateSust") and a unique username (e.g., "traffic_tanvir_bot").
4. BotFather will provide a token. Save this token for later use.

#### Get Your Chat ID:

1. Search for "Get My ID" bot on Telegram.
2. Start a chat with the bot by typing `/start`.
3. Note down the chat ID provided.

### 2. ESP32-CAM Setup

#### Install Board Support:

1. Open Arduino IDE.
2. Go to `File` > `Preferences`.
3. In the "Additional Board Manager URLs" field, add this URL: `https://dl.espressif.com/dl/package_esp32_index.json`.
4. Go to `Tools` > `Board` > `Board Manager` and search for "ESP32". Install the package.

#### Connect ESP32-CAM:

1. Connect the ESP32-CAM to your computer using an FTDI programmer or similar device.

#### Modify and Upload Code:

1. Open the provided `esp-code` in the Arduino IDE.
2. Replace `wifi name`, `wifi password`, `Your telegram id`, and `Enter the token given when new bot is created` with your credentials.
3. Select `AI Thinker ESP32-CAM` from the `Board` menu and the correct port.
4. Upload the code to the ESP32-CAM.

### 3. Arduino Setup

#### Connect Components:

1. Connect the ultrasonic sensor to the Arduino.
2. Connect the traffic light LEDs to the Arduino pins.

#### Upload Code:

1. Open the provided `arduino-code` in the Arduino IDE.
2. Select `Arduino UNO` from the `Board` menu and the correct port.
3. Upload the code to the Arduino.

## Usage

### Power the System:

1. Ensure all components are powered appropriately.

### Monitor Traffic Violations:

1. The traffic lights will change at set intervals.
2. If a vehicle passes through the sensor during a red light, the Arduino will signal the ESP32-CAM to capture a photo.
3. The photo will be sent to the Telegram bot for monitoring.

## Acknowledgments

- Inspired by various online tutorials and projects.
- Special thanks to the contributors of the Arduino and ESP32 community for their support and resources.
