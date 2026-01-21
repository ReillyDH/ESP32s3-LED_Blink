#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

/**
 * @brief LED structure to hold pin and state information
 */
typedef struct{
    uint8_t gpio_num;   // GPIO Pin number
    uint8_t state;      // LED Logical State: false = Off, true = On
}LED;

/**
 * @brief Initialize the LED GPIO
 * @param curr_led Pointer to LED struct
 */
void init_led(LED *curr_led){
    // resets the led
    gpio_reset_pin(curr_led->gpio_num);
    // sets led as an output
    gpio_set_direction(curr_led->gpio_num, GPIO_MODE_OUTPUT);

}

/**
 * @brief Toggle the LED state
 * @param curr_led Pointer to LED struct
 */
void flip_led(LED *curr_led){
    // Turns led on or off based on its state
    gpio_set_level(curr_led->gpio_num, !curr_led->state);
    // Flips the State of the led
    curr_led->state = !curr_led->state;
}


void app_main(void){
    ESP_LOGI("APP", "Main Start");

    // Initialises the Builtin Led 
    LED builtin_led;
    builtin_led.gpio_num = GPIO_NUM_2;
    builtin_led.state = false;
    init_led(&builtin_led);

    ESP_LOGI("APP", "LED Blink Starting");
    while(1){
        ESP_LOGI("APP", "LED State: %d", builtin_led.state);

        flip_led(&builtin_led);

        vTaskDelay(pdMS_TO_TICKS(1000));    // 1 Second Delay
    }

}



