#include "handControl.h"
#include "motionLib.h"



handControl::handControl(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.comboBoxCardType->addItem("DMC5800");
	ui.comboBoxCardType->addItem("PCI7856");

	ui.comboBoxCardNo->addItem("0");
	ui.comboBoxCardNo->addItem("1");

	ui.comboBoxAxisNo->addItem("X");
	ui.comboBoxAxisNo->addItem("Y");
	ui.comboBoxAxisNo->addItem("Z");

	connect(ui.comboBoxCardType, &QComboBox::currentTextChanged, [this]()
	{
		if (0 == ui.comboBoxCardType->currentIndex())
		{
			mCardType = _MOTIONCLASS::MOTION_CARD_TYPE::DMC5000;
		}
		else if (1 == ui.comboBoxCardType->currentIndex())
		{
			mCardType = _MOTIONCLASS::MOTION_CARD_TYPE::PCI7856;
		}
		
	});

	connect(ui.pushButtonInit, &QPushButton::clicked, [this]()
	{
		if (_MOTIONCLASS::MOTION_CARD_TYPE::DMC5000 == mCardType)
		{
			mpMOTIONLib = &mDMC5000Lib;
		}
		else if (_MOTIONCLASS::MOTION_CARD_TYPE::PCI7856 == mCardType)
		{
			mpMOTIONLib = mpPCI7856Lib;
		}

		if (false == mpMOTIONLib->initial())
		{
			QMessageBox::warning(this, "", "Failed.");

			return;
		}
		
//		mpMOTIONLib->
			
//		getInitialPara();

		QMessageBox::information(this, "", "ok.");
	});

	connect(ui.pushButtonHome, &QPushButton::clicked, [this]()
	{
		mDMC5000Lib.setHomePara(0, 0, 500, 10000, 0.1, 0.1, 1, 0, 0);
	//	mpPCI7856Lib->
	
		mpMOTIONLib->home();

		_MOTIONCLASS::PCI7856Lib::home(0);

		mDMC5000Lib.setMovePara(0, 0, 500, 1000, 500, 0.1, 0.1, 0, 1, false, 5000);
		mpMOTIONLib->move();
		QMessageBox::information(this, "", "ok.");
	});

	connect(ui.pushButtonStop, &QPushButton::clicked, [this]()
	{
		mpMOTIONLib->emgStop();           //½ô¼±Í£Ö¹
	});


	
}

handControl::~handControl()
{

}

 