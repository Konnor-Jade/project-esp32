

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

BlinkerNumber Number1("num-abc");

// 如果未绑定的组件被触发，则会执行其中内容
void dataRead(const String & data)
{
    // OLED
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
      Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }
    // 延迟半秒，清空上一次输入
    delay(500);
    display.clearDisplay();
    // 设置字体大小、字体颜色
    display.setTextSize(2);
    display.setTextColor(WHITE);
    // 设置输出起始点为（0，0）
    display.setCursor(0, 0);
    // 显示静态文本
    display.println(data);
    display.display(); 
    // 通信串口打印前端文本框输入的信息
    BLINKER_LOG("Blinker readString: ", data);
    BLINKER_LOG("显示屏输出：", data);
    counter++;
    Number1.print(counter);
}
