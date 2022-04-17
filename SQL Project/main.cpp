#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Query.h"
#include "Index.h"
using namespace std;

void processInput(int argc, char** argv, int& indexType, string& database, vector<Query>& queries, int& pageSize);


int main(int argc, char** argv) {
    if (argc < 7) {
        cout << "Bad Input should be formatted IndexNumber (INT) database (e.g. projDB) queries (0 50 0 50) PageSize (INT OPTIONAL)" << endl;
        return -1;
    }

    int indexType, pageSize;
    string database;
    vector<Query> queries;

    processInput(argc, argv, indexType, database, queries, pageSize);


    ifstream file;
    file.open(database);

    ParentIndex* index = nullptr;

    switch (indexType){
        case 0:
            index = new SequentialSearch();
            break;
        case 1:
            index = new KDSearch(pageSize);
            break;
        case 2:
            index = new MYKDSearch(pageSize);
            break;
        default:
            cout << "Bad indexType value, chose a value in [0, 1, 2]" << endl;
            return -1;
    }

    index->populate(file);

    ofstream out;
    out.open(database + "-out.txt");

    for(auto i: queries){
        auto valid = index->query(i);

        valid = mergeSortX(valid);



        for(auto j: valid){
            out << j->x << " " << j->y << endl;
        }
    }


    return 0;
}

void processInput(int argc, char** argv, int& indexType, string& database, vector<Query>& queries, int& pageSize){

    indexType = stoi(argv[1]);
    database = argv[2];

    for(int i = 3; i < argc - 1; i += 4){
        queries.emplace_back(
                Query(
                        argv[i],
                        argv[i + 1],
                        argv[i + 2],
                        argv[i + 3]
                        )
                );
    }

    if (indexType != 0){
        pageSize = stoi(argv[argc - 1]);
    } else {
        pageSize = -1;
    }
}