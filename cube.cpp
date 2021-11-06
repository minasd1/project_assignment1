#include "cube.h"


//RETURN ALL POINTS THAT ARE INSIDE THE GIVEN RANGE OF QUERY
vector<int> cube_range_search(int g, int radius, int probes, int dimensions, vector<int> query_point){

    int retrieved_items = 0;
    int max_retrieved_items = 500;  //THIS MUST BE CHANGED

    //A VECTOR WITH ALL THE RELATIVE BUCKETS OF QUERY POINT IN HYPERCUBE
    vector <unsigned int> relative_buckets_indexes;
    relative_buckets_indexes = get_relative_buckets(g, probes, dimensions);

    //POINTS THAT ARE IN THE GIVEN RADIUS
    vector<int> points_in_range;

    //FOR ALL THE ELEMENTS IN QUERY POINT'S BUCKET (INDICATED BY G)
    for(int i = 0; i < hyperCube_get_bucket_size(g); i++){
        //IF DISTANCE BETWEEN QUERY POINT AND A POINT IN BUCKET IS IN THE GIVEN RADIUS
        if(calculate_distance(query_point, point_vector_get_point(hyperCube_get_point(g, i) - 1), 2) < radius){
            //ADD THE POINT TO POINTS IN RANGE
            points_in_range.push_back(hyperCube_get_point(g, i));
            retrieved_items++;

            if(retrieved_items == max_retrieved_items){

                return points_in_range;
            }
        }

    }

    //FOR ALL THE RELATIVE BUCKETS OF QUERY POINT
    for(int i = 0; i < relative_buckets_indexes.size(); i++){
        //FOR ALL THEIR ELEMENTS
        for(int j = 0; j < hyperCube_get_bucket_size(relative_buckets_indexes[i]); j++){
            //IF DISTANCE BETWEEN QUERY POINT AND A POINT IN RELATIVE BUCKET IS IN THE RADIUS
            if(calculate_distance(query_point, point_vector_get_point(hyperCube_get_point(relative_buckets_indexes[i], j) - 1), 2) < radius){
                //ADD IT TO POINTS IN RANGE
                points_in_range.push_back(hyperCube_get_point(relative_buckets_indexes[i], j));
                retrieved_items++;

                if(retrieved_items == max_retrieved_items){

                    return points_in_range;
                }
            }
        }
    }

    return points_in_range;
}