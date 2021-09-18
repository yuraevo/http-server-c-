#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "server.cpp"

/**
 * Initialises the server
 */
int main(void) {

	Server server;
    std::ofstream outputFile("/Users/yuraevo/Desktop/cServer-master/build/index.html", std::ios_base::out);

	std::ifstream( inputFile );
    int port;
    char title[500];
    char heading[500];
    char color[10];
    char body[5000];

	if (outputFile.is_open()) {
        std::cout << "Please enter a title: ";
        std::cin >> title;
        std::cout << "Please enter a heading: ";
        std::cin >> heading;
        std::cout << "What color would you like your heading to be? ";
        std::cin >> color;
        std::cout << "Please enter the body: ";
        std::cin >> body;

        outputFile << "<!doctype html> " << "\n" << "<html> " << "\n" << "<head> " << "<title> " << title << " " << "</title> " << "</head>" << "\n"
           << "<body> " << "\n" << "<h1> " << "<center> " << "<font color=\"" << color << "\"> " << heading << " " << "</font> " << "</center> " << "</h1> " << "\n"
           << body << " " << "\n" << "</body> " << "\n" << "</html> " << "\n";
        outputFile.close();
	}
	std::cout << "Select server port: ";
	std::cin >> port;

	// fail case
	if (std::cin.fail())
		port = 1000;

	server.init(port);

	system("PAUSE");
    return 0;
}