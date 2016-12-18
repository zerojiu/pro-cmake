#ifndef __GUI_H_GUI_H__
#define __GUI_H_GUI_H__

#include <QtWidgets/QtWidgets>
#include "ui_pro.h"

namespace pro {
	class Gui : public QWidget {
		Q_OBJECT
	public:
		Gui(QWidget *parent = 0);
		~Gui() = default;

	public slots:
		void onPushButtonClicked();

	private:
		Ui::Form *ui;
	};
}

#endif // !__GUI_H_GUI_H__
