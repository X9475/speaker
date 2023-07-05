#ifndef LINK_H
#define LINK_H

// 链表节点
typedef struct Node {
	char music_name[64];    // 音乐名称
	struct Node *next;      // 指向下一个
	struct Node *prior;     // 指向上一个
} Node;

// 初始化链表
int InitLink();

// 找到下一首
void FindNextMusic(const char *cur, int mode, char *next);

// 插入一首
int InsertLink(Node *h, const char *name);

// 上一首
void PriorMusic(const char *cur, int mode, char *prior);

// 下一首
void NextMusic(const char *cur, int mode, char *next);

#endif
