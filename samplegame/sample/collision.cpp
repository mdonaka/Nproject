#include "collision.h"

int collision_rect(int x, int y, int width, int height, int pointX, int pointY){
	if (x <= pointX&&pointX <= x + width&&y <= pointY&&pointY <= y + height){
		return 1;
	}
	else{
		return 0;
	}
}
