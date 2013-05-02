#include<QHBoxLayout>
#include<QVBoxLayout>
#include"MainWidget.hpp"

MainWidget::MainWidget(QWidget* parent):
    QWidget(parent){
    filePathEdit = new QLineEdit();
    filePathEditLabel = new QLabel("Choose ogg vorbis file");
    fileChooseButton = new QPushButton("Choose");
    playButton = new QPushButton("Play");

	QVBoxLayout* mainLayout = new QVBoxLayout();
	QHBoxLayout* fileEditLine = new QHBoxLayout();

	fileEditLine->addWidget(filePathEdit);
	fileEditLine->addWidget(fileChooseButton);

	mainLayout->addWidget(filePathEditLabel);
	mainLayout->addLayout(fileEditLine);
	mainLayout->addWidget(playButton);

	setLayout(mainLayout);
}
