#ifndef __SELECT_
#define __SELECT_

// 展示的界面
void send_server(int sig);

// 解析json序列
void parse_message(const char *m, char *c);

// 初始化select
void InitSelect();

// 对接收的序列进行处理
void m_select();

#endif