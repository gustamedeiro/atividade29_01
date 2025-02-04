#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 11

volatile int state = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_RED, state == 0 || state == 1);
    gpio_put(LED_GREEN, state == 1 || state == 2);
    gpio_put(LED_YELLOW, 0);
    state = (state + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(-3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Semáforo ta funcionando :)\n");
        sleep_ms(1000);
    }
}
