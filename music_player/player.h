#ifndef PLAYER_H
#define PLAYER_H

#include <unistd.h>

//#define MUSICPATH   "/root/music_list/"
// #define MUSICPATH  "/media/tarena/76E8-CACF/Music"	// 音乐存储位置
#define MUSICPATH  "/home/tarena/Music/"	// 音乐存储位置
#define SHMKEY     1234		// kEY
#define SHMSIZE    4096		// 共享内存存储区大小

#define SEQUENCEMODE    1	// 顺序播放模式
#define RANDOM          2   // 随机播放模式
#define CIRCLE          3   // 单曲播放模式

//共享内存数据
typedef struct shm
{
	int     play_mode;      // 播放模式
	char    cur_name[64];   // 当前音乐名字
	pid_t   ppid;           // 父进程ID
	pid_t   child_pid;      // 子进程ID
	pid_t   grand_pid;      // 孙进程ID
} shm;

// 初始化共享内存
int InitShm();
// 读取并插入音乐
void GetMusic();
// 开始播放
void start_play();
// 停止播放
void stop_play();
// 暂停播放
void suspend_play();
// 继续播放
void continue_play();
// 播放上一首
void prior_play();
// 播放下一首
void next_play();
// 加音量
void voice_up();
// 减音量
void voice_down();
// 设置播放模式
void set_mode(int mode);


#endif
