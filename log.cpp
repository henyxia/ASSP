#include "log.h"

log::log()
{
    out = NULL;
}

log::~log()
{
}

bool log::create(void)
{
	out = new output();
}
