#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *writefile;
    char *writestr;

    writefile = argv[1];
    writestr = argv[2];
    
    int fd;
    size_t sze;

    if (argc < 3){
        printf("Unsuficient number of arguments!\n");
	
	return 1;
    }

    fd = open(writefile, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (fd == -1){
        printf("Error opening %s", writefile); 
    }
    else {
	sze = strlen(writestr);
        write(fd, writestr, sze);
    }

    openlog("writer",LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\".", writestr, writefile);
    syslog(LOG_ERR, "Error message: %m");
    closelog();

    close(fd);

    return 0;
}
