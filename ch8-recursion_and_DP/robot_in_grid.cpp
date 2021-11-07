/**
* Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
* The robot can only move in two directions, right and down, 
* but certain cells are "off limits" such that the robot cannot step on them. 
* Design an algorithm to find a path for the robot from the top left to the bottom right.
* The grid has either 1 or 0, denoting if this point is off limits or not, 0 being off limits
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a point in the grid
struct Point {
   int row;
   int column;
   Point(int r, int c){row = r;column=c;}
};

bool operator!= (const Point &p1, const Point &p2){
    return ((p1.row != p2.row) || (p1.column == p2.column));
}

// Directions
Point DIR[4] = {Point(0, 1), Point(1, 0), Point(-1, 0), Point(0, -1)};
// LEFT(0, -1), RIGHT(0, 1), UP(-1, 0), DOWN(1, 0)

bool found_exit = false;

void walk(vector<Point> &path, vector<vector<int>> &grid, Point prev){
    Point cur_coor = path.back();
    int row_len = grid.size(), col_len = grid[0].size();

    // try each directions
    for (size_t d = 0; d < 4 && found_exit == false; d++){
        cur_coor = path.back();
        Point new_cood(cur_coor.row+DIR[d].row, cur_coor.column+DIR[d].column);
        
        // out of the grid
        if (new_cood.row >= row_len || new_cood.row < 0 || new_cood.column >= col_len || new_cood.column < 0)
            continue;

        // check if the next grid is available
        if (prev != DIR[d] && grid[new_cood.row][new_cood.column] == 1){
            path.push_back(new_cood);
            walk(path, grid, DIR[d]);
        }
    }
    
    // if not reach the bottom right, get back
    if ((cur_coor.row == grid.size()-1 && cur_coor.column == grid[0].size()-1) || found_exit){
        found_exit = true;
        return;
    }
    else{
        // if all the directions are not available, get back
        path.pop_back();
    }    
}

vector<Point> findPath(vector<vector<int>> grid){
    vector<Point> path;
    path.push_back(Point(0, 0));
    walk(path, grid, Point(-1, -1));

    return path;
}



int main(){
    vector<vector<int>> grid{
        // {1, 0, 1},
        // {1, 0, 1},
        // {1, 1, 1}
        {1, 1, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    vector<Point> path = findPath(grid);

    return 0;
}
