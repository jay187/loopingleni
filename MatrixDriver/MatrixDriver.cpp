#include "Arduino.h"
#include "MatrixDriver.h"
#include "Font.h"

const int ICON_SMILEY = 97;

MatrixDriver::MatrixDriver() {
  this->current_char = ' ';
  this->next_char = ' ';
  this->single_column = 0;
  this->multi_column = 0;
  this->full_column = 0;
  this->single_text_length = 0;
  this->multi_text_length = 0;
  this->single_loop_count = 0;
  this->loops = 0;
  this->position = 0;
  this->mode = 0;
  this->next_mode = 0;
  this->single_char_pos = 0;
  this->multi_char_pos = 0;
  this->scroll_enabled = false;
  this->score = 0;
  this->turbo = 0;
  this->step_count = 0;
}

void MatrixDriver::showPosition() {
  this->setStaticNumber(this->position);
}

void MatrixDriver::setSingleScrolling(char *text, int size, int loops) {
  if (this->mode != 1 ){
    this->next_mode = this->mode;
  }
  this->mode = 1;
  this->loops = 0;
  this->single_loop_count = loops;
  this->scroll_enabled = true;
  strcpy(this->single_text, text);
  this->single_text_length = size - 1;
  this->single_char_pos = 0;
  this->setCurrentChars();
  this->fillDisplay();
}

void MatrixDriver::setMultiScrolling(char *text, int size) {
  this->scroll_enabled = true;
  this->mode = 2;
  strcpy(this->multi_text, text);
  this->multi_text_length = size - 1;
  this->multi_char_pos = -1 * this->position;
  this->setCurrentChars();
  this->fillDisplay();
}

void MatrixDriver::setStaticText(char c) {
  this->scroll_enabled = false;
  this->mode = 0;
  this->current_char = c;
  this->next_char = ' ';
  this->setCurrentChars();
  this->fillDisplay();
}

void MatrixDriver::setIcon(int icon) {
  this->scroll_enabled = false;
  this->mode = 0;
  this->next_char = ' ';
  //this->setCurrentChars();
  this->fillDisplay();
}

void MatrixDriver::setStaticNumber(int i) {
  this->scroll_enabled = false;
  this->mode = 0;
  this->current_char = (char) (i + 48);
  this->next_char = ' ';
  this->setCurrentChars();
  this->fillDisplay();
}

void MatrixDriver::setPlayerStatus(int score, int turbo) {
  if (this->mode != 1) {
    this->scroll_enabled = false;
    this->mode = 3;
    this->score = score;
    this->turbo = turbo;

    for (int c = 2; c >= 0; c--) {
      this->display[c + 5] = pgm_read_byte(&font_3x5[score / 10][2 - c]);
      this->display[c] = pgm_read_byte(&font_3x5[score % 10][2 - c]);
    }
    this->display[3] = 0;
    this->display[4] = 0;

    //SET TURBO LEDS
    int t = 7;
    for (; t > 7 - (turbo * 8 / 100); t--) {
      bitSet(this->display[t], 1);
      bitSet(this->display[t], 0);
    }
    for (; t >= 0; t--) {
      bitClear(this->display[t], 1);
      bitClear(this->display[t], 0);
    }
  }
}

void MatrixDriver::clearDisplay() {
  this->setStaticText(' ');
}

void MatrixDriver::setTurbo(int turbo) {
  this->turbo = turbo;
  if (this->mode == 3) {
    this->setPlayerStatus(this->score, turbo);
  }
}

void MatrixDriver::setCurrentChars() {
  if (mode == 1) {
    this->current_char = this->single_text[this->single_char_pos];
    if (this->single_char_pos + 1 < this->single_text_length){
      this->next_char = this->single_text[this->single_char_pos + 1];
    }
    else{
      this->next_char = ' ';
    }

  }
  else if (mode == 2) {
    if (this->multi_char_pos >= 0) {
      this->current_char = this->multi_text[this->multi_char_pos];
      if (this->multi_char_pos + 1 < this->multi_text_length){
        this->next_char = this->multi_text[this->multi_char_pos + 1];
      }
      else{
        this->next_char =  ' ';
      }
    }
    else {
      this->current_char = ' ';
      this->next_char = ' ';
    }
  }
}

void MatrixDriver::fillDisplay() {
  if (this->mode < 3) {
    int char_pos = 0;
    int max = 0;
    if (this->mode == 1) {
      char_pos = this->single_column;
      max = this->single_column;
    }
    else if (this->mode == 2) {
      char_pos = this->multi_column;
      max = this->multi_column;
    }
    else {
      char_pos = 0;
      max = 0;
    }

    int c = 7;
    for (; c >= max; c--) {
      this->display[c] = pgm_read_byte(&font_8x8[this->current_char - ' '][char_pos]);
      char_pos++;
    }
    char_pos = 0;
    for (; c >= 0; c--) {
      this->display[c] = pgm_read_byte(&font_8x8[this->next_char - ' '][char_pos]);
      char_pos++;
    }
  }
  else {
    this->setPlayerStatus(this->score, this->turbo);
  }

}

void MatrixDriver::setPosition(int pos) {
  this->position = pos;
}

void MatrixDriver::stopScrolling() {
  this->scroll_enabled = false;
}

void MatrixDriver::startScrolling() {
  this->scroll_enabled = true;
}

void MatrixDriver::enableSingleScrolling() {
  this->mode = 1;
  this->scroll_enabled = true;
}

void MatrixDriver::enableMultiScrolling() {
  this->mode = 2;
  this->scroll_enabled = true;
}

void MatrixDriver::scroll() {
  if (this->mode != 2){
    this->single_column++;
//    this->single_column++;
    if (this->single_column >= 8) {
      this->single_column = 0;
      this->single_char_pos++;
      if (this->single_char_pos >= this->single_text_length) {
        this->loops++;
        this->single_char_pos = 0;
        if (this->mode == 1 && this->loops >= this->single_loop_count) {
          this->mode = this->next_mode;
        }
      }
      this->setCurrentChars();
    }
  }
  else{
    this->multi_column++;
    if (this->multi_column >= 8) {
      this->multi_column = 0;
      this->multi_char_pos++;
      if (this->multi_char_pos >= this->multi_text_length) {
        this->multi_char_pos = 0;
      }
      this->setCurrentChars();
    }
    this->step_count = 0;
  }
  if (scroll_enabled) {
    this->fillDisplay();
  }
  this->step_count++;
}

byte MatrixDriver::getColumn(int c) {
  return this->display[c];
}

