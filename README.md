# WiFi Doorbell Notifier using ESP8266 & Telegram

This project turns your ESP8266 into a smart doorbell that sends a Telegram alert when the button is pressed.

## Features
- Detects doorbell press via push button
- Sends instant Telegram notification
- Wi-Fi based, no extra IoT platform needed
- Optional buzzer alert

## Components Required
- ESP8266 NodeMCU
- Push Button
- 10k Resistor
- Breadboard & jumper wires
- Optional: Buzzer

## Circuit Diagram
Connect the button between D1 (GPIO5) and GND.

## Telegram Bot Setup
1. Open Telegram and search `@BotFather`
2. Create a new bot and get the token
3. Start your bot and open:
   `https://api.telegram.org/bot<YOUR_TOKEN>/getUpdates`
4. Get your `chat_id` from the JSON response

## Code Configuration
Replace the following in the code:
- `YOUR_SSID` and `YOUR_WIFI_PASSWORD`
- `YOUR_BOT_TOKEN`
- `YOUR_CHAT_ID`

## Output Example
When the button is pressed, your Telegram will receive:
```
Doorbell pressed!
```

## Author
**Kayes Azam**

---
Licensed under the [MIT License](LICENSE).