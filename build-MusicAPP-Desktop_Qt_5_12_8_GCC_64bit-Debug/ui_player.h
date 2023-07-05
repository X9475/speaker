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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *musicEdit;
    QVBoxLayout *verticalLayout;
    QRadioButton *seqButton;
    QRadioButton *randomButton;
    QRadioButton *circleButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *priorButton;
    QPushButton *startButton;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *upButton;
    QPushButton *downButton;

    void setupUi(QWidget *Player)
    {
        if (Player->objectName().isEmpty())
            Player->setObjectName(QString::fromUtf8("Player"));
        Player->setWindowModality(Qt::NonModal);
        Player->resize(538, 323);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Player->sizePolicy().hasHeightForWidth());
        Player->setSizePolicy(sizePolicy);
        Player->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/player.png"), QSize(), QIcon::Normal, QIcon::Off);
        Player->setWindowIcon(icon);
        layoutWidget = new QWidget(Player);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 455, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        musicEdit = new QTextEdit(layoutWidget);
        musicEdit->setObjectName(QString::fromUtf8("musicEdit"));

        horizontalLayout_3->addWidget(musicEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        seqButton = new QRadioButton(layoutWidget);
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

        randomButton = new QRadioButton(layoutWidget);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));
        sizePolicy1.setHeightForWidth(randomButton->sizePolicy().hasHeightForWidth());
        randomButton->setSizePolicy(sizePolicy1);
        randomButton->setFont(font);

        verticalLayout->addWidget(randomButton);

        circleButton = new QRadioButton(layoutWidget);
        circleButton->setObjectName(QString::fromUtf8("circleButton"));
        sizePolicy1.setHeightForWidth(circleButton->sizePolicy().hasHeightForWidth());
        circleButton->setSizePolicy(sizePolicy1);
        circleButton->setFont(font);

        verticalLayout->addWidget(circleButton);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        priorButton = new QPushButton(layoutWidget);
        priorButton->setObjectName(QString::fromUtf8("priorButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(priorButton->sizePolicy().hasHeightForWidth());
        priorButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(priorButton);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(startButton);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        sizePolicy3.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        upButton = new QPushButton(layoutWidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        sizePolicy2.setHeightForWidth(upButton->sizePolicy().hasHeightForWidth());
        upButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(upButton);

        downButton = new QPushButton(layoutWidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(downButton->sizePolicy().hasHeightForWidth());
        downButton->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(downButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(Player);

        QMetaObject::connectSlotsByName(Player);
    } // setupUi

    void retranslateUi(QWidget *Player)
    {
        Player->setWindowTitle(QString());
        label->setText(QApplication::translate("Player", "<html><head/><body><p align=\"center\">\346\211\200\346\234\211\346\255\214\346\233\262</p></body></html>", nullptr));
        seqButton->setText(QApplication::translate("Player", "\351\241\272\345\272\217\346\222\255\346\224\276", nullptr));
        randomButton->setText(QApplication::translate("Player", "\351\232\217\346\234\272\346\222\255\346\224\276", nullptr));
        circleButton->setText(QApplication::translate("Player", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
        priorButton->setText(QApplication::translate("Player", "<<", nullptr));
        startButton->setText(QApplication::translate("Player", "|>", nullptr));
        nextButton->setText(QApplication::translate("Player", ">>", nullptr));
        upButton->setText(QApplication::translate("Player", "up", nullptr));
        downButton->setText(QApplication::translate("Player", "down", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Player: public Ui_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
