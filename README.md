# Introduction

The repo is to show how to migrate packages from ROS 1 to ROS 2.

# Build

* Get the code

```bash
mkdir -p ~/migration_example_ws/src
cd migration_example_ws/src
git clone https://github.com/Adlink-ROS/ROS_migration_example.git
```

* Run ROS 1 first

```bash
# 1st terminal
roscore
# 2nd terminal
source ~/migration_example_ws/devel/setup.bash
rosrun migration_example talker
```
