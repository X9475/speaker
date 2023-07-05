#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "player.h"
#include <json-c/json.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"
#include <errno.h>

extern int      g_buttonfd;	// 按键的fd
extern int      g_sockfd;   // 客户端的fd
extern fd_set   readfd;     
extern fd_set   tmpfd;
extern int      g_maxfd;

void *showinput(void *arg);

// 展示的界面
void show()
{
	printf("1、开始播放\n");
	printf("2、结束播放\n");
	printf("3、暂停播放\n");
	printf("4、继续播放\n");
	printf("5、上一首\n");
	printf("6、下一首\n");
	printf("7、增加音量(未)\n");
	printf("8、减小音量(未)\n");
	printf("a、顺序播放\n");
	printf("b、随机播放\n");
	printf("c、单曲循环\n");
}

// 解析json序列
void parse_message(const char *m, char *c)
{
	struct json_object *obj = json_tokener_parse(m);
	struct json_object *json;
	json_object_object_get_ex(obj, "cmd", &json);
	strcpy(c, json_object_get_string(json));
}

// 初始化select
void InitSelect()
{
	FD_ZERO(&readfd);               // 套接字集合readfd清空
	FD_ZERO(&tmpfd);                // 套接字集合tmpfd清空
	FD_SET(g_buttonfd, &readfd);    // 设置g_buttonfd位在集合readfd中
	FD_SET(STDIN_FILENO, &readfd); 	//
}

// 对接收的序列进行处理
void m_select()
{
    // 展示界面
	show();
	fd_set tmpfd;
	char message[1024] = {0};
	while (1)
	{   // select 返回时，内核将修改readfd来通知应用程序哪些文件描述符已经就绪
		tmpfd = readfd;
        // 给timeout传递为NULL，则select将一直阻塞，直到某个文件描述符就绪
		int ret = select(g_maxfd + 1, &tmpfd, NULL, NULL, NULL);
		if (-1 == ret && errno != EINTR) {
			perror("select");
		} // 如果在select等待期间，程序接收到信号，则select立即返回-1，并设置errno为EINTR 
        else if (-1 == ret && errno == EINTR) {
			continue;
		}
        
        // 设备有数据可读
		if (FD_ISSET(g_sockfd, &tmpfd)) {	// TCP 有数据可读
			memset(message, 0, sizeof(message));
			ret = recv(g_sockfd, message, sizeof(message), 0);
			if (-1 == ret) {
				perror("g_sockfd recv");
			}

			char cmd[64] = {0};
			// 解析服务端发过来的指令
			parse_message(message, cmd);
			if (!strcmp(cmd, "start")) {
				socket_start_play();			
			} 
            else if (!strcmp(cmd, "stop")) {
				socket_stop_play();
			}
            else if (!strcmp(cmd, "suspend")) {
				socket_suspend_play();
			}
            else if (!strcmp(cmd, "continue")) {
				socket_continue_play();
			} 
            else if (!strcmp(cmd, "prior")) {
				socket_prior_play();
			}
			else if (!strcmp(cmd, "next")) {
				socket_next_play();
			}
			else if (!strcmp(cmd, "voice_up")) {
				socket_voice_up_play();
			}
			else if (!strcmp(cmd, "voice_down")) {
				socket_voice_down_play();
			}
			else if (!strcmp(cmd, "sequence")) {
				socket_mode_play(SEQUENCEMODE);
			}
			else if (!strcmp(cmd, "random")) {
				socket_mode_play(RANDOM);
			}
			else if (!strcmp(cmd, "circle")) {
				socket_mode_play(CIRCLE);
			}
			else if (!strcmp(cmd, "get")) {
				socket_get_status();
			}
			else if (!strcmp(cmd, "music")) {
				socket_get_music();								
			}
		}
		else if (FD_ISSET(STDIN_FILENO, &tmpfd)) {  // 标准输入有命令时
			char id;
			scanf("%c",&id);
			switch (id) {
				case '1':
					start_play();
					break;
				case '2':
					stop_play();
					break;
				case '3':
					suspend_play();
					break;
				case '4':
					continue_play();
					break;
				case '5':
					prior_play();
					break;
				case '6':
					next_play();
					break;
				case '7':
					voice_up();
					break;
				case '8':
					voice_down();
					break;
				case 'a':
					printf("已更改为--顺序播放\n");
					set_mode(SEQUENCEMODE);
					break;
				case 'b':
					printf("已更改为--随机播放\n");
					set_mode(RANDOM);
					break;
				case 'c':
					printf("已更改--单曲播放\n");
					set_mode(CIRCLE);
					break;
			}
		}
	}
}
