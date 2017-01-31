all: rf

rf: rf.c
	gcc -o $@ $<
