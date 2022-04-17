//
// Created by Chris on 4/16/2022.
//

#ifndef SQL_PROJECT_QUERY_H
#define SQL_PROJECT_QUERY_H

#include <string>

struct Query{
    int xMin, xMax, yMin, yMax;

    Query(int xMin, int xMax, int yMin, int yMax){
        this->xMin = xMin;
        this->xMax = xMax;
        this->yMin = yMin;
        this->yMax = yMax;
    }

    Query(const char* xMin, const char* xMax, const char* yMin, const char* yMax){
        this->xMin = std::stoi(xMin);
        this->xMax = std::stoi(xMax);
        this->yMin = std::stoi(yMin);
        this->yMax = std::stoi(yMax);
    }

    void print(){
        std::cout << "xMin: " << xMin << ", xMax: " << xMax << ", yMin: " << yMin << ", yMax: " << yMax << std::endl;
    }
};
#endif //SQL_PROJECT_QUERY_H
