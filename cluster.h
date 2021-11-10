#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include <vector>

#include "vector_ops.h"

using namespace std;


void k_means_plus_plus(int k);
void update(vector<vector<int>>& cluster_table, vector<int>& centroid_ids, int& last_known_id);
//void lloyds(int number_of_clusters, int num_of_points, fstream& output_file, bool complete_flag);


#endif
