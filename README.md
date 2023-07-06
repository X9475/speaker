# speaker
基于select&amp;libevent的并发音箱服务系统

# 开发环境：
  Ubuntu16.04、Qt5.12、vscode、SourceInsight4.0
# 相关库安装：
  libevent: \
  sudo apt-get install libevent-dev \
  源码官网：http://libevent.org/ \
  源码包：libevent-2.1.11-stable.tar.gz \
  编译：-levent

  json-c: \
  sudo apt-get install libjson0-dev libjson0 \
  源码包：git clone https://github.com/json-c/json-c.git \
  相关库文件在：/usr/lib/x86_64-linux-gnu/  \
  相关头文件在：/usr/include/json-c/ 
  编译：-ljson-c

  jsoncpp：\
  sudo apt-get install libjsoncpp-dev  \
  引用头文件：#include "jsoncpp/json/json.h  \
  编译：-ljsoncpp

  madplay:  \
  sudo apt-get install madplay
# 项目介绍
   使用select作为客户端（后期可移植嵌入式imx6ull开发板）的网络控制，libevent（内部实现epoll）作为服务端框架
   对于前端UI和后端的信息交流采用JSON格式，其中音乐资源存放在挂载的U盘或其他磁盘里，以读文件目录的方式将音乐名称计入内存维护的
   双向循环链表中，后期使用madplay实现音乐资源的播放；通过三进程运行的方式处理业务，子进程用来等待回收孙进程播放的资源，不同进程之间通过共享内存实现进程通信；
   创建不同的孙进程来处理并发访问；经过服务器中心处理，使APP状态和实际播放状态同步，最后在客户端退出（Ctrl+C）时回收申请的内存，以防止内存泄漏
