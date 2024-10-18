#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

AsyncWebServer server(80);


const int led1 = 12;////////////7othom fel position el s7a7
const int led2 = 13;
const int led3 = 14;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 LED Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; text-align: center; margin: 40px;}
    .button { padding: 10px 20px; font-size: 16px; }
    .on { background-color: #4CAF50; color: white; }
    .off { background-color: #f44336; color: white; }
  </style>
</head>
<body>
  <h1>ESP32 LED Control</h1>
  <p><button class="button on" onclick="fetch('/led1/on')">LED 1 ON</button>
  <button class="button off" onclick="fetch('/led1/off')">LED 1 OFF</button></p>
  <p><button class="button on" onclick="fetch('/led2/on')">LED 2 ON</button>
  <button class="button off" onclick="fetch('/led2/off')">LED 2 OFF</button></p>
  <p><button class="button on" onclick="fetch('/led3/on')">LED 3 ON</button>
  <button class="button off" onclick="fetch('/led3/off')">LED 3 OFF</button></p>
</body>
</html>)rawliteral";


void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);


  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);


  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });


  server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, HIGH);
    request->send(200, "text/plain", "LED 1 ON");
  });
  server.on("/led1/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, LOW);
    request->send(200, "text/plain", "LED 1 OFF");
  });


  server.on("/led2/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, HIGH);
    request->send(200, "text/plain", "LED 2 ON");
  });
  server.on("/led2/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, LOW);
    request->send(200, "text/plain", "LED 2 OFF");
  });


  server.on("/led3/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, HIGH);
    request->send(200, "text/plain", "LED 3 ON");
  });
  server.on("/led3/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, LOW);
    request->send(200, "text/plain", "LED 3 OFF");
  });


  server.begin();
}

void loop() {

}
