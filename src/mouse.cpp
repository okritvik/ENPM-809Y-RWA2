#include "../include/mouse/mouse.h"  
#include "../include/util/util.h"
#include <string>

void rwa2::Mouse::move_forward(){ //moves the mouse to one step forward
    API::moveForward();
}

void rwa2::Mouse::turn_left(){ //turns the mouse to its left (90 CCW)
    API::turnLeft();
    m_direction = (m_direction+3)%4; //changing the direction to local west of mouse
}

void rwa2::Mouse::turn_right(){ // turns the mouse to its right (90 CW)
    API::turnRight();
    m_direction = (m_direction+1)%4; //changing the direction to local east of mouse
}
bool rwa2::Mouse::turn_back(){ // rotates the mouse by 180 degrees
    API::turnRight();
    API::turnRight();
    m_direction = (m_direction+2)%4; //changing the direction to local south of mouse
    return true;
}

bool rwa2::Mouse::search_maze(){
    while (DFS(m_x,m_y)){ // If there is a path this loop will be executed
        bool next_node_flag = false; // this flag is set if the mouse cant be moved to next node.
        size_t size_ns = m_node_stack.size();
        size_t size_fp = m_final_path.size();
        if(size_ns == 0){
            return false; // returns the control to main function [ because no path is found and the stack size is empty ]
        }
        // std::cerr << "Clearing the final path stack\n";
        for(size_t i=0; i<size_fp;i++){
            m_final_path.pop(); // emptying the final path stack
        }
        
        // std::cerr << "Reversing the found stack\n";
        for(size_t i=0;i<size_ns;i++){
            m_final_path.push(m_node_stack.top());
            if(i != 0){
                API::setColor(m_node_stack.top().at(0),m_node_stack.top().at(1),'g'); // colors the tiles of computed path from mouse node to goal node in green
            }
            else{ // sets the goal node text to G1, G2, G3, G4 based on the goal node indices
                if(m_goal_node.at(0) == 7){
                    if(m_goal_node.at(1) == 7){
                        API::setText(7,7,"G1");
                    }
                    else{
                        API::setText(7,8,"G2");
                    }
                }
                else{
                    if(m_goal_node.at(1) == 7){
                        API::setText(8,7,"G3");
                    }
                    else{
                        API::setText(8,8,"G4");
                    }
                }
                API::setColor(m_goal_node.at(0),m_goal_node.at(1),'c'); //sets the goal node color to cyan
            }
            // std::cerr << "Popping from nodestack "<<m_node_stack.top().at(0) << " "<< m_node_stack.top().at(1) <<"\n";
            m_node_stack.pop();
        }
        // std::cerr << "Bot movements starts\n";
        while(true){ // this will loop until a new unknown wall is encountered by the mouse during its transversal
            bool flag = false;
            // If a new wall is found and if not in m_maze, setting the wall
            if(m_direction == direction::NORTH){
                if(API::wallFront()){
                    if(m_maze.at(m_x).at(m_y).is_wall(m_direction)){
                        flag = false;
                    }
                    else{
                        m_maze.at(m_x).at(m_y).set_wall(m_direction,true);
                        API::setWall(m_x,m_y,'n');
                        flag = true;
                    }
                }
                if(API::wallRight()){
                    if(!m_maze.at(m_x).at(m_y).is_wall(m_direction+1)){
                        m_maze.at(m_x).at(m_y).set_wall(m_direction+1,true);
                        API::setWall(m_x,m_y,'e');
                    } 
                }
                if(API::wallLeft()){
                    if(!m_maze.at(m_x).at(m_y).is_wall((m_direction+3)%4)){
                        m_maze.at(m_x).at(m_y).set_wall((m_direction+3)%4,true);
                        API::setWall(m_x,m_y,'w');
                    }
                }
            }
            else if(m_direction == direction::EAST){
                if(API::wallRight()){
                    if(!m_maze.at(m_x).at(m_y).is_wall((m_direction+1))){
                        m_maze.at(m_x).at(m_y).set_wall((m_direction+1),true);
                        API::setWall(m_x,m_y,'s');
                    }
                }
                if(API::wallFront()){
                    if(m_maze.at(m_x).at(m_y).is_wall(m_direction)){
                        flag = false;
                    }
                    else{
                        m_maze.at(m_x).at(m_y).set_wall(m_direction,true);
                        API::setWall(m_x,m_y,'e');
                        flag = true;
                    }
                }
                if(API::wallLeft()){
                    if(!m_maze.at(m_x).at(m_y).is_wall((m_direction-1))){
                        m_maze.at(m_x).at(m_y).set_wall(m_direction-1,true);
                        API::setWall(m_x,m_y,'n');
                    }   
                }
            }
            else if(m_direction == direction::SOUTH){
                if(API::wallFront()){
                    if(m_maze.at(m_x).at(m_y).is_wall(m_direction)){
                        flag = false;
                    }
                    else{
                        m_maze.at(m_x).at(m_y).set_wall(m_direction,true);
                        API::setWall(m_x,m_y,'s');
                        flag = true;
                    }
                }
                if(API::wallLeft()){
                    if(!m_maze.at(m_x).at(m_y).is_wall(m_direction-1)){
                        m_maze.at(m_x).at(m_y).set_wall(m_direction-1,true);                    
                        API::setWall(m_x,m_y,'e');
                    }
                }
                if(API::wallRight()){
                    if(!m_maze.at(m_x).at(m_y).is_wall(m_direction+1)){
                        m_maze.at(m_x).at(m_y).set_wall(m_direction+1,true);                    
                        API::setWall(m_x,m_y,'w');
                    }
                }
            }
            else if(m_direction == direction::WEST){
                if(API::wallLeft()){
                    if(!m_maze.at(m_x).at(m_y).is_wall((m_direction-1))){
                        m_maze.at(m_x).at(m_y).set_wall((m_direction-1),true);
                        API::setWall(m_x,m_y,'s');
                    }
                }
                if(API::wallFront()){
                    if(m_maze.at(m_x).at(m_y).is_wall(m_direction)){
                        flag = false;
                    }
                    else{
                        m_maze.at(m_x).at(m_y).set_wall(m_direction,true);
                        API::setWall(m_x,m_y,'w');
                        flag = true;
                    }
                }
                if(API::wallRight()){
                    if(!m_maze.at(m_x).at(m_y).is_wall((m_direction+1)%4)){
                        m_maze.at(m_x).at(m_y).set_wall((m_direction+1)%4,true);
                        API::setWall(m_x,m_y,'n');
                    }
                }
            }
            if(flag){ // flag is true when there is an unknown wall in mouse's north
                break;
            }
            
            // std::cerr << "X and Y of path stack: "  << m_final_path.top().at(0) << " " << m_final_path.top().at(1) << "\n";
            m_curr_node = m_final_path.top(); // current node will be the top node of the path stack and the control returns true if the current node is goal
            if((m_curr_node.at(0) == m_goal_node.at(0)) && (m_curr_node.at(1)==m_goal_node.at(1))){
                return true;
            }
            m_final_path.pop(); // popping the current node
            // std::cerr << "Next X and Y of path stack: "  << m_final_path.top().at(0) << " " << m_final_path.top().at(1) << "\n";
            m_next_node = m_final_path.top(); // pointing the next node to the new top node of path stack
            m_x = m_next_node.at(0);
            m_y = m_next_node.at(1);
            if(!move_to_next_node(m_next_node,m_curr_node,m_direction)){ // checks if there is a possibility to move to the next node in the path
                next_node_flag = true;
                break;
            }
        }
        if(next_node_flag){ // condition is true when mouse can't move to next node
            m_x = m_curr_node.at(0);
            m_y = m_curr_node.at(1);
        }
        else{
            m_x = m_final_path.top().at(0);
            m_y = m_final_path.top().at(1);
        }
        if((m_x == m_goal_node.at(0)) && (m_y == m_goal_node.at(1))){
            return true;
        }
        m_visited_nodes = {false}; // clearing the visited nodes array
        // std::cerr << "Passing the x and y: " << m_x << " " << m_y << "\n";
    }
    return false;
}

