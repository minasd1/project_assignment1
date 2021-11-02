#ifndef LSH_H
#define LSH_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "vector_ops.h"
#include "hash_functions.h"
#include "hashTable.h"


using namespace std;

typedef struct dist_id_pair {
    float dist; //DISTANCE BETWEEN POINT AND QUERY POINT
    int id; //ID OF THE POINT
}dist_id_pair;

vector<dist_id_pair> find_approximate_knn(vector<int> query_point, int k,  G& g, int max_candidates=-1);

vector<int> range_search(vector<int>& g, int radius, vector<int>& query_point);









#endif