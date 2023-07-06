#include "player.h"
#include "ui_player.h"

Player::Player(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    socket = s;
    this->setFixedSize(QSize(512,314));
    ui->seqButton->setChecked(true);
    connect(socket, &QTcpSocket::readyRead, this, &Player::server_reply_slot);
    // RadioButton信号与槽
    connect(ui->seqButton, &QRadioButton::clicked, this, &Player::on_seqButton_cliecked);
    connect(ui->randomButton, &QRadioButton::clicked, this, &Player::on_randomButton_cliecked);
    connect(ui->circleButton, &QRadioButton::clicked, this, &Player::on_circleButton_cliecked);

    // 启动定时器，1秒后发送获取所有音乐的请求
    timer.start(1000);

    connect(&timer, &QTimer::timeout, this, &Player::timeout_slot);
}

Player::~Player()
{
    delete ui;
}

int Player::vals = 50;

void Player::timeout_slot()
{
    // 向服务器发送获取所有音乐的请求
    QJsonObject obj;
    obj.insert("cmd", "app_music");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    timer.stop();
}

void Player::server_reply_slot()
{
    QByteArray ba = socket->readAll();
    QJsonObject obj = QJsonDocument::fromJson(ba).object();
    QString cmd = obj.value("cmd").toString();

    if (cmd == "app_reply") {
        QString result = obj.value("result").toString();
        if (result == "start_success") {
            ui->startButton->setIcon(QIcon(":/start.png"));
            play_flag = START_PALY;
        }
        else if (result == "suspend_success") {
            ui->startButton->setIcon(QIcon(":/suspend.png"));
            play_flag = SUSPEND_PLAY;
        }
        else if (result == "continue_success") {
            ui->startButton->setIcon(QIcon(":/start.png"));
            play_flag = START_PALY;
        }
        else if (result == "next_success") {
            play_flag = START_PALY;
        }
        else if (result == "prior_success") {
            play_flag = START_PALY;
        }
        else if (result == "off_line") {
            QMessageBox::warning(this, "Warm Prompt", "Device off_line");
        }
    } else if (cmd == "app_reply_status") { // 播放器状态的回复
        QString status = obj.value("status").toString();
        QString music = obj.value("music").toString();
        if (status == "start") {
            play_flag = START_PALY;
            ui->startButton->setIcon(QIcon(":/start.png"));
        }
        else if (status == "suspend") {
            play_flag = SUSPEND_PLAY;
            ui->startButton->setIcon(QIcon(":/suspend.png"));
        }
        else if (status == "stop") {
            play_flag = STOP_PLAY;
            ui->startButton->setIcon(QIcon(":/suspend.png"));
        }

        ui->curEdit->setText(music);
    }
    else if (cmd == "app_reply_music") {  // 所有音乐的回复
        QJsonArray arr = obj.value("music").toArray(); // 转换成json数组
        QString result;
        for (int i = 0; i < arr.count(); i++) {
            result.append(arr.at(i).toString());
            result.append('\n');
        }
        ui->musicEdit->setText(result);
    }
}


void Player::on_voiceSlider_valueChanged(int value)
{
    Q_UNUSED(value);
    int val = ui->voiceSlider->value();
    if (val < vals) {
        vals = val;
        QJsonObject obj;
        obj.insert("cmd", "app_voice_down");
        QByteArray ba = QJsonDocument(obj).toJson();
        socket->write(ba);
    } else if (val > vals) {
        vals = val;
        QJsonObject obj;
        obj.insert("cmd", "app_voice_up");
        QByteArray ba = QJsonDocument(obj).toJson();
        socket->write(ba);
    }
}

void Player::on_startButton_clicked()
{
    if (play_flag == SUSPEND_PLAY) {
        QJsonObject obj;
        obj.insert("cmd", "app_continue");
        QByteArray ba = QJsonDocument(obj).toJson();
        socket->write(ba);
    }
    else if (play_flag == START_PALY) {
        QJsonObject obj;
        obj.insert("cmd", "app_suspend");
        QByteArray ba = QJsonDocument(obj).toJson();
        socket->write(ba);
    }
    else if (play_flag == STOP_PLAY) {
        QJsonObject obj;
        obj.insert("cmd", "app_start");
        QByteArray ba = QJsonDocument(obj).toJson();
        socket->write(ba);
    }
}

void Player::on_priorButton_clicked()
{
    QJsonObject obj;
    obj.insert("cmd", "app_prior");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

void Player::on_nextButton_clicked()
{
    QJsonObject obj;
    obj.insert("cmd", "app_next");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

// 顺序播放
void Player::on_seqButton_cliecked()
{
    QJsonObject obj;
    obj.insert("cmd", "app_sequence");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

// 随机播放
void Player::on_randomButton_cliecked()
{
    QJsonObject obj;
    obj.insert("cmd", "app_random");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

// 单曲循环
void Player::on_circleButton_cliecked()
{
    QJsonObject obj;
    obj.insert("cmd", "app_circle");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
}

void Player::closeEvent(QCloseEvent *event)
{
    QJsonObject obj;
    obj.insert("cmd", "app_off_line");
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    socket->waitForBytesWritten();
    event->accept();
}

