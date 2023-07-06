#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include "player.h"

namespace Ui {class Widget;}

#define IP    "192.168.221.129"
#define PORT  8000

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked(); // 绑定按钮被点击
    void server_reply_slot();     // 接收服务端响应槽函数

private:
    void bind_operation();        // 执行绑定操作

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};

#endif // WIDGET_H
