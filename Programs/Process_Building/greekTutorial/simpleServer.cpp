/* Topics covered:
 * 		1) Simple server following TCP protocol
 *
 * Ideas:
 * 		1) Use observer or another design pattern for listeners
 *
 */

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

using namespace std;

//This must be cast to sockaddr structure.
//TODO - How the hell is the cast working ???
struct sockaddr_in {
	unsigned short sin_family; //Protocol Family AF_INET
	unsigned short sin_port;   //Address port (16 bits)
	struct in_addr sin_addr;
};

int main() {

	int sockid{socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)};

	if (sockid!= -1 ) {

		unsigned short addrport{htons(5100)};

		//INADDR_ANY to binds socket to all available interfaces
		unsigned long  portSize{htons(INADDR_ANY)};

		//TODO - Cast it to a pointer to the structure castable to sockaddr
		int status{bind(sockid, &addrport, portSize)};
	}


}
