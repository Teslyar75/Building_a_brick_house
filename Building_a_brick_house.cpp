/*2) Добавить к коду на слайде 22 презентации по Паттернам проектирования (выслана в Тимс) 
возможность создавать кирпичные дома.*/
#include <iostream>
using namespace std;
class House abstract
{
};


class PanelHouse : public House
{
public:
	PanelHouse()
	{
		cout << "Panel house built\n";
	}
};


class WoodHouse : public House
{
public:
	WoodHouse()
	{
		cout << "Wooden house built\n";
	}
};



class Developer abstract
{
	
public:
	virtual House* Create() = 0;
};


class PanelDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new PanelHouse;
	}
};


class WoodDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new WoodHouse;
	}
};


House* Client(Developer* pDev)
{
	return pDev->Create();
}



class BrickHouse : public House
{
public:
	BrickHouse()
	{
		cout << "Brick house built\n";
	}
};

class BrickDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new BrickHouse;
	}
};


int main()
{
	Developer* pDev = new PanelDeveloper();
	House* pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new WoodDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new BrickDeveloper(); // новый создатель для кирпичных домов
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;
}