bool rwa2::Mouse::DFS(int l_x,int l_y){
    API::clearAllColor(); // clear the tiles color before generating a new path
    if(l_x != m_goal_node.at(0) || l_y != m_goal_node.at(1)){
        if(m_node_stack.empty()){ // if stack is empty, push the current node
            m_curr_node.at(0) = l_x;
            m_curr_node.at(1) = l_y;
            m_node_stack.push(m_curr_node);
            // std::cerr << "Pushed to stack: " << m_curr_node.at(0) <<", " << m_curr_node.at(1) << "\n";
            (m_visited_nodes.at(l_y)).at(l_x) = true;
        }
    }
    else{
        // std::cerr << "NODE STACK SIZE BEFORE POPPING IS: "<< m_node_stack.size() << "\n";
        return true;
    }
    // if the next node is valid, then pushing to the stack (valid => no wall and the node is not in visited list)
    if(!(m_maze.at(l_x).at(l_y).is_wall(direction::NORTH)) && (update_next_node(direction::NORTH,m_next_node,m_curr_node) && (!is_visited(m_visited_nodes,m_next_node)))){
        m_node_stack.push(m_next_node);
        (m_visited_nodes.at(m_next_node.at(1))).at(m_next_node.at(0)) = true;
    }
    else if(!(m_maze.at(l_x).at(l_y).is_wall(direction::EAST)) && (update_next_node(direction::EAST,m_next_node,m_curr_node) && (!is_visited(m_visited_nodes,m_next_node)))){
        m_node_stack.push(m_next_node);
        (m_visited_nodes.at(m_next_node.at(1))).at(m_next_node.at(0)) = true;
    }
    else if(!(m_maze.at(l_x).at(l_y).is_wall(direction::SOUTH)) && (update_next_node(direction::SOUTH,m_next_node,m_curr_node) && (!is_visited(m_visited_nodes,m_next_node)))){
        m_node_stack.push(m_next_node);
        (m_visited_nodes.at(m_next_node.at(1))).at(m_next_node.at(0)) = true;
    }
    else if(!(m_maze.at(l_x).at(l_y).is_wall(direction::WEST)) && (update_next_node(direction::WEST,m_next_node,m_curr_node) && (!is_visited(m_visited_nodes,m_next_node)))){
        m_node_stack.push(m_next_node);
        (m_visited_nodes.at(m_next_node.at(1))).at(m_next_node.at(0)) = true;
    }
    else{
        //backtracking
        if(!m_node_stack.empty()){
            // std::cerr << "Popped from stack: "<<m_node_stack.top().at(0)<<", "<<m_node_stack.top().at(1) << "\n";
            m_node_stack.pop();            
        }
        else{
            return false;
        }
    }
    // std::cerr << "Pushed to stack: "<<m_next_node.at(0)<<", "<<m_next_node.at(1) << "\n";
    
    // If the stack is not empty, it computes the DFS path
    if(!m_node_stack.empty()){
        m_top_node = m_node_stack.top();
        m_curr_node.at(0) = m_top_node.at(0);
        m_curr_node.at(1) = m_top_node.at(1);
        // std::cerr << "Curr_x: " << m_curr_node.at(0) << " Curr_y: " << m_curr_node.at(1) <<"\n";
        return DFS(m_curr_node.at(0),m_curr_node.at(1));
    }
    else{
        return false;
    }
}

