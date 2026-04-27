// AI Disclaimer: This code was written with minimal AI assistance.
// Used AI for: syntax checking and debugging only.
// Core logic and problem-solving approach are my own work.

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

#include "Shape.h"
#include "Shape.cpp"

// prints all areas - takes vector of unique pointers
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for(const auto& s : shapes) {
        s->display();
        
        double area = s->getArea();
        
        // format output - if its a whole number dont show decimals
        if (area == (int)area) {
            std::cout << "Area: " << (int)area << std::endl;
        }
        else {
            std::cout << std::fixed << std::setprecision(4);
            std::cout << "Area: " << area << "\n";
        }

        std::cout << std::endl; // blank line between shapes
    }
}

int main() {
    std::ifstream infile("shapes.txt");

    if (!infile.is_open()) {
        std::cerr << "Error: could not open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;

    std::string line;
    int lineNum = 0;

    while(getline(infile, line)) {
        lineNum++;
        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Error on line " << lineNum << ": bad rectangle data" << std::endl;
            }
        }
        else if(type == "circle"){
            double r;
            if(ss >> r){
                shapes.push_back(std::make_unique<Circle>(r));
            }
            else {
                std::cerr << "Error on line " << lineNum << ": bad circle data" << std::endl;
            }
        }
        else {
            // unknown shape type
            std::cerr << "Error on line " << lineNum << ": unknown shape type \"" << type << "\"" << std::endl;
        }
    }

    infile.close();

    printAllAreas(shapes);

    // unique_ptrs clean themselves up, no delete needed

    return 0;
}