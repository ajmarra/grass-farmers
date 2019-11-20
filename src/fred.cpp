#include "fred.h"
#include "item.h"
#include <iostream>
#include <list>

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 64, 64, 10, 200, 100) {

}

void Fred::useSelectedItem(void) {
	if (this->getSelectedItem() != nullptr) {
		switch (this->getSelectedItem()->getType()) {
		case ActorType::HEALTH:
		{
			std::cout << this->health;
			this->heal(5);
		}
		break;
		}
	}
}
