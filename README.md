# iot-plant-watering

This program runs in an ESP32 or 8266. It measures soil humidity and waters the plant when the humidity is under a threshold.    

A capacitive humidity sensor is recommended, it's measured through an analog pin.    

The watering is only a digital pin control, it should be correctly set up to power on a relay-like circuit.


Libraries:    
- [WebSockets](https://github.com/Links2004/arduinoWebSockets)