#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "LEDControl.h"

void setup() {
    // Initialize serial communication for debugging
    Serial.begin(115200);
    
    // Initialize the LEDs
    initializeLEDs();
    
    // Create the LED control task
    xTaskCreate(controlLEDs, "LED Control Task", 1024, NULL, 1, NULL);
    
    // Set custom intervals
    setRedLEDBrightness(128); // Example: set red LED brightness to 128
    setGreenLEDBrightness(64); // Example: set green LED brightness to 64
    setBlueLEDBrightness(255); // Example: set blue LED brightness to 255

}

void loop() {
    // Example sequences to test LED behaviors and colors

    // Turn the LED off
    Serial.println("Test: LED Off");
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

    // Turn the LED on with different colors
    Serial.println("Test: LED On Red");
    ledBehavior = LED_BEHAVIOR_ON;
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED On Green");
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED On Blue");
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay


    // Set the LED to slow blink
    Serial.println("Test: LED Slow Blink Red");
    ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
    ledColor = LED_COLOR_RED;
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED Slow Blink Green");
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED Slow Blink Blue");
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    Serial.println();
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

    // Set the LED to blink
    Serial.println("Test: LED Blink Red");
    ledBehavior = LED_BEHAVIOR_BLINK;
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED Blink Green");
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED Blink Blue");
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay


    // Set the LED to fast blink
    Serial.println("Test: LED Fast Blink Red");
    ledBehavior = LED_BEHAVIOR_FAST_BLINK;
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED Fast Blink Green");
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay
    
    Serial.println("Test: LED Fast Blink Blue");
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println();
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay


    // Set the LED to cycle through colors
    Serial.println("Test: LED Cycle");
    ledBehavior = LED_BEHAVIOR_CYCLE;
    vTaskDelay(6000 / portTICK_PERIOD_MS);
    Serial.println();
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1 second delay

    // Repeat the sequence
}
