#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP
#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QString>

#include"playVorbis.hpp"

class MainWidget :public QWidget{
    Q_OBJECT
public:
    MainWidget(QWidget* parent = 0);

private slots:
    void playVorbis();
    void callFileChooser();

private:
    QLineEdit* filePathEdit;
    QLabel* filePathEditLabel;
    QPushButton* fileChooseButton;
    QPushButton* playButton;

    QString vorbisFilePath;

    playVorbis *player;
};
#endif
