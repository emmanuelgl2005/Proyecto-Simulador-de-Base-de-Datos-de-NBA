#ifndef NBADATA_H_
#define NBADATA_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include "heap.h"

using namespace std;

class NBAdata {
public:
    float _3Ppercent;
    float _2Ppercent;
    string team;
    int rk; 
    int wins;
    int losses;

    NBAdata(); 
    NBAdata(float _3Ppercent, float _2Ppercent, const string& team, int rk);
    void sortBy3Ppercent(std::vector<NBAdata> &data);
    void sortBy2Ppercent(std::vector<NBAdata> &data);
    void sortByWins(vector<NBAdata> &data); 
    void sortByLosses(vector<NBAdata> &data);
    void searchTeam(const vector<NBAdata> &data); 
    void accessRk(const vector<NBAdata> &data); 
    void showMenu();
    void manageMenu(vector<NBAdata> &data, MaxHeap &favoriteHeap);
    void mergeSortBy3Ppercent(vector<NBAdata> &data, int left, int middle, int right);
    void mergeSortBy2Ppercent(vector<NBAdata> &data, int left, int middle, int right);
    void mergeSort(vector<NBAdata> &data, bool sortBy3);
    string toLowerCase(const string str);
    void selectFavoriteTeam(MaxHeap &favoriteHeap, const vector<NBAdata> &data);
    void viewFavoriteTeam(MaxHeap &favoriteHeap);
    void displayWithFavorite(const vector<NBAdata> &data, MaxHeap &favoriteHeap);
    void displaySortedWithFavorite(vector<NBAdata> &data, MaxHeap &favoriteHeap, bool sortBy3);
    void displayWinsWithFavorite(vector<NBAdata> &data, MaxHeap &favoriteHeap);
    void displayLossesWithFavorite(vector<NBAdata> &data, MaxHeap &favoriteHeap);  
    void saveReport(const vector<NBAdata> &data, MaxHeap &favoriteHeap, const string &filename);     
};

#endif /* NBADATA_H_ */