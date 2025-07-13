# MAC-ros2_elementary_teaching
## Workflow

1. Clone the repository:
   ```bash
   git clone https://github.com/DIT-ROBOTICS/MAC-ros2_elementary_teaching.git
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
