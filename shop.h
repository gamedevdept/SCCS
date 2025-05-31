#include <iostream>

#ifndef SHOP_H
#define SHOP_H

class Shop
{

public:
	void shopMain();
	void constructure();
	void transport();
	int construct(std::string name);
	void upgrade();
	void mapUp();
};

extern Shop sho;

#endif // !SHOP_H
