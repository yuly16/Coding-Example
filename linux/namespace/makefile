all: pid network

network: network.c
	gcc $^ -o $@
pid: pid.c
	gcc $^ -o $@

.PHONY: clean

clean:
	rm pid network