void rwa2::Mouse::display_walls() {
    for (int x = 0; x < m_maze_width; x += 1) {
        for (int y = 0; y < m_maze_height; y += 1) {
            if (m_maze.at(x).at(y).is_wall(direction::NORTH)) {
                //display this wall in the simulator
                API::setWall(x, y, 'n');
            }
                
            if (m_maze.at(x).at(y).is_wall(direction::EAST)) {
                //display this wall in the simulator
                API::setWall(x, y, 'e');
            }
                
            if (m_maze.at(x).at(y).is_wall(direction::SOUTH)) {
                //display this wall in the simulator
                API::setWall(x, y, 's');
            }
                
            if (m_maze.at(x).at(y).is_wall(direction::WEST)) {
                //display this wall in the simulator
                API::setWall(x, y, 'w');
            }
            //display the number of walls surrounding the current node
            API::setText(x, y, std::to_string(m_maze.at(x).at(y).compute_number_of_walls()));
        }
    }
}

bool rwa2::Mouse::is_visited(std::array<std::array<bool,16>,16> &m_visited_nodes, std::array<int,2> &node){
        return m_visited_nodes.at(node.at(1)).at(node.at(0));
}

bool rwa2::Mouse::update_next_node(const int& dir,std::array<int,2>& m_next_node, const std::array<int,2>& m_curr_node){
    //Updating the next node based on the direction and current position
    if(dir == direction::NORTH){
        m_next_node.at(0) = m_curr_node.at(0);
        m_next_node.at(1) = m_curr_node.at(1)+1;
    }
    else if(dir == direction::EAST){
        m_next_node.at(0) = m_curr_node.at(0)+1;
        m_next_node.at(1) = m_curr_node.at(1);
    }
    else if(dir == direction::SOUTH){
        m_next_node.at(0) = m_curr_node.at(0);
        m_next_node.at(1) = m_curr_node.at(1)-1;
    }
    else if(dir == direction::WEST){
        m_next_node.at(0) = m_curr_node.at(0)-1;
        m_next_node.at(1) = m_curr_node.at(1);
    }
    return true;
}

