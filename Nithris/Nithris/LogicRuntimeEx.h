//PG4400 - INNLEVERING 1 - TRYM NILSEN
//also an exception class i ended up not using
#ifndef LOGICRUNTIMEEX_H
#define LOGICRUNTIMEEX_H

#include <stdexcept>

class LogicRuntimeEx : public std::runtime_error {
public:
	LogicRuntimeEx(const char *message) : std::runtime_error(message) { }

};
#endif
