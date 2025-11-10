#pragma once
#include <string>
#include "SplayTree.hpp"
#include "KeyValuePair.hpp"

class TreeMap {
private:
    SplayTree<KeyValuePair> tree_;

public:
    TreeMap() = default;

    void insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    void deleteKey(const std::string& key);
};