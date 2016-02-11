#include "log.h"

log::log()
{
    out = NULL;
}

log::~log()
{
}

void log::create(void)
{
	out = new output();
}
