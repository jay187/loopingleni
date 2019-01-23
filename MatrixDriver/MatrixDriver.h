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
	uint8_t single_column;
	uint8_t multi_column;
	uint8_t full_column;
	uint8_t single_text_length;
	uint8_t multi_text_length;
	uint8_t single_loop_count;
	uint8_t loops;
	uint8_t position;
	uint8_t mode;
	uint8_t next_mode;
	uint8_t single_char_pos;
	uint8_t multi_char_pos;
	uint8_t step_count;
	boolean scroll_enabled;
	uint8_t score;
	uint8_t turbo;
};

#endif
