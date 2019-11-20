#ifndef HEALTH_ITEM_H
#define HEALTH_ITEM_H

#include "item.h"
#include "character.h"

class HealthItem : public Item {
private:
	int healQuantity = 5;

public:
	HealthItem(double x, double y, double width, double height);

	void use(int x, int y) override;

	int getHealQuantity(void) { return healQuantity; };

};

#endif //HEALT_ITEM_H