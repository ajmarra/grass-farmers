#ifndef HEALTH_ITEM_H
#define HEALTH_ITEM_H

#include "item.h"

class HealthItem : public Item {
private:
	int healQuantity;

public:
	HealthItem(double x, double y, double width, double height);

	int getHealQuantity(void) { return healQuantity; };

};

#endif //HEALT_ITEM_H