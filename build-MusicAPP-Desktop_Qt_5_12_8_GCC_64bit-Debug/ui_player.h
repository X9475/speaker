/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *musicEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *curEdit;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QRadioButton *seqButton;
    QRadioButton *randomButton;
    QRadioButton *circleButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *priorButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSlider *voiceSlider;

    void setupUi(QWidget *Player)
    {
        if (Player->objectName().isEmpty())
            Player->setObjectName(QString::fromUtf8("Player"));
        Player->setWindowModality(Qt::NonModal);
        Player->resize(512, 314);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Player->sizePolicy().hasHeightForWidth());
        Player->setSizePolicy(sizePolicy);
        Player->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/player.png"), QSize(), QIcon::Normal, QIcon::Off);
        Player->setWindowIcon(icon);
        widget = new QWidget(Player);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(32, 22, 448, 267));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        musicEdit = new QTextEdit(widget);
        musicEdit->setObjectName(QString::fromUtf8("musicEdit"));

        gridLayout->addWidget(musicEdit, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        curEdit = new QLineEdit(widget);
        curEdit->setObjectName(QString::fromUtf8("curEdit"));

        horizontalLayout_2->addWidget(curEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(42, -1, -1, 25);
        seqButton = new QRadioButton(widget);
        seqButton->setObjectName(QString::fromUtf8("seqButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(seqButton->sizePolicy().hasHeightForWidth());
        seqButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        font.setPointSize(12);
        seqButton->setFont(font);

        verticalLayout->addWidget(seqButton);

        randomButton = new QRadioButton(widget);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));
        sizePolicy1.setHeightForWidth(randomButton->sizePolicy().hasHeightForWidth());
        randomButton->setSizePolicy(sizePolicy1);
        randomButton->setFont(font);

        verticalLayout->addWidget(randomButton);

        circleButton = new QRadioButton(widget);
        circleButton->setObjectName(QString::fromUtf8("circleButton"));
        sizePolicy1.setHeightForWidth(circleButton->sizePolicy().hasHeightForWidth());
        circleButton->setSizePolicy(sizePolicy1);
        circleButton->setFont(font);

        verticalLayout->addWidget(circleButton);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(27, -1, 7, -1);
        priorButton = new QPushButton(widget);
        priorButton->setObjectName(QString::fromUtf8("priorButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(priorButton->sizePolicy().hasHeightForWidth());
        priorButton->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/prior.png"), QSize(), QIcon::Normal, QIcon::Off);
        priorButton->setIcon(icon1);
        priorButton->setIconSize(QSize(27, 27));

        horizontalLayout->addWidget(priorButton);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/suspend.png"), QSize(), QIcon::Normal, QIcon::Off);
        startButton->setIcon(icon2);
        startButton->setIconSize(QSize(30, 30));
        startButton->setAutoDefault(false);

        horizontalLayout->addWidget(startButton);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton = new QPushButton(widget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        sizePolicy3.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy3);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon3);
        nextButton->setIconSize(QSize(27, 27));
        nextButton->setAutoDefault(false);
        nextButton->setFlat(false);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer_3 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/voice.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        voiceSlider = new QSlider(widget);
        voiceSlider->setObjectName(QString::fromUtf8("voiceSlider"));
        voiceSlider->setSingleStep(2);
        voiceSlider->setValue(50);
        voiceSlider->setOrientation(Qt::Horizontal);
        voiceSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(voiceSlider);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(Player);

        startButton->setDefault(false);
        nextButton->setDefault(false);


        QMetaObject::connectSlotsByName(Player);
    } // setupUi

    void retranslateUi(QWidget *Player)
    {
        Player->setWindowTitle(QString());
        label->setText(QApplication::translate("Player", "<html><head/><body><p align=\"center\">\346\211\200\346\234\211\346\255\214\346\233\262</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Player", "Now", nullptr));
        seqButton->setText(QApplication::translate("Player", "\351\241\272\345\272\217\346\222\255\346\224\276", nullptr));
        randomButton->setText(QApplication::translate("Player", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
        circleButton->setText(QApplication::translate("Player", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
        priorButton->setText(QString());
        nextButton->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Player: public Ui_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
