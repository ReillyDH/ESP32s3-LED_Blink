# ESP32-S3 LED Blink Example

This is a simple FreeRTOS-based LED blink project for the Freenove ESP32-S3 WROOM-1 board.  
It demonstrates:

- Struct-based LED abstraction
- GPIO control using ESP-IDF
- FreeRTOS task delay handling
- Active-low LED handling

## Requirements

- ESP32-S3 Freenove board
- ESP-IDF v5.5.2
- USB-UART connection (COM3 on Windows)

## How to Build & Flash

```bash
idf.py set-target esp32s3
idf.py build
idf.py flash monitor -p <YOUR_COM_PORT>