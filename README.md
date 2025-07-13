# MAC-ros2_elementary_teaching_example
## HW_1 topic練習
標頭檔皆放在 /include/homework/topic_hw.h 下

**publisher：**
- 檔案：publisher.cpp
- node名稱：Publisher
- 功能：每0.5秒傳從0開始的正整數並印出
  
**subscriber：**
- 檔案：subscription.cpp
- node名稱：Subscriber
- 功能：接收publisher傳來的topic並印出
  
**topic：**
- std_msgs/Int64 /topic
## HW_2 service練習
標頭檔皆放在 /include/homework/service_hw.h 下

**server：**
- 檔案：server.cpp
- node名稱：Server
- 功能：將收到的兩數字平方相加後開2次根並印出request與response
  
**client：**
- 檔案：client.cpp
- node名稱：Client
- 功能：由(0,0)開始每0.5秒發送request，每次成功發送request後 x+1 y+2並印出收到的response
  
**service：**
- request：geometry_msgs/Point point
- response：float32 dis

## HW_3 launch練習
一次開啟前兩次作業的四個node
- 檔名：launch_hw.launch
- 功能：將HW_1的topic名改成/number，將HW_2的client node名改成Chassis; server node名改成Tower
