#include "videowidget.h"
#include <qaction.h>
#include <qmessagebox.h>
#include <SlowFastSlider.h>

VideoWidget::VideoWidget(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout* col = new QVBoxLayout();
	videoOutput = new CVImageWidget();
	col->addWidget(videoOutput);

	QHBoxLayout* row = new QHBoxLayout();
	QPushButton* loadBtn = new QPushButton("Load");
	QPushButton* nextBtn = new QPushButton("->");
	QPushButton* prevBtn = new QPushButton("<-");
	SlowFastSlider* slider = new SlowFastSlider(this);
	row->addWidget(prevBtn);
	row->addWidget(loadBtn);
	row->addWidget(nextBtn);
	row->addWidget(slider);
	row->addStretch(2);
	col->addLayout(row);

	this->setLayout(col);


	connect(nextBtn, &QPushButton::clicked, this, &VideoWidget::nextClicked);
	connect(loadBtn, &QPushButton::clicked, this, &VideoWidget::loadClicked);
	connect(prevBtn, &QPushButton::clicked, this, &VideoWidget::prevClicked);


	//connect(this, SIGNAL(updateView(cv::Mat)), &mainWnd, SLOT(updateView(cv::Mat)));
	//connect(this, SIGNAL(updateSlider(int)), &mainWnd, SLOT(updateSlider(int)));
	//connect(this, SIGNAL(updateButtons(bool)), &mainWnd, SLOT(updateButtons(bool)));
	//connect(this, SIGNAL(updateCurrentTime(std::string)), &mainWnd, SLOT(setCurrentTime(std::string)));
}

VideoWidget::~VideoWidget()
{

}

void VideoWidget::showImage(cv::Mat img)
{
	videoOutput->showImage(img);
}

void VideoWidget::prevClicked(void)
{
	QMessageBox msgBox;
	msgBox.setText("Prev");
	msgBox.exec();

	SlowFastSlider aa = new SlowFastSlider();
	aa.show();
	_sleep(2000);
}

void VideoWidget::loadClicked(void)
{
	QMessageBox msgBox;
	msgBox.setText("Load");
	msgBox.exec();

}

void VideoWidget::nextClicked(void)
{
	QMessageBox msgBox;
	msgBox.setText("Next");
	msgBox.exec();
	setStatusTip("AAAA");

}
