all:
	cc util.c -Ofast -c -o util.o
	cc sock.c -Ofast -c -o sock.o
	cc main.c -Ofast -c -o main.o
	cc get.c -Ofast -c -o get.o
	cc set.c -Ofast -c -o set.o
	cc version.c -Ofast -c -o version.o
	cc *.o -Ofast -s -o cisd

install: all
	cp -f cisd /usr/bin/cisd
	cp -f cisd.service /etc/systemd/system/cisd.service
	systemctl enable --now cisd

clean:
	rm -f *.o cisd
