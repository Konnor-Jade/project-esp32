// 绑定输出信号到25号串口
#define PIN_VIBRATION 25


// 新建组件对象
BlinkerButton Button_vibra("btn-vibra");


// 按下按键即会执行该函数
void button_vibra_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    digitalWrite(PIN_VIBRATION, HIGH);
//    电机震动10秒后关闭
    BLINKER_LOG("震动电机：on");   
    BLINKER_LOG("震动电机：10");
    delay(1000);
    BLINKER_LOG("震动电机：9");
    delay(1000);
    BLINKER_LOG("震动电机：8");
    delay(1000);
    BLINKER_LOG("震动电机：7");
    delay(1000);
    BLINKER_LOG("震动电机：6");
    delay(1000);
    BLINKER_LOG("震动电机：5");
    delay(1000);
    BLINKER_LOG("震动电机：4");
    delay(1000);
    BLINKER_LOG("震动电机：3");
    delay(1000);
    BLINKER_LOG("震动电机：2");
    delay(1000);
    BLINKER_LOG("震动电机：1");
    delay(1000);
    // 关闭震动电机
    digitalWrite(PIN_VIBRATION, LOW);
    BLINKER_LOG("震动电机：off");
}
