// Return true if ring buffer is empty
#define RING_BUFFER_EMPTY(name)		(name##Read == name##Write)

// Return true if ring buffer is full
#define RING_BUFFER_FULL(name)		( ((name##Write+1) & (name##Size-1)) == name##Read )

// Write value to ring buffer
#define RING_BUFFER_WRITE(name, value)	\
	name[name##Write++] = value;		\
	name##Write &= (name##Size-1)

// Return value from ring buffer
#define RING_BUFFER_READ(name)			\
	name[name##Read++];					\
	name##Read &= (name##Size-1)
