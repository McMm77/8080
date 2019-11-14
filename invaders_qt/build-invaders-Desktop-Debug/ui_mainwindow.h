/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *play_screen;
    QPushButton *emulation_trigger;
    QPushButton *step_button;
    QPushButton *reset_button_0;
    QLineEdit *reg_b_edit;
    QLineEdit *reg_c_edit;
    QLineEdit *reg_d_edit;
    QLineEdit *reg_e_edit;
    QLineEdit *reg_h_edit;
    QLineEdit *reg_l_edit;
    QLineEdit *reg_a_edit;
    QLabel *reg_b_label;
    QLabel *reg_b_label_2;
    QLabel *reg_b_label_3;
    QLabel *reg_b_label_4;
    QLabel *reg_b_label_5;
    QLabel *reg_b_label_6;
    QLabel *reg_b_label_7;
    QLabel *ass_label_post;
    QPushButton *reset_button_1;
    QPushButton *reset_button_2;
    QPushButton *reset_button_3;
    QPushButton *reset_button_4;
    QPushButton *reset_button_5;
    QPushButton *reset_button_6;
    QPushButton *reset_button_8;
    QLineEdit *z_flag;
    QLineEdit *s_flag;
    QLineEdit *p_flag;
    QLineEdit *c_flag;
    QLineEdit *ac_flag;
    QLabel *reg_b_label_8;
    QLabel *reg_b_label_9;
    QLabel *reg_b_label_10;
    QLabel *reg_b_label_11;
    QLabel *reg_b_label_12;
    QLineEdit *pc;
    QLineEdit *stack;
    QLabel *ass_label_pre;
    QPushButton *step_x_button;
    QLineEdit *ass_step_count;
    QPushButton *step_to_button;
    QLineEdit *debug_pc;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(691, 593);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        play_screen = new QGraphicsView(centralWidget);
        play_screen->setObjectName(QStringLiteral("play_screen"));
        play_screen->setGeometry(QRect(30, 10, 256, 256));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(play_screen->sizePolicy().hasHeightForWidth());
        play_screen->setSizePolicy(sizePolicy1);
        play_screen->setMinimumSize(QSize(256, 256));
        play_screen->setMaximumSize(QSize(256, 256));
        emulation_trigger = new QPushButton(centralWidget);
        emulation_trigger->setObjectName(QStringLiteral("emulation_trigger"));
        emulation_trigger->setGeometry(QRect(310, 20, 89, 25));
        step_button = new QPushButton(centralWidget);
        step_button->setObjectName(QStringLiteral("step_button"));
        step_button->setGeometry(QRect(310, 60, 89, 25));
        reset_button_0 = new QPushButton(centralWidget);
        reset_button_0->setObjectName(QStringLiteral("reset_button_0"));
        reset_button_0->setGeometry(QRect(310, 180, 51, 25));
        reg_b_edit = new QLineEdit(centralWidget);
        reg_b_edit->setObjectName(QStringLiteral("reg_b_edit"));
        reg_b_edit->setGeometry(QRect(90, 280, 61, 25));
        reg_c_edit = new QLineEdit(centralWidget);
        reg_c_edit->setObjectName(QStringLiteral("reg_c_edit"));
        reg_c_edit->setGeometry(QRect(240, 280, 61, 25));
        reg_d_edit = new QLineEdit(centralWidget);
        reg_d_edit->setObjectName(QStringLiteral("reg_d_edit"));
        reg_d_edit->setGeometry(QRect(90, 320, 61, 25));
        reg_e_edit = new QLineEdit(centralWidget);
        reg_e_edit->setObjectName(QStringLiteral("reg_e_edit"));
        reg_e_edit->setGeometry(QRect(240, 320, 61, 25));
        reg_h_edit = new QLineEdit(centralWidget);
        reg_h_edit->setObjectName(QStringLiteral("reg_h_edit"));
        reg_h_edit->setGeometry(QRect(90, 360, 61, 25));
        reg_l_edit = new QLineEdit(centralWidget);
        reg_l_edit->setObjectName(QStringLiteral("reg_l_edit"));
        reg_l_edit->setGeometry(QRect(240, 360, 61, 25));
        reg_a_edit = new QLineEdit(centralWidget);
        reg_a_edit->setObjectName(QStringLiteral("reg_a_edit"));
        reg_a_edit->setGeometry(QRect(240, 400, 61, 25));
        reg_b_label = new QLabel(centralWidget);
        reg_b_label->setObjectName(QStringLiteral("reg_b_label"));
        reg_b_label->setGeometry(QRect(40, 280, 41, 17));
        reg_b_label_2 = new QLabel(centralWidget);
        reg_b_label_2->setObjectName(QStringLiteral("reg_b_label_2"));
        reg_b_label_2->setGeometry(QRect(190, 280, 41, 17));
        reg_b_label_3 = new QLabel(centralWidget);
        reg_b_label_3->setObjectName(QStringLiteral("reg_b_label_3"));
        reg_b_label_3->setGeometry(QRect(40, 320, 41, 17));
        reg_b_label_4 = new QLabel(centralWidget);
        reg_b_label_4->setObjectName(QStringLiteral("reg_b_label_4"));
        reg_b_label_4->setGeometry(QRect(190, 320, 41, 17));
        reg_b_label_5 = new QLabel(centralWidget);
        reg_b_label_5->setObjectName(QStringLiteral("reg_b_label_5"));
        reg_b_label_5->setGeometry(QRect(40, 360, 41, 17));
        reg_b_label_6 = new QLabel(centralWidget);
        reg_b_label_6->setObjectName(QStringLiteral("reg_b_label_6"));
        reg_b_label_6->setGeometry(QRect(190, 360, 41, 17));
        reg_b_label_7 = new QLabel(centralWidget);
        reg_b_label_7->setObjectName(QStringLiteral("reg_b_label_7"));
        reg_b_label_7->setGeometry(QRect(190, 400, 41, 17));
        ass_label_post = new QLabel(centralWidget);
        ass_label_post->setObjectName(QStringLiteral("ass_label_post"));
        ass_label_post->setGeometry(QRect(360, 480, 271, 31));
        reset_button_1 = new QPushButton(centralWidget);
        reset_button_1->setObjectName(QStringLiteral("reset_button_1"));
        reset_button_1->setGeometry(QRect(370, 180, 51, 25));
        reset_button_2 = new QPushButton(centralWidget);
        reset_button_2->setObjectName(QStringLiteral("reset_button_2"));
        reset_button_2->setGeometry(QRect(430, 180, 51, 25));
        reset_button_3 = new QPushButton(centralWidget);
        reset_button_3->setObjectName(QStringLiteral("reset_button_3"));
        reset_button_3->setGeometry(QRect(490, 180, 51, 25));
        reset_button_4 = new QPushButton(centralWidget);
        reset_button_4->setObjectName(QStringLiteral("reset_button_4"));
        reset_button_4->setGeometry(QRect(310, 220, 51, 25));
        reset_button_5 = new QPushButton(centralWidget);
        reset_button_5->setObjectName(QStringLiteral("reset_button_5"));
        reset_button_5->setGeometry(QRect(370, 220, 51, 25));
        reset_button_6 = new QPushButton(centralWidget);
        reset_button_6->setObjectName(QStringLiteral("reset_button_6"));
        reset_button_6->setGeometry(QRect(430, 220, 51, 25));
        reset_button_8 = new QPushButton(centralWidget);
        reset_button_8->setObjectName(QStringLiteral("reset_button_8"));
        reset_button_8->setGeometry(QRect(490, 220, 51, 25));
        z_flag = new QLineEdit(centralWidget);
        z_flag->setObjectName(QStringLiteral("z_flag"));
        z_flag->setGeometry(QRect(360, 280, 21, 25));
        s_flag = new QLineEdit(centralWidget);
        s_flag->setObjectName(QStringLiteral("s_flag"));
        s_flag->setGeometry(QRect(360, 310, 21, 25));
        p_flag = new QLineEdit(centralWidget);
        p_flag->setObjectName(QStringLiteral("p_flag"));
        p_flag->setGeometry(QRect(360, 340, 21, 25));
        c_flag = new QLineEdit(centralWidget);
        c_flag->setObjectName(QStringLiteral("c_flag"));
        c_flag->setGeometry(QRect(360, 370, 21, 25));
        ac_flag = new QLineEdit(centralWidget);
        ac_flag->setObjectName(QStringLiteral("ac_flag"));
        ac_flag->setGeometry(QRect(360, 400, 21, 25));
        reg_b_label_8 = new QLabel(centralWidget);
        reg_b_label_8->setObjectName(QStringLiteral("reg_b_label_8"));
        reg_b_label_8->setGeometry(QRect(340, 280, 16, 17));
        reg_b_label_9 = new QLabel(centralWidget);
        reg_b_label_9->setObjectName(QStringLiteral("reg_b_label_9"));
        reg_b_label_9->setGeometry(QRect(340, 310, 16, 17));
        reg_b_label_10 = new QLabel(centralWidget);
        reg_b_label_10->setObjectName(QStringLiteral("reg_b_label_10"));
        reg_b_label_10->setGeometry(QRect(340, 340, 16, 17));
        reg_b_label_11 = new QLabel(centralWidget);
        reg_b_label_11->setObjectName(QStringLiteral("reg_b_label_11"));
        reg_b_label_11->setGeometry(QRect(340, 370, 16, 17));
        reg_b_label_12 = new QLabel(centralWidget);
        reg_b_label_12->setObjectName(QStringLiteral("reg_b_label_12"));
        reg_b_label_12->setGeometry(QRect(340, 400, 16, 17));
        pc = new QLineEdit(centralWidget);
        pc->setObjectName(QStringLiteral("pc"));
        pc->setGeometry(QRect(80, 440, 121, 25));
        stack = new QLineEdit(centralWidget);
        stack->setObjectName(QStringLiteral("stack"));
        stack->setGeometry(QRect(240, 440, 121, 25));
        ass_label_pre = new QLabel(centralWidget);
        ass_label_pre->setObjectName(QStringLiteral("ass_label_pre"));
        ass_label_pre->setGeometry(QRect(360, 430, 301, 31));
        step_x_button = new QPushButton(centralWidget);
        step_x_button->setObjectName(QStringLiteral("step_x_button"));
        step_x_button->setGeometry(QRect(450, 60, 89, 25));
        ass_step_count = new QLineEdit(centralWidget);
        ass_step_count->setObjectName(QStringLiteral("ass_step_count"));
        ass_step_count->setGeometry(QRect(550, 60, 101, 25));
        step_to_button = new QPushButton(centralWidget);
        step_to_button->setObjectName(QStringLiteral("step_to_button"));
        step_to_button->setGeometry(QRect(450, 110, 89, 25));
        debug_pc = new QLineEdit(centralWidget);
        debug_pc->setObjectName(QStringLiteral("debug_pc"));
        debug_pc->setGeometry(QRect(550, 110, 101, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 691, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        emulation_trigger->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
        step_button->setText(QApplication::translate("MainWindow", "Next Step", Q_NULLPTR));
        reset_button_0->setText(QApplication::translate("MainWindow", "rst 0", Q_NULLPTR));
        reg_b_label->setText(QApplication::translate("MainWindow", "reg b", Q_NULLPTR));
        reg_b_label_2->setText(QApplication::translate("MainWindow", "reg c", Q_NULLPTR));
        reg_b_label_3->setText(QApplication::translate("MainWindow", "reg d", Q_NULLPTR));
        reg_b_label_4->setText(QApplication::translate("MainWindow", "reg e", Q_NULLPTR));
        reg_b_label_5->setText(QApplication::translate("MainWindow", "reg h", Q_NULLPTR));
        reg_b_label_6->setText(QApplication::translate("MainWindow", "reg l", Q_NULLPTR));
        reg_b_label_7->setText(QApplication::translate("MainWindow", "reg a", Q_NULLPTR));
        ass_label_post->setText(QString());
        reset_button_1->setText(QApplication::translate("MainWindow", "rst 1", Q_NULLPTR));
        reset_button_2->setText(QApplication::translate("MainWindow", "rst 2", Q_NULLPTR));
        reset_button_3->setText(QApplication::translate("MainWindow", "rst 3", Q_NULLPTR));
        reset_button_4->setText(QApplication::translate("MainWindow", "rst 4", Q_NULLPTR));
        reset_button_5->setText(QApplication::translate("MainWindow", "rst 5", Q_NULLPTR));
        reset_button_6->setText(QApplication::translate("MainWindow", "rst 6", Q_NULLPTR));
        reset_button_8->setText(QApplication::translate("MainWindow", "rst 7", Q_NULLPTR));
        reg_b_label_8->setText(QApplication::translate("MainWindow", "z", Q_NULLPTR));
        reg_b_label_9->setText(QApplication::translate("MainWindow", "s", Q_NULLPTR));
        reg_b_label_10->setText(QApplication::translate("MainWindow", "p", Q_NULLPTR));
        reg_b_label_11->setText(QApplication::translate("MainWindow", "c", Q_NULLPTR));
        reg_b_label_12->setText(QApplication::translate("MainWindow", "ac", Q_NULLPTR));
        ass_label_pre->setText(QString());
        step_x_button->setText(QApplication::translate("MainWindow", "X Steps", Q_NULLPTR));
        step_to_button->setText(QApplication::translate("MainWindow", "X Steps", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
