#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "ATT8aur9F7_EXT";
const char* password = "Lazloian1";

const uint16_t port = 59090;
const char* host = "192.168.1.65";

void setup() 
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("...");
  }

  Serial.print("WiFi connected with IP: ");
  Serial.print(WiFi.localIP());
}

void loop() 
{
  WiFiClient client;
  
  if (!client.connect(host, port))
  {
    Serial.println("Connection to host failed");
    delay(1000);
    return;
  }

  client.print("Hello");
  Serial.println("Hello");
  delay(1000);
}