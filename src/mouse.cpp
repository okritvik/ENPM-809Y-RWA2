#include "../include/mouse/mouse.h"  
#include "../include/api/api.h"  
#include "../include/util/util.h"
#include <string>
// #include <iterator>


void move_to_prev_node(const std::array<int,2>& top_node,const std::array<int,2>& curr_node, int& m_direction);


void rwa2::Mouse::move_forward(){
    API::moveForward();
}

void rwa2::Mouse::turn_left(){
    API::turnLeft();
    m_direction = (m_direction+3)%4;
}

void rwa2::Mouse::turn_right(){
    API::turnRight();
    m_direction = (m_direction+1)%4;
}
bool rwa2::Mouse::turn_back(){
    API::turnRight();
    API::turnRight();
    m_direction = (m_direction+2)%4;
    return true;
}

// bool rwa2::Mouse::search_maze(){   
//     curr_node.at(0) = m_x;
//     curr_node.at(1) = m_y;
//     API::setColor(m_x,m_y,'g');

//     if(curr_node.at(0) == 7 && curr_node.at(1) == 7){
//         return true;
//     }
//     else{
//         node_stack.push(curr_node);
//     }
//     if(visited_nodes.size() == 0){
//         visited_nodes.push_back(curr_node);
//     }
    //SELF CODE

    
    // if(!API::wallFront()){
    //     update_next_node(m_direction,next_node,curr_node);
    //     if(!is_visited(visited_nodes,next_node)){
    //         std::cerr << "No wall front\n";
    //         // std::cerr << m_x << m_y << '\n';
    //         API::moveForward();
    //         visited_nodes.push_back(next_node);
    //     }
    //     else if(!API::wallRight()){
    //         update_next_node((m_direction+1)%4,next_node,curr_node);
    //         if(!is_visited(visited_nodes,next_node)){
    //             std::cerr << "No wall to right\n";
    //             // std::cerr << m_x << m_y << '\n';
    //             API::turnRight();
    //             API::moveForward();
    //             m_direction = (m_direction+1)%4;
    //             visited_nodes.push_back(next_node);
    //         }
    //     }
    //     else if(!API::wallLeft()){
    //         update_next_node((m_direction+3)%4,next_node,curr_node);
    //         if(!is_visited(visited_nodes,next_node)){
    //             std::cerr << "No wall to left\n";
    //             // std::cerr << m_x << m_y << '\n';
    //             API::turnLeft();
    //             API::moveForward();
    //             m_direction = (m_direction+3)%4;
    //             visited_nodes.push_back(next_node);
    //         }
    //     }
    //     else if(!node_stack.empty()){
    //         std::cerr << "I am in the else condition to backtrack\n";
    //         node_stack.pop();
    //         top_node = node_stack.top();
    //         if(top_node.at(0)==curr_node.at(0) && top_node.at(1) == curr_node.at(1)){
    //             node_stack.pop();
    //         }
    //         top_node = node_stack.top();
    //         // API::turnRight();
    //         // API::turnRight();
    //         // m_direction = (m_direction+2)%4;
    //         move_to_prev_node(top_node,curr_node,m_direction);
    //         m_x = top_node.at(0);
    //         m_y = top_node.at(1);
    //         std::cerr <<"Maze function called again\n";
    //         search_maze();
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // else if(!API::wallRight()){
    //     update_next_node((m_direction+1)%4,next_node,curr_node);
    //     if(!is_visited(visited_nodes,next_node)){
    //         std::cerr << "No wall to right\n";
    //         // std::cerr << m_x << m_y << '\n';
    //         API::turnRight();
    //         API::moveForward();
    //         m_direction = (m_direction+1)%4;
    //         visited_nodes.push_back(next_node);
    //     }
    //     else if(!API::wallLeft()){
    //         update_next_node((m_direction+3)%4,next_node,curr_node);
    //         if(!is_visited(visited_nodes,next_node)){
    //             std::cerr << "No wall to left\n";
    //             // std::cerr << m_x << m_y << '\n';
    //             API::turnLeft();
    //             API::moveForward();
    //             m_direction = (m_direction+3)%4;
    //             visited_nodes.push_back(next_node);
    //         }
    //     }
    //     else if(!node_stack.empty()){
    //         std::cerr << "I am in the else condition to backtrack\n";
    //         node_stack.pop();
    //         top_node = node_stack.top();
    //         if(top_node.at(0)==curr_node.at(0) && top_node.at(1) == curr_node.at(1)){
    //             node_stack.pop();
    //         }
    //         top_node = node_stack.top();
    //         // API::turnRight();
    //         // // API::turnRight();
    //         // m_direction = (m_direction+1)%4;
    //         // API::moveForward();
    //         move_to_prev_node(top_node,curr_node,m_direction);
    //         m_x = top_node.at(0);
    //         m_y = top_node.at(1);
    //         std::cerr <<"Maze function called again\n";
    //         search_maze();
    //     }
    //     else{
    //         return false;
    //         }

    //     }
    // else if(!API::wallLeft()){
    //     update_next_node((m_direction+3)%4,next_node,curr_node);
    //     if(!is_visited(visited_nodes,next_node)){
    //         std::cerr << "No wall to left\n";
    //         // std::cerr << m_x << m_y << '\n';
    //         API::turnLeft();
    //         API::moveForward();
    //         m_direction = (m_direction+3)%4;
    //         visited_nodes.push_back(next_node);
    //     }
    //     else{
    //         if(!node_stack.empty()){
    //             std::cerr << "I am in the else condition to backtrack\n";
    //             node_stack.pop();
    //             top_node = node_stack.top();
    //             if(top_node.at(0)==curr_node.at(0) && top_node.at(1) == curr_node.at(1)){
    //                 node_stack.pop();
    //             }
    //             top_node = node_stack.top();
    //             // API::turnLeft();
    //             // // API::turnRight();
    //             // m_direction = (m_direction+3)%4;
    //             // API::moveForward();
    //             move_to_prev_node(top_node,curr_node,m_direction);
    //             m_x = top_node.at(0);
    //             m_y = top_node.at(1);
    //             std::cerr <<"Maze function called again\n";
    //             search_maze();
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    // }
    // else{
    //     if(!node_stack.empty()){
    //         std::cerr << "I am in the else condition to backtrack\n";
    //         node_stack.pop();
    //         top_node = node_stack.top();
    //         // API::turnRight();
    //         // API::turnRight();
    //         // m_direction = (m_direction+2)%4;
    //         // API::moveForward();
    //         if(top_node.at(0)==curr_node.at(0) && top_node.at(1) == curr_node.at(1)){
    //             node_stack.pop();
    //         }
    //         top_node = node_stack.top();
    //         move_to_prev_node(top_node,curr_node,m_direction);
    //         m_x = top_node.at(0);
    //         m_y = top_node.at(1);
    //         std::cerr <<"Maze function called again\n";
    //         search_maze();
    //     }
    //     else{
    //         return false;
    //     }

    // }
    // m_x = next_node.at(0);
    // m_y = next_node.at(1);
    // search_maze();





    //PREVIOUS CODE

    // std::cerr << m_x << '\t' << m_y << '\n';
    // while(true){
    //     if(!API::wallFront()){
    //         API::moveForward();
    //     }
    //     else if(!API::wallLeft()){
    //         API::turnLeft();
    //         API::moveForward();
    //     }
    //     else if(!API::wallRight()){
    //         API::turnRight();
    //         API::moveForward();
    //     }
    //     else{
    //         API::turnRight();
    //         API::turnRight();
    //         API::moveForward();
    //     }
    // }
    // return true;

    // if((curr_node.at(0) != 7) && (curr_node.at(1) != 7)){
    //     node_stack.push(curr_node);
    //     std::cerr << "Stack pushed\n";
    // }
    

    // else{
    //     return true;
    // }

    // // if(std::find(visited_nodes.begin(),visited_nodes.end(),curr_node) == visited_nodes.end()){
    // //     visited_nodes.push_back(curr_node);
    // // }
    // if(visited_nodes.size() == 0){
    //     visited_nodes.push_back(curr_node);
    //     std::cerr << "Visited node pushed \n";
    // }
    
    
    // if(!API::wallFront()){
    //     update_next_node(m_direction,next_node,curr_node);        
    //     if(!is_visited(visited_nodes,next_node)){
    //         std::cerr << "NO wall front\n";
    //         // std::cerr << m_x << m_y << '\n';
    //         API::moveForward();
    //         visited_nodes.push_back(next_node);
    //     }
    //     else if(API::wallRight()){
    //         if(!node_stack.empty()){
    //             node_stack.pop();
    //             top_node = node_stack.top();
    //             API::moveForward();
    //             m_x = top_node.at(0);
    //             m_y = top_node.at(1);
    //             std::cerr <<"Maze function called again\n";
    //             search_maze();
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     else{
    //         API::turnRight();
    //         m_direction = (m_direction+1)%4;
    //     }

    // }
    // else{
    //     API::turnRight();
    //     m_direction = (m_direction+1)%4;
    // }
    // // else if(!API::wallRight()){
    // //     // m_maze.at(m_x).at(m_y).set_wall(direction::NORTH, true);
    // //     update_next_node((m_direction+1)%4,next_node,curr_node);        
    // //     if(!is_visited(visited_nodes,next_node)){
    // //         API::turnRight();
    // //         m_direction = (m_direction+1)%4;
    // //         API::moveForward();
    // //     }
    // // }
    // // // m_maze.at(m_x).at(m_y).set_wall(direction::EAST, true);
    // // else if (true){
    // //     API::turnRight();
    // //     API::turnRight();
    // //     m_direction = (m_direction+2)%4;
    // //     if(!API::wallFront()){
    // //         update_next_node(m_direction,next_node,curr_node);        
    // //         if(!is_visited(visited_nodes,next_node)){
    // //             API::moveForward();
    // //         }
    // //     }
        
    // // }
    // // else if(!API::wallRight()){

    // //     // m_maze.at(m_x).at(m_y).set_wall(direction::NORTH, true);
    // //     update_next_node((m_direction+1)%4,next_node,curr_node);        
    // //     if(!is_visited(visited_nodes,next_node)){
    // //         API::turnRight();
    // //         m_direction = (m_direction+1)%4;
    // //         API::moveForward();
    // //     }
    // // }
    // // m_maze.at(m_x).at(m_y).set_wall(direction::EAST, true);
    // m_x = next_node.at(0);
    // m_y = next_node.at(1);
    // search_maze();  
// }


//NEWLY WRITTEN FUNCTION

bool rwa2::Mouse::search_maze(){
    if(m_x != 8 || m_y != 7){
        if(node_stack.empty()){
            // curr_node.at(0) = m_x;
            // curr_node.at(1) = m_y;
            node_stack.push(curr_node);
            API::setColor(node_stack.top().at(0),node_stack.top().at(1),'g');
            std::cerr << "Pushed to stack: " << curr_node.at(0) <<", " << curr_node.at(1) << "\n";
            (visited_nodes.at(m_y)).at(m_x) = 1;
        }
    }
    else{
        return true;
    }
    if((!API::wallFront()) && (update_next_node(m_direction,next_node,curr_node) && (!is_visited(visited_nodes,next_node)))){
        update_walls(node_stack,m_direction);
        node_stack.push(next_node);
        API::setColor(node_stack.top().at(0),node_stack.top().at(1),'g');
        (visited_nodes.at(next_node.at(1))).at(next_node.at(0)) = 1;
        // curr_node.at(0) = next_node.at(0);
        // curr_node.at(1) = next_node.at(1);
        // m_x = curr_node.at(0);
        // m_y = curr_node.at(1);
        
        move_forward();
    }
    else if((!API::wallRight()) && (update_next_node((m_direction+1)%4,next_node,curr_node) && (!is_visited(visited_nodes,next_node)))){
        update_walls(node_stack,m_direction);
        node_stack.push(next_node);
        API::setColor(node_stack.top().at(0),node_stack.top().at(1),'g');
        (visited_nodes.at(next_node.at(1))).at(next_node.at(0)) = 1;
        // curr_node.at(0) = next_node.at(0);
        // curr_node.at(1) = next_node.at(1);
        // m_x = curr_node.at(0);
        // m_y = curr_node.at(1);
        
        turn_right();
        move_forward();
    }
    else if((!API::wallLeft()) && (update_next_node((m_direction+3)%4,next_node,curr_node) && (!is_visited(visited_nodes,next_node)))){
        update_walls(node_stack,m_direction);
        node_stack.push(next_node);
        API::setColor(node_stack.top().at(0),node_stack.top().at(1),'g');
        (visited_nodes.at(next_node.at(1))).at(next_node.at(0)) = 1;
        turn_left();
        move_forward();
    }
    // else if((turn_back()) && (!API::wallFront()) && (update_next_node((m_direction+2)%4,next_node,curr_node) && (!is_visited(visited_nodes,next_node)))){
    //     node_stack.push(next_node);
    //     (visited_nodes.at(next_node.at(1))).at(next_node.at(0)) = 1;
    //     // curr_node.at(0) = next_node.at(0);
    //     // curr_node.at(1) = next_node.at(1);
    //     // m_x = curr_node.at(0);
    //     // m_y = curr_node.at(1);
    //     move_forward();
    // }
    
    else{
        if(!node_stack.empty()){
            API::setColor(node_stack.top().at(0),node_stack.top().at(1),'a');
            update_walls(node_stack,m_direction);
            std::cerr << "Popped from stack: "<<node_stack.top().at(0)<<", "<<node_stack.top().at(1) << "\n";
            node_stack.pop();
            top_node = node_stack.top();
            move_to_prev_node(top_node,curr_node,m_direction);
            // curr_node.at(0) = top_node.at(0);
            // curr_node.at(1) = top_node.at(1);
            // next_node.at(0) = curr_node.at(0);
            // next_node.at(1) = curr_node.at(1);
            // //search_maze();
        }
        else{
            return false;
        }
    }
    std::cerr << "Pushed to stack: "<<next_node.at(0)<<", "<<next_node.at(1) << "\n";
    if(!node_stack.empty()){
        // top_node = node_stack.top();
        // //move_to_prev_node(top_node,curr_node,m_direction);
        // curr_node.at(0) = top_node.at(0);
        // curr_node.at(1) = top_node.at(1);
        // m_x = curr_node.at(0);
        // m_y = curr_node.at(1);
        top_node = node_stack.top();
        
        curr_node.at(0) = top_node.at(0);
        curr_node.at(1) = top_node.at(1);
        std::cerr << "Curr_x: " << curr_node.at(0) << " Curr_y: " << curr_node.at(1) <<"\n";
        m_x = curr_node.at(0);
        m_y = curr_node.at(1);
        search_maze();
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

bool rwa2::Mouse::is_visited(std::array<std::array<int,16>,16> &visited_nodes, std::array<int,2> &node){
    if((visited_nodes.at(node.at(1)).at(node.at(0))) == 1){
        return true;
    }
    else{
        return false;
    }
}

bool rwa2::Mouse::update_next_node(const int& dir,std::array<int,2>& next_node, const std::array<int,2>& curr_node){
    if(dir == direction::NORTH){
        next_node.at(0) = curr_node.at(0);
        next_node.at(1) = curr_node.at(1)+1;
    }
    else if(dir == direction::EAST){
        next_node.at(0) = curr_node.at(0)+1;
        next_node.at(1) = curr_node.at(1);
    }
    else if(dir == direction::SOUTH){
        next_node.at(0) = curr_node.at(0);
        next_node.at(1) = curr_node.at(1)-1;
    }
    else if(dir == direction::WEST){
        next_node.at(0) = curr_node.at(0)-1;
        next_node.at(1) = curr_node.at(1);
    }
    return true;
}

void move_to_prev_node(const std::array<int,2>& top_node,const std::array<int,2>& curr_node, int& m_direction){
    if(top_node.at(0)-curr_node.at(0) > 0){
        if(m_direction == direction::EAST){
            API::moveForward();
        }
        else if(m_direction == direction::SOUTH){
            API::turnLeft();
            API::moveForward();
            m_direction = (m_direction+3)%4;
        }
        else if(m_direction == direction::NORTH){
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+1)%4;
        }
        else if(m_direction == direction::WEST){
            API::turnRight();
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+2)%4;
        }
    }
    else if(top_node.at(0)-curr_node.at(0) < 0){
        if(m_direction == direction::EAST){
            API::turnRight();
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+2)%4;
            
        }
        else if(m_direction == direction::SOUTH){
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+1)%4;
        }
        else if(m_direction == direction::NORTH){
            API::turnLeft();
            API::moveForward();
            m_direction = (m_direction+3)%4;
            
        }
        else if(m_direction == direction::WEST){
            API::moveForward();
        }
    }
    else if(top_node.at(1)-curr_node.at(1) > 0){
        if(m_direction == direction::EAST){
            API::turnLeft();
            API::moveForward();
            m_direction = (m_direction+3)%4;
            
        }
        else if(m_direction == direction::SOUTH){
            API::turnRight();
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+2)%4;
        }
        else if(m_direction == direction::NORTH){
            API::moveForward();
            
            
        }
        else if(m_direction == direction::WEST){
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+1)%4;
        }
    }
    else if(top_node.at(1)-curr_node.at(1) < 0){
        if(m_direction == direction::EAST){
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+1)%4;
        }
        else if(m_direction == direction::SOUTH){
            API::moveForward();
        }
        else if(m_direction == direction::NORTH){
            API::turnRight();
            API::turnRight();
            API::moveForward();
            m_direction = (m_direction+2)%4;  
        }
        else if(m_direction == direction::WEST){
            API::turnLeft();
            API::moveForward();
            m_direction = (m_direction+3)%4;
        }
    }
}

void rwa2::Mouse::update_walls(const std::stack<std::array<int,2>> &node_stack, const int& m_direction){
    char dir;
    char left;
    char right;
    switch (m_direction)
    {
    case direction::NORTH:
        dir = 'n';
        break;
    case direction::EAST:
        dir = 'e';
        break;
    case direction::WEST:
        dir = 'w';
        break;
    case direction::SOUTH:
        dir = 's';
        break;
    // default:
    //     break;
    }
    if(dir == 'n'){
        left = 'w';
        right = 'e';
    }
    else if(dir == 'e'){
        left = 'n';
        right = 's';
    }
    else if(dir == 's'){
        left = 'e';
        right = 'w';
    }
    else{
        left = 's';
        right = 'n';
    }
    

        if(API::wallFront()){
            API::setWall(node_stack.top().at(0),node_stack.top().at(1),dir);
        }
        if(API::wallLeft()){
            API::setWall(node_stack.top().at(0),node_stack.top().at(1),left);
        }
        if(API::wallRight()){
            API::setWall(node_stack.top().at(0),node_stack.top().at(1),right);
        }
}