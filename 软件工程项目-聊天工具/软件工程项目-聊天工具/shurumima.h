#pragma once
#include <QWidget>
#include "ui_shurumima.h"

class shurumima : public QWidget {
	Q_OBJECT

public:
	shurumima(QWidget * parent = Q_NULLPTR);
	~shurumima();

private:
	Ui::shurumima ui;
};
