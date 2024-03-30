## Sensora Event at KIIT
# Reaction Time Game 🎮⏱️

Welcome to the **Reaction Time Game**! Test your reflexes and challenge your friends with this fun and interactive game built for the ESP8266 platform.

## How It Works 🤖

The game utilizes a series of LEDs and buttons to create a random sequence that players must follow. Points are scored by accurately pressing the buttons in the correct order, as quickly as possible. The game is connected to Adafruit IO, allowing for real-time data tracking and leaderboards.

## Features ✨

- **Random Sequence Generation**: Keeps the game unpredictable and challenging.
- **Real-Time Data Tracking**: Monitor your performance and compete with others.
- **Player Name Input**: Personalize your game experience with your name.
- **Start Animation**: Get ready for the action with a cool starting light sequence.

## Hardware Requirements 🛠️

- ESP8266 WiFi Module (Nodemcu  or any other compatible module)
- 7 LEDs ( 3 for start indicator and 4 for corresponding buttons )
- 4 Buttons (D0, D1, D2, D5)
- 1 Buzzer (A0)

## Setup 📐

1. Connect the hardware according to the schematic provided.
2. Flash the ESP8266 with the provided code.
3. Connect to the WiFi network `wifi_ssid` with the password `wifi_password`.
4. Start the game and have fun!

## Code Snippet 📝

```cpp
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
// rest of the code
```


## Troubleshooting 🔧

If you encounter issues while setting up or playing the game, here are some common fixes:

    WiFi Connection Issues: Ensure the credentials are entered correctly and that the ESP8266 is within range of the router.
    LEDs Not Lighting Up: Check the wiring and ensure the pins are configured correctly in the code.
    Button Response Lag: Debounce the buttons in the code to prevent false triggering.

## Media 📸🎥

Check out these videos and photos to see the Reaction Time Game in action!

    Gameplay Video
    Hardware Setup Photo

## Stay Connected 📢

Follow the project on Instagram for updates and cool new features!

    Reaction Time Game on Instagram

## Contributing 🤝

Interested in contributing to the Reaction Time Game? Great! Feel free to fork the repository, make your changes, and submit a pull request.

# License 📜

This project is licensed under the GPL - see the LICENSE.md file for details.

## Acknowledgments 🙏

    Thanks to Adafruit for providing the MQTT library.
    Shoutout to all the beta testers and contributors.
# Happy Gaming! 🕹️
