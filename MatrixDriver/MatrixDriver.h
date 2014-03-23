#ifndef MatrixDriver_h
#define MatrixDriver_h

#include "Arduino.h"

class MatrixDriver {
public:
	MatrixDriver();
	void setPosition(int pos);
	void setSingleScrolling(char *text, int size, int loops);
	void setStaticText(char c);
	void setStaticNumber(int i);
	void setPlayerStatus(int score, int turbo);
	void setTurbo(int turbo);
	void setMultiScrolling(char *text, int size);
	byte getColumn(int C);
	void scroll();
	void startScrolling();
	void stopScrolling();
	void enableMultiScrolling();
	void enableSingleScrolling();
	void showPosition();
	void clearDisplay();
	void setIcon(int icon);
private:
	void setCurrentChars();
	void fillDisplay();
	char single_text[60];
	char multi_text[60];
	byte display[8];
	char current_char;
	char next_char;
	int single_column;
	int multi_column;
	int full_column;
	int single_text_length;
	int multi_text_length;
	int single_loop_count;
	int loops;
	int position;
	int mode;
	int next_mode;
	int single_char_pos;
	int multi_char_pos;
	int step_count;
	boolean scroll_enabled;
	int score;
	int turbo;
};

#endif
