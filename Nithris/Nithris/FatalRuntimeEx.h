//PG4400 - INNLEVERING 1 - TRYM NILSEN
//exception class for fatal exceptions i ended up not using :P
#ifndef FATALRUNTIMEEX_H
#define FATALRUNTIMEEX_H

#include <stdexcept>

class FatalRuntimeEx : public std::runtime_error {
public:
	FatalRuntimeEx(const char *message) : std::runtime_error(message) { }

};
#endif