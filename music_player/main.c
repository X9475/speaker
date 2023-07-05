#include <stdio.h>
#include "main.h"
#include "device.h"
#include <stdlib.h>
#include "socket.h"
#include "link.h"
#include "player.h"
#include <signal.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <string.h>
#include <sys/select.h>
#include "select.h"

int         g_buttonfd;
int         g_ledfd;
int         g_mixerfd;
int         g_sockfd;
Node 		*head;
extern int  shmid;
extern void *g_addr;
fd_set      readfd, tmpfd;
int         g_maxfd;
int			num = 0; // 记录歌曲的数目


// 信号SIGINT处理函数
void handler(int sig)
{
	shm s;
	memset(&s, 0, sizeof(s));
    // 读取共享内存数据并操作
	memcpy(&s, g_addr, sizeof(s));
	kill(s.child_pid, SIGKILL);
	kill(s.grand_pid, SIGKILL);
    
    // 释放存储区和ID
	shmdt(g_addr);
	shmctl(shmid, IPC_RMID, NULL);	// 删除共享内存区
    // 关闭socket
	close(g_sockfd);
	// 循环释放歌曲链表节点
	Node *n = head->next;
	for (int i = num; i >0; i--,n = n->next) {
		free(head);
		head = n;
	}
	printf("已释放\n");
	exit(0);
}

int main()
{
	// 打开设备文件
	// if (FAILURE == InitDriver()) {
	// 	printf("初始化设备文件失败\n");
	// 	exit(1);
	// }
    // 初始化select
	InitSelect();

    // 初始化客户端网络
	if (FAILURE == InitSocket()) {
		printf("初始化网络失败\n");
		// 初始化失败，点亮 2 个LED灯
		// led_on(0);
		// led_on(1);
	}

	// 初始化链表
	if (FAILURE == InitLink()) {
		printf("链表初始化失败\n");
		exit(1);
	}

	// 初始化共享内存
	if (FAILURE == InitShm()) {
		printf("共享内存初始化失败\n");
		exit(1);
	}
	// 读取并插入音乐 
	GetMusic();
	// 捕获ctrl c信号
	signal(SIGINT, handler);

    // 对接收的序列进行处理，在次循环处理接收的数据
	m_select();

	return 0;
}
