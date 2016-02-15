// Protector
#ifndef __CONTROL_H__
#define __CONTROL_H__

// Includes
#include <QDockWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class control : public QDockWidget
{
public:
	control();
	~control();
	void	create();

private:
	QVBoxLayout*	mainLayout;
};

#endif
