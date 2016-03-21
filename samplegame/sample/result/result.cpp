#include"result.h"

void result(Scene *scene){
	SetMainWindowText("Œ‹‰Ê‰æ–Ê");
	DrawFormatString(20, 450, 0xffffff, "x‚Åƒ^ƒCƒgƒ‹‰æ–Ê‚Ö");

	if (CheckHitKey(KEY_INPUT_X)){
		*scene = Title;
	}
}