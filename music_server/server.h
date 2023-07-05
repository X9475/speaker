#ifndef SERVER_H
#define SERVER_H

#include <event.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <event2/listener.h>
#include <jsoncpp/json/json.h>
#include <list>
#include <time.h>
#include "player.h"
#include "node.h"

#define IP    "192.168.221.129"
#define PORT  8000


class PlayerServer
{
public:
	PlayerServer(const char *ip = IP, int port = PORT);
	~PlayerServer();

private:     // 作为回调函数使用
	static void listener_cb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *addr, int socklen, void *arg);     
	static void read_cb(struct bufferevent *bev, void *ctx);
	static void event_cb(struct bufferevent *bev, short what, void *ctx);
private:
	struct event_base 	  	*base;     	//事件集合
	struct evconnlistener 	*listener;

	static Player *p;					// 播放器对象
	static std::list<Node>	*l;
};


#endif
