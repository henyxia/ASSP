// Protector
#ifndef __LOG_H__
#define __LOG_H__

// Includes
#include <QDockWidget>
#include <QTextEdit>

#include "output.h"

// Class
class log : public QDockWidget
{
    // Con/Des structor
    public:
    log();
    ~log();

    // Public
	void create(void);
	output* out;
};

#endif
