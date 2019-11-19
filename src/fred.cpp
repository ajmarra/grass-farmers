#include "fred.h"
#include "item.h"
#include <iostream>
#include <list>

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 64, 64, 10, 200, 100) {

}

void Fred::useSelectedItem(void) {
	if (this->getSelectedItem() != nullptr) {
		std::cout << "Hello";
		switch (this->getSelectedItem()->getType()) {
		case ActorType::HEALTH:
		{
			this->heal(10);
		}
		break;
		}
	}
}
