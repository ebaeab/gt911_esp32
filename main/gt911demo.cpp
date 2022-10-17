#include <stdio.h>
#include <esp_log.h>
#include "driver/i2c.h"
#include "gt9xx.h"
#include "myi2c.h"
static const char *TAG = "DEMO";

extern "C"
{
void app_main();
}


void app_main(void) {
    i2c_master_init();
    GT9xx_Class *a1=new GT9xx_Class();
    a1->begin(0);


    uint16_t x=0;
    uint16_t y=0;
    uint8_t z=0;

    int bb=0;

    while (true){
        vTaskDelay(2);
        bb=a1->scanPoint();
        a1->getPoint(x,y,z);
        ESP_LOGE(TAG, "I2C   %d  %d  %d",x,y,bb);
    }


}
