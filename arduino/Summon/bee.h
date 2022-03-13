// 定义输出串口
#define PIN_BEE 2


// 新建组件对象
BlinkerButton Button_BEE("btn-bee");


// 按下按键即会执行该函数
void button_bee_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    BLINKER_LOG("蜂鸣器：on");
    
    digitalWrite(PIN_BEE, HIGH);
    BLINKER_LOG("蜂鸣器：2");
//    蜂鸣器启动两秒后关闭
    delay(1000);  
    BLINKER_LOG("蜂鸣器：1");
    delay(1000);
    digitalWrite(PIN_BEE, LOW);
    BLINKER_LOG("蜂鸣器：off");
}
