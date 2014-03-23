#ifndef LoopingLouieStruct_h
#define LoopingLouieStruct_h

typedef struct {
	boolean active;
	int lost;
	int turbo_load;
	unsigned long last_turbo;
	int chip_count;
	boolean pending_chip;
} Player;

#endif
