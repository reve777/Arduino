# Arduino
設定藍牙模組的名稱、密碼與連線速率
1.將 Arduino 的 USB 線拔掉。
2.拔掉 HC-05 VCC 和 Arduino 5V 相連的這條線
3:將 Arduino 的 USB 線插入電腦。
4:先按下HC-05板上的按鈕不放.然行將HC-05 VCC 和 Arduino 5V 相連
  約1秒左右放掉HC-05板上的按鈕,此時HC-05板上的燈約2秒鐘閃一次.
  就代表進入AT COMMAND模式了.
5:
  在「序列埠監控視窗」下方調整 NL & CR 以及 9600 baud
  在「序列埠監控視窗」上方輸入 AT 應該會得到 OK 的回應
* 藍芽 AT 常用指令：
* AT 指令是否暢通
* AT -> OK
* 查看版本
* AT+VERSION? -> +VERSION:4.0-20190815
* 查看藍牙名稱：
* AT+NAME? -> +NAME:HC-05
* 修改藍牙名稱：
* AT+NAME=輸入你想取的名字 -> OK
* AT+NAME? -> +NAME:上面所輸入的名字
* 查看配對密碼
* AT+PSWD? -> +PSWD:1234
* 修改配對密碼
* AT+PSWD=9999 -> OK
* AT+PSWD? -> +PSWD:9999          
* 查看 UART
* AT+UART? -> +UART:9600,0,0                 
* 若不是 9600 則必須修改 UART=9600,0,0 讓手機可以傳資料
* 修改指令如下：
* AT+UART=9600,0,0
* AT+UART? -> +UART:9600,0,0
* 查看藍芽硬體位置
* AT+ADDR? -> +ADDR:0022:01:0010F8

*AT+ROLE? 0 從端   1主端

https://swf.com.tw/?p=750

vysor  
https://xantorohara.github.io/led-matrix-editor/#0000000000000000|0000000001000000|0000000103010000|0000010307030100|000002060f060200|0000040c1f0c0400|000008183f180800|000010307e301000|00002060fc602000|000040c0f8c04000|000040c0f9c04000|00008081f3818000|00000103e7030100|00000103e7030100
