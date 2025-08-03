# MAC-ros2_elementary_teaching
## Workflow

1. Clone the repository:
   ```bash
   git clone -b template https://github.com/DIT-ROBOTICS/MAC-ros2_elementary_teaching.git
   ```
2. build container: 
   ```bash
   cd /ros2_teaching/docker
   docker build .
   docker compose up
   ```
3. enter container
   ```bash
   source /opt/ros/humble/setup.bash
   echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
   source install/setup.bash
   echo "source install/setup.bash" >> ~/.bashrc
   colcon build
   ```
4. create branch from template
   ```bash
   git checkout -b your_branch
   ```
 後續寫作業時接在 your_branch 修改，要交作業時再 push 上來，your_branch 名稱用 github 帳號名 +_branch
 寫作業的方式是修改程式中的"TO DO"，使其符合作業需求
=======
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
