#ifndef SOCKET_H
#define SOCKET_H

// #define SERVER_IP     "47.101.128.140" // 设置阿里云服务端
#define SERVER_PORT  8000
#define SERVER_IP    "192.168.221.129"
#define TIMEOUT       1

// 初始化客户端socket
int InitSocket();

// 客户端响应服务器开始播放
void socket_start_play();

// 客户端响应服务器停止播放
void socket_stop_play();

// 客户端响应服务器暂停播放
void socket_suspend_play();

// 客户端响应服务器继续播放
void socket_continue_play();

// 客户端响应服务器播放上一首
void socket_prior_play();

// 客户端响应服务器播放上下一首
void socket_next_play();

// 客户端响应服务器播放加音量
void socket_voice_up_play();

// 客户端响应服务器播放减音量
void socket_voice_down_play();

// 客户端响应服务器播放模式
void socket_mode_play(int);

// 客户端响应服务器获取状态
void socket_get_status();

// 客户端响应服务器获取音乐
void socket_get_music();

#endif