bool rwa2::Mouse::move_to_next_node(const std::array<int,2>& m_top_node,const std::array<int,2>& m_curr_node, int& m_direction){
    // calculates the global direction of the next node depending on the mouse's direction
    if(m_top_node.at(0)-m_curr_node.at(0) > 0){ 
        if(m_direction == direction::EAST){
            if(API::wallFront()){
                return false;
            }
            API::moveForward();
        }
        else if(m_direction == direction::SOUTH){
            API::turnLeft();
            m_direction = (m_direction+3)%4; //(m_direction+3)%4 = EAST
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
        else if(m_direction == direction::NORTH){
            API::turnRight();
            m_direction = (m_direction+1)%4; //(m_direction+1)%4 = EAST
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
        else if(m_direction == direction::WEST){
            API::turnRight();
            API::turnRight();
            m_direction = (m_direction+2)%4; //(m_direction+2)%4 = EAST
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
    }
    else if(m_top_node.at(0)-m_curr_node.at(0) < 0){
        if(m_direction == direction::EAST){
            API::turnRight();
            API::turnRight();
            m_direction = (m_direction+2)%4; //(m_direction+2)%4 = WEST
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
            
        }
        else if(m_direction == direction::SOUTH){
            API::turnRight();
            m_direction = (m_direction+1)%4; //(m_direction+1)%4 = WEST
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
        else if(m_direction == direction::NORTH){
            API::turnLeft();
            m_direction = (m_direction+3)%4; //(m_direction+3)%4 = WEST
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
            
        }
        else if(m_direction == direction::WEST){
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
        }
    }
    else if(m_top_node.at(1)-m_curr_node.at(1) > 0){
        if(m_direction == direction::EAST){
            API::turnLeft();
            m_direction = (m_direction+3)%4; //(m_direction+3)%4 = NORTH
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
            
        }
        else if(m_direction == direction::SOUTH){
            API::turnRight();
            API::turnRight();
            m_direction = (m_direction+2)%4; //(m_direction+2)%4 = NORTH
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
        else if(m_direction == direction::NORTH){
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
            
        }
        else if(m_direction == direction::WEST){
            API::turnRight();
            m_direction = (m_direction+1)%4; //(m_direction+2)%4 = NORTH
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
    }
    else if(m_top_node.at(1)-m_curr_node.at(1) < 0){
        if(m_direction == direction::EAST){
            API::turnRight();
            m_direction = (m_direction+1)%4;// (m_direction+1)%4 = SOUTH
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
        else if(m_direction == direction::SOUTH){
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
        }
        else if(m_direction == direction::NORTH){
            API::turnRight();
            API::turnRight();
            m_direction = (m_direction+2)%4; //(m_direction+2)%4 = SOUTH
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
             
        }
        else if(m_direction == direction::WEST){
            API::turnLeft();
            m_direction = (m_direction+3)%4; //(m_direction+3)%4 = SOUTH
            if(API::wallFront()){
                return false;
            }
            
            API::moveForward();
            
        }
    }
    return true;
}