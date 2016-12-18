#include "gui.h"
#include <QMessageBox>

pro::Gui::Gui(QWidget *parent /*= 0*/)
	: QWidget(parent)
	, ui(new Ui::Form)
{
	ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
}

void pro::Gui::onPushButtonClicked()
{
	if (!(QMessageBox::information(this, tr("close"), tr("Are you sure?"), tr("Yes"), tr("No"))))
	{
		this->close();
	}
}

