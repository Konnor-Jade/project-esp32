#define BLINKER_WIFI
#include <Blinker.h>

char auth[] = "25d8af57e61e";
char ssid[] = "KONNOR 3588";
char pswd[] = "v5091O^8";

// 新建组件对象
BlinkerButton Button_WIFI("btn-wifi");

int counter = 0;

// 按下按键即会执行该函数
void button_wifi_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
