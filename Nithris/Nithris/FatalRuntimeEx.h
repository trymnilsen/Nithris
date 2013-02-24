#ifndef FATALRUNTIMEEX_H
#define FATALRUNTIMEEX_H

#include <stdexcept>

class FatalRuntimeEx : public std::runtime_error {
public:
	FatalRuntimeEx(const char *message) : std::runtime_error(message) { }

};
#endif