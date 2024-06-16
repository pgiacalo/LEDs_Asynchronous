#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Enumerations for LED behavior and color
typedef enum {
    LED_BEHAVIOR_OFF,
    LED_BEHAVIOR_ON,
    LED_BEHAVIOR_BLINK,
    LED_BEHAVIOR_FAST_BLINK,
    LED_BEHAVIOR_SLOW_BLINK,
    LED_BEHAVIOR_CYCLE
} LedBehavior;

typedef enum {
    LED_COLOR_RED,
    LED_COLOR_GREEN,
    LED_COLOR_BLUE
} LedColor;

// Shared variables
extern volatile LedBehavior ledBehavior;
extern volatile LedColor ledColor;

// GPIO pins for the RGB LED
extern const int redLEDPin;
extern const int greenLEDPin;
extern const int blueLEDPin;

// Getter and setter functions for the intervals
#ifdef __cplusplus
extern "C" {
#endif

void controlLEDs(void *pvParameters);
void initializeLEDs();
void resetLEDs();

// Getters
int getBlinkInterval();
int getFastBlinkInterval();
int getSlowBlinkInterval();
int getCycleInterval();

// Setters
void setBlinkInterval(int interval);
void setFastBlinkInterval(int interval);
void setSlowBlinkInterval(int interval);
void setCycleInterval(int interval);

#ifdef __cplusplus
}
#endif

#endif // LED_CONTROL_H
