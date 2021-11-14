#include <iostream>
#include <array>

#include "../include/mouse/mouse.h"
#include "../include/api/api.h"


int main() {

	rwa2::Mouse mouse; // Instantiating a mouse object
	mouse.display_walls(); // Displaying the boundary walls of the maze
	if(!mouse.search_maze()){ // Computing the path from start to goal nodes
		std::cerr << "Path Not Found\n";
	}
	else{
		std::cerr << "Path Found \n";
	}
	return 0;
}