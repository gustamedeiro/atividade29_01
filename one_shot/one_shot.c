#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_BLUE 12
#define LED_RED 13
#define LED_GREEN 11
#define BUTTON 5

volatile bool is_running = false;

int64_t turn_off_led_red(alarm_id_t id, void *user_data) {
    gpio_put(LED_RED, 0);
    return 0;
}

int64_t turn_off_led_blue(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE, 0);
    is_running = false;
    return 0;
}

int64_t turn_off_led_green(alarm_id_t id, void *user_data) {
    gpio_put(LED_GREEN, 0);
    add_alarm_in_ms(3000, turn_off_led_red, NULL, false);
    add_alarm_in_ms(6000, turn_off_led_blue, NULL, false);
    return 0;
}

void button_callback(uint gpio, uint32_t events) {
    static uint64_t last_press_time = 0;
    uint64_t current_time = time_us_64();
    if (current_time - last_press_time < 300000) return;
    last_press_time = current_time;

    if (!is_running) {
        is_running = true;
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        add_alarm_in_ms(3000, turn_off_led_green, NULL, false);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(BUTTON);

    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        tight_loop_contents();
    }
}
