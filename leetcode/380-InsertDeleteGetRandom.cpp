//
// Created by wu on 2022/4/6.
//

#include "leetcode.h"

class RandomizedSet {
public:
    int size;
    int vecsize;
    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {
        size = 0;
        vecsize = 0;
    }

    bool insert(int val) {
        if (mp.count(val))
            return false;
        if (size < vecsize)
            vec[size++] = val;
        else {
            vec.push_back(val);
            size++, vecsize++;
        }
        mp[val] = size-1;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;
        vec[mp[val]] = vec[size-1];
        mp[vec[size-1]] = mp[val];
        size--;
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return vec[rand()%size];
    }
};

int main(void) {
    RandomizedSet randomizedSet;
    randomizedSet.insert(0); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet.insert(1); // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet.remove(0); // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet.insert(2); // 2 was already in the set, so return false.
    randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    cout << randomizedSet.getRandom();

}