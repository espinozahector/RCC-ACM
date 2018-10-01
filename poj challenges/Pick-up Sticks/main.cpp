#include <iostream>

struct POINT{// just to make it easier to keep track of stuff
    int x = 0;// set default values for our struct
    int y = 0;// set default values for our struct
};

struct LINE{// just to make it easier to keep track of stuff
    POINT p1;// start point
    POINT p2;// end point
};

int findOrient(const LINE&, const POINT&);// Used to find the orientation of three points
bool isTouching(const LINE&, const POINT&);// Used to see if a point lies on a line
bool isOnTop(const LINE&, const LINE&);// Used to see if a line segment crosses another line segment


int main() {
    int* answer = nullptr;// Used to keep track of which sticks are on the top 
    LINE* lines = nullptr;// Used to hold all our line segments
    
    int n;
    std::cin>>n;
    
    answer = new int[n];
    lines = new LINE[n];
    
    // input
    for(int i = 0; i < n; i++){
        answer[i] = i + 1;// "id" for each stick
        
        // input starting x,y coords of our line
        std::cin>>lines[i].p1.x;
        std::cin>>lines[i].p1.y;
        
        // input ending x,y coords of our line
        std::cin>>lines[i].p2.x;
        std::cin>>lines[i].p2.y;
    }
    
    std::cout<<std::endl;
    
    // processing
    for(int i = 0; i < n - 1; i++){// n - 1 because last stick is always on top
        for(int j = i + 1; j < n - 1; j++){
            if(isOnTop(lines[i], lines[j])){
                answer[i] = -1;// first stick thrown is on bottom and j is always greater than i therefore j is on top
            } 
        }
    }
    
    // printing
    std::cout<<"Top sticks: ";
    for(int i = 0; i < n; i++){
        if(answer[i] > 0){// if the index is less than one then it isnt a top stick
            std::cout<<answer[i];
            (i + 1 == n)?(std::cout<<"."):(std::cout<<", ");// print formatting
        }
    }
    
    return 0;
}


bool isTouching(const LINE& line, const POINT& p){
    if(p.x <= std::max(line.p1.x, line.p2.x) && // if points x value is between or equal to the lines min and max x value
       p.x >= std::min(line.p1.x, line.p2.x) && 
            
       p.y <= std::max(line.p1.y, line.p2.y) && // if points y value is between or equal to the lines min and max y value
       p.y >= std::min(line.p1.y, line.p2.y)){  
        return true;
    }
            
    return false;
}

int findOrient(const LINE& line, const POINT& p){
    int orientation = (line.p2.y - line.p1.y) * (p.x - line.p2.x) - 
                      (line.p2.x - line.p1.x) * (p.y - line.p2.y);// formula explanation can be found in first link below
    
    if(orientation == 0){
        return 0;// colinear
    }
    else if(orientation > 0){
        return 1;// clockwise
    }
    else{
        return 2;// counter-clockwise
    }
    
    std::cout<<"If this shows up your orientation function is broken"<<std::endl;
    exit(1);
}

bool isOnTop(const LINE& line, const LINE& line2){
    int o1 = findOrient(line, line2.p1);// basically what this does is make sure that both points
    int o2 = findOrient(line, line2.p2);// of the second line are above and below the first line segment
    
    int o3 = findOrient(line2, line.p1);// does the same as first but with lines
    int o4 = findOrient(line2, line.p2);// switched
    
    // general case, if line and start/end points have diff orientation then it crosses
    if(o1 != o2 && o3 != o4){
        return true;
    }
    
    // special cases, if the lines are colinear
    if(o1 == 0 && isTouching(line, line2.p1)){
        return true;
    }
    if(o2 == 0 && isTouching(line, line2.p2)){
        return true;
    }
    if(o3 == 0 && isTouching(line2, line.p1)){
        return true;
    }
    if(o4 == 0 && isTouching(line2, line.p2)){
        return true;
    }
    
    // doesnt fall in the above cases so it doesnt intersect
    return false;
    
}

/*
    http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf 
    https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
 * 
 * Resources I used for guidance on this problem
 */