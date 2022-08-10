#include "time.h"
#include "time.h"

int frame = 0;

void updateTime() {
	++frame;

	if (frame == 60)
		frame = 0;
}

int currentFrame() {
	return frame;
}
