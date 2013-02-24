//PG4400 - INNLEVERING 1 - TRYM NILSEN
//excpetion class for initialization for graphics
#ifndef GRAPHICSINITEX_H
#define GRAPHICSINITEX_H

#include <stdexcept>

class GraphicsInitEx : public std::runtime_error {
public:
	GraphicsInitEx(const char *message) : std::runtime_error(message) { }
	
};

#endif