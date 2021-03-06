#include "hashTable.h"

void hashTable_initialization(int num_of_hashTables, int num_of_buckets){

    //INITIALIZE L HASHTABLES WITH HASHTABLESIZE BUCKETS AND 1 POINT (WITH ID 0) IN EACH BUCKET
    HashTables.resize(num_of_hashTables, vector<vector<int> >(num_of_buckets, vector<int>(0)));
    //IT CAN ALSO BE INITIALIZED AS ZERO
}

//PUSH A POINT'S ID VALUE TO A BUCKET OF EACH OF THE HASHTABLES USING 
//EACH BUCKET IS INDICATED BY THE INT VALUES PRODUCED BY FUNCTION G
void hashTable_push_back(vector<int>& g, int key_val){

    for(int i = 0; i < HashTables.size(); i++){
        HashTables[i][g[i]].push_back(key_val);
        //HashTables[i][g[i]].end() = key_val;
    }
}

//GET KEY VALUES OF ALL THE POINTS OF A BUCKET OF EACH HASH TABLE
//EACH BUCKET IS INDICATED BY THE INT VALUES PRODUCED BY FUNCTION G 
vector<int> hashTable_get_points_in_buckets(vector<int>& g){

    vector<int> points_in_buckets;

    for(int i = 0; i < HashTables.size(); i++){
        for(int j = 0; j < HashTables[i][g[i]].size(); j++){
            //INSERT THE NUMBER OF HASHTABLE OF THE POINT (USE TO GET APPROPRIATE ID VALUE)
            points_in_buckets.push_back(i);
            //PUSH THE ID OF THE POINT TO POINTS IN HASHTABLE BUCKETS
            points_in_buckets.push_back(HashTables[i][g[i]][j]);
        }
    }

    return points_in_buckets;
}

//GET NUMBER OF HASHTABLES - L
int hashTable_get_num_of_htables(){

    return HashTables.size();
}

//GET NUMBER OF POINTS IN A HASHTABLE BUCKET
int hashTable_get_bucket_size(int htable_num, int bucket){

    return HashTables[htable_num][bucket].size();
}

//GET A SPECIFIC POINT FROM A HASHTABLE BUCKET
int hashTable_get_point(int htable_num, int bucket, int place){

    return HashTables[htable_num][bucket][place];
}

//PRINT HASHTABLES DATA - USED FOR CHECKING PURPOSES
void hashTable_print_data(){
    for (int i = 0; i < HashTables.size(); i++) {
        for (int j = 0; j < HashTables[i].size(); j++){
            for(int k = 0; k < HashTables[i][j].size(); k++){
                cout<< HashTables[i][j][k] << " ";
            }
        }
        cout << endl;
    }
    cout << "Hashtable size is: " << HashTables.size() << endl;
    cout << "buckets of each hashtable are: " << HashTables[0].size() << endl;
    cout << "elements in each bucket are: " << HashTables[0][0].size() << endl;
}