#ifndef MOTIONCONTROL2_H
#define MOTIONCONTROL2_H

#include <QtWidgets/QMainWindow>
#include "ui_motioncontrol2.h"



class motionControl2 : public QMainWindow
{
	Q_OBJECT

public:
	motionControl2(QWidget *parent = 0);
	~motionControl2();


private slots:
	void on_handAction_clicked();

public:
	QMenu *configureMenu;
	QAction *autoparaAction;

	QMenu *controlMenu;
	QAction *handAction;
	
	QMenu *debugMenu;
	QAction *dmcAction;
	QAction *aspAction;

private:
	void createMenuBar();

private:
	Ui::motionControl2Class ui;
};

#endif // MOTIONCONTROL2_H
