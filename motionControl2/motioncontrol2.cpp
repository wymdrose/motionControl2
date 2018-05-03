#include "motioncontrol2.h"
#include "handControl.h"
#include "aspAction.h"

motionControl2::motionControl2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	createMenuBar();
}

motionControl2::~motionControl2()
{

}


void motionControl2::createMenuBar()
{
	//	manageAction->setShortcut(tr("Ctrl+M"));
	//	quitAction->setShortcut(tr("Ctrl+Q"));

	configureMenu = menuBar()->addMenu(tr("configure"));
	autoparaAction = new QAction(QStringLiteral("autoPara"), this);
	configureMenu->addAction(autoparaAction);

	//
	controlMenu = menuBar()->addMenu(tr("control"));
	handAction = new QAction(QStringLiteral("ÊÖ¶¯"), this);
	controlMenu->addAction(handAction);


	debugMenu = menuBar()->addMenu(tr("debug"));
	dmcAction = new QAction(QStringLiteral("DMC5000"), this);
	aspAction = new QAction(QStringLiteral("PCI7856"), this);

	debugMenu->addAction(dmcAction);
	controlMenu->addSeparator();
	debugMenu->addAction(aspAction);

  	connect(handAction, SIGNAL(triggered()), this, SLOT(on_handAction_clicked()));
	
	connect(aspAction, &QAction::triggered, [this](){
		class aspAction T;
		T.exec();
	});
}

void motionControl2::on_handAction_clicked()
{
	handControl T;
	T.exec();
}

