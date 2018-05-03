#ifndef ASPACTION_H
#define ASPACTION_H

#include <QDialog>
#include "ui_aspAction.h"

class aspAction : public QDialog
{
	Q_OBJECT

public:
	aspAction(QWidget *parent = 0);
	~aspAction();

private:
	Ui::aspAction ui;
};

#endif // ASPACTION_H
