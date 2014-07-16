#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
	uint64_t r;
	uint64_t t;
} s_rt;

main(int argc, char** argv) // map a normal file as shared mem:
{
	int fd;
	int trt;
	int sr;
	s_rt *wrt;

	fd=open("/tmp/apachert.mmap",O_CREAT|O_RDWR|O_TRUNC,00644);
	lseek(fd,sizeof(s_rt)-1,SEEK_SET);
	write(fd,"",1);
	
	wrt = (s_rt*) mmap( NULL,sizeof(s_rt),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0 );
	(*wrt).t = 0;
	(*wrt).r = 0;
	close( fd );
	while(1) {
		sr = scanf("%d", &trt);
		if(sr == -1) usleep(10000);
		else {
			(*wrt).r ++;
			(*wrt).t += trt;
		}
	}
	munmap( wrt, sizeof(s_rt));
}

