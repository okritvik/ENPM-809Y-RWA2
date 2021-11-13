#include <iostream>
#include <array>

#include "../include/mouse/mouse.h"
#include "../include/api/api.h"


int main() {

	rwa2::Mouse mouse;
	mouse.display_walls();
	if(!mouse.search_maze()){
		std::cerr << "Path Not Found\n";
	}
	else{
		std::cerr << "Path Found \n";
	}
	return 0;
}