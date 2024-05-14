#include "TideNetwork.h"
#include "Utils.h"

ESP8266WiFiMulti wifiMulti; // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

TideNetwork::TideNetwork(Configuration *config)
{
  this->config = config;
}

enum WifiState
{
  DISCONNECTED,
  CONNECTING,
  CONNECTED
};

WifiState wifiState = DISCONNECTED;
unsigned long wifiConnectStart;

void TideNetwork::setup()
{

  // Initial state
  wifiState = CONNECTING;
  wifiConnectStart = millis();

  // Set up the Wi-Fi credentials
  int wifiCount = this->config->getWifiNetworksCount();
  for (int i = 0; i < wifiCount; i++)
  {
    WifiCredentials credentials = this->config->getWifiNetworks()[i];
    wifiMulti.addAP(credentials.SSID.c_str(), credentials.key.c_str());
  }

  Serial.println("[TideNetwork] WiFi set up complete. Connecting to Wi-Fi networks...");
  wifiMulti.run();
}

void TideNetwork::loop()
{

  // Everything's fine. No need to do anything
  if(wifiState == CONNECTED && WiFi.status() == WL_CONNECTED){
    return;
  }

  // After 5 seconds of starting the connection, check if we're connected
  if (wifiState == CONNECTING && millis() - wifiConnectStart > 5000)
  {
    // Great, we're connected
    if (WiFi.status() == WL_CONNECTED)
    {
      wifiState = CONNECTED;

      Serial.print("[TideNetwork] Connected to ");
      Serial.println(WiFi.SSID()); // Tell us what network we're connected to
      Serial.print("IP address:\t");
      Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer
    }
    // We failed to connect
    else
    {
      wifiState = DISCONNECTED;
      Serial.println("[TideNetwork] Failed to connect to WiFi");
    }
  }
  // We were connected and lost connection, or we failed to connect
  // either way, we need to try to reconnect
  else if (
    (wifiState == CONNECTED && WiFi.status() != WL_CONNECTED) ||
    wifiState == DISCONNECTED)
  {
    Serial.println("[TideNetwork] Connection lost. Attempting to reconnect...");
    wifiMulti.run();
    wifiState = CONNECTING;
    wifiConnectStart = millis();
  }
}
