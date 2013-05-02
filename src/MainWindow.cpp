#include"MainWindow.hpp"

MainWindow::MainWindow(){
    wid = new MainWidget();

    setCentralWidget(wid);
    setWindowTitle("vorbis-music");
}
