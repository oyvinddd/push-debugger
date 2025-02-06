#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const std::string dev_server = "api.sandbox.push.apple.com:443";
const std::string prod_server = "api.push.apple.com:443";

std::string create_push_request() {

    return "";
}

int main() {

    int sock = 0;
    struct sockaddr_in server_addr;
    //char buffer[1024] = {0};

    // creating a socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Error creating socket" << std:: endl;
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(443); // host-to-network short (bytes are swapped on little-endian machines)

    // convert address from text to binary form
    if (inet_pton(AF_INET, prod_server.c_str(), &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/address not supported" << std::endl;
        return -1;
    }

    // connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    auto push_req = create_push_request(); 

    close(sock);
    return 0;
}

