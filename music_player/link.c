#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include "link.h"
#include "player.h"
#include <time.h>

extern Node *head;
extern int num;
// 初始化双向循环链表
int InitLink()
{
	head = (Node *)malloc(sizeof(Node) * 1);
	if (NULL == head) {
		return FAILURE;
	}
	head->next = NULL;
	head->prior = NULL;
	num++;
	return SUCCESS;
}

// 插入链表节点
int InsertLink(Node *h, const char *name)
{
	if (NULL == h || NULL == name) {
		return FAILURE;
	}
	Node *new = (Node *)malloc(sizeof(Node) * 1);
	if (NULL == new) {
		return FAILURE;
	}
	new->next = NULL;
	new->prior = NULL;
	strcpy(new->music_name, name);
	Node  *ptr = head;
	if (ptr->next == NULL) { // 插入第一个节点
		ptr->next = new;
		new->prior = ptr;
		new->next = head;
		head->prior = new;
	}
	while (ptr->next != head) {
		ptr = ptr->next;
	}
	ptr->next = new;
	new->prior = ptr;
	new->next = head;
	head->prior = new;
	num++; // 歌曲数目加1
	return SUCCESS;
}

// 根据当前歌曲和播放模式，找到下一首歌,
// cur：当前歌曲 mode:播放模式 next：存放下一首歌名
void FindNextMusic(const char *cur, int mode, char *next)
{
	if (mode == CIRCLE) {               // 单曲循环
		strcpy(next, cur);
		return;
	} else if (mode == SEQUENCEMODE) {	// 顺序播放
		Node *p = head->next;
		while (strcmp(p->music_name, cur) != 0) {
			p = p->next;
		}
		if (p->next == head) { // 跳过头结点
			strcpy(next, head->next->music_name);
		} else {
			strcpy(next, p->next->music_name);
		}
		return;
	} else {							// 随机播放
		Node *p = head->next;
		srand(time(NULL));
		int num = rand() % 100;
		for (int i = 0; i < num; i++) {
			p = p->next;
		}
		if (p == head) {
            strcpy(next, head->next->music_name);
		} else {
			strcpy(next, p->music_name);
		}
		return;
	}
}

// 根据模式选择上一首
void PriorMusic(const char *cur, int mode, char *prior)
{
	if (mode == SEQUENCEMODE) {
		Node *p = head->next;
		// 找到当前歌曲
		while (strcmp(p->music_name, cur) != 0) {
			p = p->next;
		}
		if (p == head->next) {
			printf("prior music is %s\n", head->prior->music_name);
			strcpy(prior, head->prior->music_name);
		} else {
			strcpy(prior, p->prior->music_name);
		}
		return;
	} else if (mode == RANDOM) {
		Node *p = head->next;
		while (1) {
			srand(time(NULL));
			int num = rand() % 100; // 100 可根据实际歌曲数目进行更改
			for (int i = 0; i < num; i++) { 
				p = p->next;
			}
			if (p == head || !strcmp(p->music_name,cur)) {
				continue;
			} else {
				strcpy(prior, p->music_name);
				return;
			}
		}
	} else if (mode == CIRCLE) {
		strcpy(prior, cur);
		return;
	}
}

// 下一首
void NextMusic(const char *cur, int mode, char *next)
{
	if (mode == SEQUENCEMODE) {
		Node *p = head->next;
		while (strcmp(p->music_name, cur) != 0) {
			p = p->next;
		}
		if (p == head->prior) {
			printf("next music is %s\n", head->next->music_name);
			strcpy(next, head->next->music_name);
		} else {
			strcpy(next, p->next->music_name);
		}
		return;
	} else if (mode == RANDOM) {
		Node *p = head->next;
		while (1) {
			srand(time(NULL));
			int num = rand() % 100; // 100 可根据实际歌曲数目进行更改
			for (int i = 0; i < num; i++) {
				p = p->next;
			}
			if (p == head || !strcmp(p->music_name,cur)) {
				continue;
			} else {
				strcpy(next, p->music_name);
				return;
			}
		}
	} else if (mode == CIRCLE) {
		strcpy(next, cur);
	}
}
