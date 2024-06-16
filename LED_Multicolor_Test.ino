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
    setBlinkInterval(500); // Example: set blink interval to 500ms
    setFastBlinkInterval(50); // Example: set fast blink interval to 50ms
    setSlowBlinkInterval(2000); // Example: set slow blink interval to 2000ms
    setCycleInterval(1500); // Example: set cycle interval to 1500ms
}

void loop() {
    // Example sequences to test LED behaviors and colors

    // Turn the LED off
    ledBehavior = LED_BEHAVIOR_OFF;
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // Turn the LED on with different colors
    ledBehavior = LED_BEHAVIOR_ON;
    
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // Set the LED to blink
    ledBehavior = LED_BEHAVIOR_BLINK;
    
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // Set the LED to fast blink
    ledBehavior = LED_BEHAVIOR_FAST_BLINK;
    
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // Set the LED to slow blink
    ledBehavior = LED_BEHAVIOR_SLOW_BLINK;
    
    ledColor = LED_COLOR_RED;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_GREEN;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    
    ledColor = LED_COLOR_BLUE;
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // Set the LED to cycle through colors
    ledBehavior = LED_BEHAVIOR_CYCLE;
    vTaskDelay(6000 / portTICK_PERIOD_MS);

    // Repeat the sequence
}
