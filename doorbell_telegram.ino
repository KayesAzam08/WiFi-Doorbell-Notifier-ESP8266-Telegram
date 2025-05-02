#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* telegramBotToken = "YOUR_BOT_TOKEN";
const char* chatID = "YOUR_CHAT_ID";

const int buttonPin = D1;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  bool currentState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && currentState == LOW) {
    sendTelegramMessage("Doorbell pressed!");
    Serial.println("Button Pressed");
    delay(2000); // debounce delay
  }
  lastButtonState = currentState;
}

void sendTelegramMessage(String message) {
  WiFiClientSecure client;
  client.setInsecure();

  if (client.connect("api.telegram.org", 443)) {
    String url = "/bot" + String(telegramBotToken) + "/sendMessage?chat_id=" + String(chatID) + "&text=" + message;
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.telegram.org\r\n" +
                 "Connection: close\r\n\r\n");
    delay(1000);
    while (client.available()) {
      String line = client.readStringUntil('\n');
      Serial.println(line);
    }
  } else {
    Serial.println("Connection failed");
  }
}