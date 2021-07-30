# Introduction

The repo is to show how to migrate packages from ROS 1 to ROS 2.

# Build

* Get the code

```bash
mkdir -p ~/migration_example_ws/src
cd migration_example_ws/src
git clone https://github.com/Adlink-ROS/ROS_migration_example.git
```

* Build and run ROS 1

```bash
# 1st terminal
roscore
# 2nd terminal
cd ~/migration_example_ws/
catkin_make
source ~/migration_example_ws/devel/setup.bash
rosrun migration_example talker
```

* Migrate to ROS 2: Remove the comment in 3 files
  - package.xml
  - CMakeLists.txt
  - talker.cpp

* Build and run ROS 2 

```bash
# Clean ROS 1 build result
rm -rf devel build
rm -rf src/CMakeLists.txt
# Build
colcon build
source install/local_setup.bash
ros2 run migration_example talker
```

