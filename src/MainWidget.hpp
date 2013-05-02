#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP
#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>

class MainWidget :public QWidget{
    Q_OBJECT
public:
    MainWidget(QWidget* parent = 0);

private:
    QLineEdit* filePathEdit;
    QLabel* filePathEditLabel;
    QPushButton* fileChooseButton;
    QPushButton* playButton;
};
#endif
