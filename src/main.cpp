#include<QApplication>
#include"MainWindow.hpp"

int main(int argc,char** argv){
	QApplication vorbis_music(argc,argv);
    MainWindow win;
    win.show();

	return vorbis_music.exec();
}
