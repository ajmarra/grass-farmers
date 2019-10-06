#ifndef ACTOR_H
#define ACTOR_H

class Actor {
	protected:
		double x, y, x_speed, y_speed, width, height;

	public:
		Actor(double x, double y, double width, double height);
		
		virtual void run(void);
		
		virtual void reset(void) = 0;
		
		double get_x(void);
		
		double get_y(void);
		
		double get_x_speed(void);
		
		double get_y_speed(void);
};

#endif
