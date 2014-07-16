all: agent
agent:
	gcc -o asar_apache_agent asar_apache_agent.c
clean:
	rm -f asar_apache_agent
install:
	install -t /usr/local/sbin -s -o root -g root -m 0755 asar_apache_agent
