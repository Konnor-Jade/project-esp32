#!/usr/bin/env python# -*- coding: utf-8 -*-from machine import Pin,I2Cimport ssd1306from time import sleepfrom Blinker.Blinker import Blinker, BlinkerButton, BlinkerNumber#from Blinker.BlinkerDebug import BLINKER_DEBUG,BLINKER_LOGfrom Blinker.BlinkerDebug import *# 设置 OLED 参数# ESP32 Pin assignment i2c = I2C(-1, scl=Pin(22), sda=Pin(21))oled_width = 128oled_height = 64oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)# 定义wifi、设备码等参数sauth = '2f267d15d465'ssid = 'KONNOR 3588'pswd = 'v5091O^8'# 开启调试BLINKER_DEBUG.debug()# 设置联网模式为wifi，连接网络Blinker.mode('BLINKER_WIFI')Blinker.begin(auth, ssid, pswd)# 定义组件button_wifi = BlinkerButton('btn-wifi')# 定义蜂鸣器组件button_bee = BlinkerButton('btn-bee')# 定义震动电机组件button_vibra = BlinkerButton('btn-vibra')pinValue = 0# 设置输出PinWifi = Pin(4, Pin.OUT)PinWifi.value(pinValue)PinBee = Pin(2, Pin.OUT)PinBee.value(0)PinVibra = Pin(25, Pin.OUT)PinVibra.value(0)# 定义蜂鸣器按钮回调函数def button_bee_callback(state):    ''' '''    BLINKER_LOG('get button state: ', state)    button_bee.print(state)    print("蜂鸣器触发")    PinBee.value(1)    sleep(2)    PinBee.value(0)    # 定义wifi按钮回调函数def button_wifi_callback(state):    ''' '''    BLINKER_LOG('get button state: ', state)    button_wifi.print(state)    print("wifi已经连接")    global pinValue        pinValue = 1 - pinValue    PinWifi.value(pinValue)# 定义蜂鸣器按钮回调函数def button_vibra_callback(state):    ''' '''    BLINKER_LOG('get button state: ', state)    button_vibra.print(state)    print("震动电机触发")    PinVibra.value(1)    sleep(10)    PinVibra.value(0)def data_callback(data):    BLINKER_LOG('Blinker readString: ', data)    print("OLED显示：",data)    oled.fill(0)    oled.show()    oled.text(data, 0, 0)    oled.show()button_wifi.attach(button_wifi_callback)button_bee.attach(button_bee_callback)button_vibra .attach(button_vibra_callback)Blinker.attachData(data_callback)if __name__ == '__main__':    while True:                Blinker.run()