#include "LEDControl.h"

// Shared variables
volatile LedBehavior ledBehavior = LED_BEHAVIOR_OFF;
volatile LedColor ledColor = LED_COLOR_RED;

// GPIO pins for the RGB LED
const int redLEDPin = 13;
const int greenLEDPin = 12;
const int blueLEDPin = 14;

// Interval variables
static int blinkInterval = 250;  // Blinking interval in milliseconds
static int fastBlinkInterval = 100;  // Blinking interval in milliseconds
static int slowBlinkInterval = 1000;  // Blinking interval in milliseconds
static int cycleInterval = 1000; // Cycle thru 3 colors interval in milliseconds

// Getters
int getBlinkInterval() {
    return blinkInterval;
}

int getFastBlinkInterval() {
    return fastBlinkInterval;
}

int getSlowBlinkInterval() {
    return slowBlinkInterval;
}

int getCycleInterval() {
    return cycleInterval;
}

// Setters
void setBlinkInterval(int interval) {
    blinkInterval = interval;
}

void setFastBlinkInterval(int interval) {
    fastBlinkInterval = interval;
}

void setSlowBlinkInterval(int interval) {
    slowBlinkInterval = interval;
}

void setCycleInterval(int interval) {
    cycleInterval = interval;
}

void controlLEDs(void *pvParameters) {
    while (true) {
        switch (ledBehavior) {
            case LED_BEHAVIOR_OFF:
                digitalWrite(redLEDPin, LOW);
                digitalWrite(greenLEDPin, LOW);
                digitalWrite(blueLEDPin, LOW);
                break;
            case LED_BEHAVIOR_ON:
                if (ledColor == LED_COLOR_RED) {
                    digitalWrite(redLEDPin, HIGH);
                    digitalWrite(greenLEDPin, LOW);
                    digitalWrite(blueLEDPin, LOW);
                } else if (ledColor == LED_COLOR_GREEN) {
                    digitalWrite(redLEDPin, LOW);
                    digitalWrite(greenLEDPin, HIGH);
                    digitalWrite(blueLEDPin, LOW);
                } else if (ledColor == LED_COLOR_BLUE) {
                    digitalWrite(redLEDPin, LOW);
                    digitalWrite(greenLEDPin, LOW);
                    digitalWrite(blueLEDPin, HIGH);
                }
                break;
            case LED_BEHAVIOR_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    digitalWrite(redLEDPin, HIGH);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(redLEDPin, LOW);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    digitalWrite(greenLEDPin, HIGH);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(greenLEDPin, LOW);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    digitalWrite(blueLEDPin, HIGH);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(blueLEDPin, LOW);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_FAST_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    digitalWrite(redLEDPin, HIGH);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(redLEDPin, LOW);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    digitalWrite(greenLEDPin, HIGH);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(greenLEDPin, LOW);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    digitalWrite(blueLEDPin, HIGH);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(blueLEDPin, LOW);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_SLOW_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    digitalWrite(redLEDPin, HIGH);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(redLEDPin, LOW);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    digitalWrite(greenLEDPin, HIGH);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(greenLEDPin, LOW);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    digitalWrite(blueLEDPin, HIGH);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    digitalWrite(blueLEDPin, LOW);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                }
                break;                                
            case LED_BEHAVIOR_CYCLE:
                digitalWrite(redLEDPin, LOW);
                digitalWrite(greenLEDPin, HIGH);
                digitalWrite(blueLEDPin, LOW);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                digitalWrite(redLEDPin, LOW);
                digitalWrite(greenLEDPin, LOW);
                digitalWrite(blueLEDPin, HIGH);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                digitalWrite(redLEDPin, HIGH);
                digitalWrite(greenLEDPin, LOW);
                digitalWrite(blueLEDPin, LOW);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                break;
        }
        
        // Add a short delay to ensure the task yields control and resets the watchdog
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void initializeLEDs() {
    pinMode(greenLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
    resetLEDs();
}

void resetLEDs() {
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(blueLEDPin, LOW);
}
