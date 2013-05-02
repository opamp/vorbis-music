#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QHBoxLayout>
#include<QVBoxLayout>

#include"MainWidget.hpp"

MainWidget::MainWidget(QWidget* parent):
    QWidget(parent){
    filePathEdit = new QLineEdit();
    filePathEditLabel = new QLabel("Choose ogg vorbis file");
    fileChooseButton = new QPushButton("Choose");
    playButton = new QPushButton("Play");

    filePathEdit->setReadOnly(true);

    connect(fileChooseButton,SIGNAL(clicked()),this,SLOT(callFileChooser()));
    connect(playButton,SIGNAL(clicked()),this,SLOT(playOggVorbisFile()));

	QVBoxLayout* mainLayout = new QVBoxLayout();
	QHBoxLayout* fileEditLine = new QHBoxLayout();

	fileEditLine->addWidget(filePathEdit);
	fileEditLine->addWidget(fileChooseButton);

	mainLayout->addWidget(filePathEditLabel);
	mainLayout->addLayout(fileEditLine);
	mainLayout->addWidget(playButton);

	setLayout(mainLayout);
}

void MainWidget::callFileChooser(){
    this->vorbisFilePath = QFileDialog::getOpenFileName(this,tr("Open Vorbis File"),".",tr("Audio File (*.ogg)"));
    filePathEdit->setText(this->vorbisFilePath);
}

void MainWidget::playOggVorbisFile(){
    if(!QFile::exists(this->vorbisFilePath)){
        QMessageBox::critical(this,"ERROR","You have to choose ogg vorbis file.");
        return;
    }
    player = new playVorbis(this->vorbisFilePath);
    if(!player->play()){
        QMessageBox::critical(this,"ERROR","Fail to play ogg vorbis file.");
        return;
    }
}
