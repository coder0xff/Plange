#ifndef SCOPE_H
#define SCOPE_H

#include <vector>

class Scope
{
public:
	Scope();
	~Scope();
private:
	Scope * parent;
	std::vector<Scope *> children;
	
};

#endif SCOPE_H