#define LED_BUILTIN 4
#define BLINKER_PRINT Serial
#include "wifi.h"
#include "bee.h"
#include "vibration.h"
#include "oled.h"
void setup() {
    // 初始化串口
    Serial.begin(115200);

    #if defined(BLINKER_PRINT)
        BLINKER_DEBUG.stream(BLINKER_PRINT);
    #endif
    // 初始化有LED的IO
    #if defined(LED_BUILTIN)
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    #endif
    
    // 初始化振动电机管脚
    #if defined(PIN_BEE)
        pinMode(PIN_BEE, OUTPUT); //设置pinBuzzer脚为输出状态
    #endif
    
    // 初始化蜂鸣器管脚
    #if defined(PIN_VIBRATION)
        pinMode(PIN_VIBRATION, OUTPUT); //设置pinBuzzer脚为输出状态
    #endif
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd); 
    Blinker.attachData(dataRead);
    Button_WIFI.attach(button_wifi_callback);
    Button_BEE.attach(button_bee_callback);
    Button_vibra.attach(button_vibra_callback);

    
}

void loop() {
    Blinker.run();
}
