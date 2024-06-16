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

// Brightness variables (0-255)
static int redLEDBrightness = 255;
static int greenLEDBrightness = 255;
static int blueLEDBrightness = 255;

// Getters for intervals
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

// Setters for intervals
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

// Getters for brightness
int getRedLEDBrightness() {
    return redLEDBrightness;
}

int getGreenLEDBrightness() {
    return greenLEDBrightness;
}

int getBlueLEDBrightness() {
    return blueLEDBrightness;
}

// Setters for brightness
void setRedLEDBrightness(int brightness) {
    redLEDBrightness = brightness;
    ledcWrite(redLEDPin, brightness);
}

void setGreenLEDBrightness(int brightness) {
    greenLEDBrightness = brightness;
    ledcWrite(greenLEDPin, brightness);
}

void setBlueLEDBrightness(int brightness) {
    blueLEDBrightness = brightness;
    ledcWrite(blueLEDPin, brightness);
}

void controlLEDs(void *pvParameters) {
    while (true) {
        switch (ledBehavior) {
            case LED_BEHAVIOR_OFF:
                ledcWrite(redLEDPin, 0);
                ledcWrite(greenLEDPin, 0);
                ledcWrite(blueLEDPin, 0);
                break;
            case LED_BEHAVIOR_ON:
                if (ledColor == LED_COLOR_RED) {
                    ledcWrite(redLEDPin, redLEDBrightness);
                    ledcWrite(greenLEDPin, 0);
                    ledcWrite(blueLEDPin, 0);
                } else if (ledColor == LED_COLOR_GREEN) {
                    ledcWrite(redLEDPin, 0);
                    ledcWrite(greenLEDPin, greenLEDBrightness);
                    ledcWrite(blueLEDPin, 0);
                } else if (ledColor == LED_COLOR_BLUE) {
                    ledcWrite(redLEDPin, 0);
                    ledcWrite(greenLEDPin, 0);
                    ledcWrite(blueLEDPin, blueLEDBrightness);
                }
                break;
            case LED_BEHAVIOR_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    ledcWrite(redLEDPin, redLEDBrightness);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(redLEDPin, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    ledcWrite(greenLEDPin, greenLEDBrightness);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(greenLEDPin, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    ledcWrite(blueLEDPin, blueLEDBrightness);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(blueLEDPin, 0);
                    vTaskDelay(blinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_FAST_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    ledcWrite(redLEDPin, redLEDBrightness);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(redLEDPin, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    ledcWrite(greenLEDPin, greenLEDBrightness);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(greenLEDPin, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    ledcWrite(blueLEDPin, blueLEDBrightness);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(blueLEDPin, 0);
                    vTaskDelay(fastBlinkInterval / portTICK_PERIOD_MS);
                }
                break;
            case LED_BEHAVIOR_SLOW_BLINK:
                if (ledColor == LED_COLOR_RED) {
                    ledcWrite(redLEDPin, redLEDBrightness);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(redLEDPin, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_GREEN) {
                    ledcWrite(greenLEDPin, greenLEDBrightness);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(greenLEDPin, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                } else if (ledColor == LED_COLOR_BLUE) {
                    ledcWrite(blueLEDPin, blueLEDBrightness);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                    ledcWrite(blueLEDPin, 0);
                    vTaskDelay(slowBlinkInterval / portTICK_PERIOD_MS);
                }
                break;                                
            case LED_BEHAVIOR_CYCLE:
                ledcWrite(redLEDPin, 0);
                ledcWrite(greenLEDPin, greenLEDBrightness);
                ledcWrite(blueLEDPin, 0);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                ledcWrite(redLEDPin, 0);
                ledcWrite(greenLEDPin, 0);
                ledcWrite(blueLEDPin, blueLEDBrightness);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                ledcWrite(redLEDPin, redLEDBrightness);
                ledcWrite(greenLEDPin, 0);
                ledcWrite(blueLEDPin, 0);
                vTaskDelay(cycleInterval / portTICK_PERIOD_MS);
                break;
        }
        
        // Add a short delay to ensure the task yields control and resets the watchdog
        vTaskDelay(30 / portTICK_PERIOD_MS);
    }
}

void initializeLEDs() {
    ledcAttach(redLEDPin, 5000, 8); // 5000 Hz, 8-bit resolution
    ledcAttach(greenLEDPin, 5000, 8); // 5000 Hz, 8-bit resolution
    ledcAttach(blueLEDPin, 5000, 8); // 5000 Hz, 8-bit resolution
}

void resetLEDs() {
    ledcWrite(redLEDPin, 0);
    ledcWrite(greenLEDPin, 0);
    ledcWrite(blueLEDPin, 0);
}
