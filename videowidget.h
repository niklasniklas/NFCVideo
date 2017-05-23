#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <qpushbutton.h>
#include <cvimagewidget.h>
#include <opencv2\opencv.hpp>
#include <qboxlayout.h>
#include <qmessagebox.h>

class VideoWidget : public QWidget
{
	Q_OBJECT

public:
	VideoWidget(QWidget *parent);
	~VideoWidget();

	void showImage(cv::Mat img);

private slots:
	void nextClicked(void);
	void prevClicked(void);
	void loadClicked(void);

private:
	CVImageWidget*	videoOutput;
};

#endif // VIDEOWIDGET_H
