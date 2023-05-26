/*
接线说明:无

程序说明:使用MQTT的用户名密码功能,但是好像有问题,
        1:订阅端:不使用用户名密码
          发布端:不使用用户名密码
          可以正常接收消息
        2:订阅端:不使用用户名密码
          发布端:使用用户名密码
          订阅端只能接收到一条保留消息
        3:订阅端:使用用户名密码
          发布端:不使用用户名密码
          订阅端只能接收一条保留消息
        4:订阅端:使用用户名密码
          发布端:使用用户名密码
          无任何消息


注意事项:

函数示例:无

作者:灵首

时间:2023_5_26

*/
#include <Arduino.h>
#include <Ticker.h>

#include "mqttPubAndSub.h"
#include "wifiSet.h"

Ticker ticker;
static int Count;

//函数的声明

void timeCount(void);

void setup() {
  //串口设置
  Serial.begin(9600);
  Serial.print("serial is OK!!!\n");

  //wifi设置及连接
  wifi_multi_init();
  wifi_multi_con();

  //初始化MQTT服务
  MQTTInit();

  //定时设置
  ticker.attach(1,timeCount);
}



void loop() {
  mqttStateTest();
  if(Count == 3){
    pubMQTTmsg("lingsou-");
    Count = 0;
  }
}



/**
* @brief 这是一个用来辅助实现延时功能的函数
*
* @return 无
*/
void timeCount(void){
  Count++;
}

