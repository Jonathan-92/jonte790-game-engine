#ifndef CHECKPOINT_H
#define CHECKPOINT_H

/* This struct is a helpful tool to assign where enemies will move. It simply
stores an x and y coordinate that is set by the constructor. */
struct Checkpoint
{
public:
	Checkpoint(int x, int y);
	const int x;
	const int y;
	~Checkpoint();
};

#endif