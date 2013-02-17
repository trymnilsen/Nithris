#ifndef GRAPHICSINITEX_H
#define GRAPHICSINITEX_H

#include <stdexcept>

class GraphicsInitEx : public std::runtime_error {
public:
	GraphicsInitEx(const char *message) : std::runtime_error(message) { }
	
};

#endif