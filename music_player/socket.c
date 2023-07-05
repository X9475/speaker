// 客户端socket接收服务器命令并作出响应
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "main.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "device.h"
#include "socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <json-c/json.h>
#include "player.h"
#include <sys/select.h>
#include "link.h"

extern Node *head;
extern int g_sockfd;
extern int iLeft;
extern int g_start_flag;
extern int g_suspend_flag;
extern fd_set readfd;
extern int g_maxfd;
extern void *g_addr;

// 1秒执行一次，向服务器发送保活信息
void send_server(int sig)
{
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("info"));
	json_object_object_add(json, "status", json_object_new_string("alive"));
	json_object_object_add(json, "deviceid", json_object_new_string("001"));
    // {"cmd": "info", "status": "alive", "deviceid": "001" }
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("send");
	}
    // 循环定时
	alarm(TIMEOUT);
}

// 线程处理函数
void *connect_cb(void *arg)
{
	int count = 5, ret;
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(SERVER_PORT);	// 8000 主机序转网络序
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // 尝试与服务器连接count次
	while (count--) {

		ret = connect(g_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
		if (ret == -1) {
			sleep(1);
			continue;
		}
		// 连接成功，点亮 4 个LED灯
		// led_on(0);
		// led_on(1);
		// led_on(2);
		// led_on(3);
        
        // 定时1s钟，向服务器发送 alive 字符串
		alarm(TIMEOUT);
		signal(SIGALRM, send_server);

		// 连接服务器成功，g_sockfd添加到集合readfd中
		FD_SET(g_sockfd, &readfd);
		if (g_maxfd < g_sockfd) {
			g_maxfd = g_sockfd;
		}

		break;
	}

	return NULL;
}

// 初始化客户端socket
int InitSocket()
{
	g_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == g_sockfd) {
		return FAILURE;
	}

	// 启动线程向服务器发起连接
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, connect_cb, NULL);
	if (ret != 0) {
		return FAILURE;
	}

	return SUCCESS;
}

// 客户端响应服务器开始播放
void socket_start_play()
{
	start_play();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("start_success"));
	// {"cmd": "reply", "result": "start_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("start_play send");
	}
}

// 客户端响应服务器停止播放
void socket_stop_play()
{
	stop_play();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("stop_success"));
	// {"cmd": "reply", "result": "stop_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("stop_play send");
	}
}

// 客户端响应服务器暂停播放
void socket_suspend_play()
{
	suspend_play();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("suspend_success"));
	// {"cmd": "reply", "result": "suspend_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("suspend_play send");
	}
}

// 客户端响应服务器继续播放
void socket_continue_play()
{
	continue_play();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("continue_success"));
	// {"cmd": "reply", "result": "continue_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("continue_play send");
	}
}

// 客户端响应服务器播放上一首
void socket_prior_play()
{
	prior_play();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("prior_success"));
	// {"cmd": "reply", "result": "prior_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("prior_play send");
	}
}

// 客户端响应服务器播放上下一首
void socket_next_play()
{
	next_play();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("next_success"));
	// {"cmd": "reply", "result": "next_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("next_play send");
	}
}

// 客户端响应服务器播放加音量
void socket_voice_up_play()
{
	voice_up();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("voiceup_success"));
	// {"cmd": "reply", "result": "voiceup_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("voice_up_play send");
	}
}

// 客户端响应服务器播放减音量
void socket_voice_down_play()
{
	voice_down();
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("voicedown_success"));
	// {"cmd": "reply", "result": "voicedown_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("voice_down_play send");
	}
}

// 客户端响应服务器播放模式
void socket_mode_play(int mode)
{
	set_mode(mode);
	// 向服务器反馈响应成功
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply"));
	json_object_object_add(json, "result", json_object_new_string("mode_success"));
	// {"cmd": "reply", "result": "mode_success"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("mode_play send");
	}
}

// 客户端响应服务器获取状态
void socket_get_status()
{
	//播放状态  当前歌曲名  音量
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply_status"));
	if (g_start_flag == 1 && g_suspend_flag == 0) {
		json_object_object_add(json, "status", json_object_new_string("start"));
		// {"cmd": "reply_status", "status": "start"}
	}
	else if (g_start_flag == 1 && g_suspend_flag == 1) {
		json_object_object_add(json, "status", json_object_new_string("suspend"));
		// {"cmd": "reply_status", "status": "suspend"}
	}
	else if (g_start_flag == 0) {
		json_object_object_add(json, "status", json_object_new_string("stop"));
		// {"cmd": "reply_status", "status": "stop"}
	}
	json_object_object_add(json, "voice", json_object_new_int(iLeft));
	// {"cmd": "reply_status", "status": "xxxx", "voice": 20}

	shm s;
	memset(&s, 0, sizeof(s));
	memcpy(&s, g_addr, sizeof(s));
	// 获取共享内存中的歌曲名字
	json_object_object_add(json, "music", json_object_new_string(s.cur_name));
	// {"cmd": "reply_status", "status": "xxxx", "voice": 20, "music": "xx.mp3"}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("get_status send");
	}
}

// 客户端响应服务器获取音乐
void socket_get_music()
{
	struct json_object *json = json_object_new_object();
	json_object_object_add(json, "cmd", json_object_new_string("reply_music"));
	// {"cmd": "reply_music"}
	struct json_object *array = json_object_new_array();
	Node *p = head->next;
	while (p != head) { // 一轮循环结束
		json_object_array_add(array, json_object_new_string(p->music_name));
		p = p->next;
	}
	json_object_object_add(json, "music", array);
	// {"cmd": "reply_status", "music": ["1.mp3", "2.mp3", "3.mp3", ...]}
	const char *buf = json_object_to_json_string(json);
	int ret = send(g_sockfd, buf, strlen(buf), 0);
	if (-1 == ret) {
		perror("get_music send");
	}
}
