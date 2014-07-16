all: agent gather
agent:
	gcc -o asar_apache_agent asar_apache_agent.c
gather:
	gcc -o asar_apache_gather asar_apache_gather.c
clean:
	rm -f asar_apache_gather asar_apache_agent asar
install:
	cp asar.py asar
	install -t /usr/local/sbin -s -o root -g root -m 0755 asar_apache_agent
	install -t /usr/local/sbin -s -o root -g root -m 0755 asar_apache_gather
#	install -t /usr/local/sbin -o root -g root -m 0755 asar_gather.py
#	install -t /usr/local/bin -o root -g root -m 0755 asar
