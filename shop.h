#include <iostream>

#ifndef SHOP_H
#define SHOP_H

class Shop
{

public:
	void shopMain();
	void constructure();
	void transport();
	void construct(std::string name);
	void upgrade();
};

extern Shop sho;

#endif // !SHOP_H
