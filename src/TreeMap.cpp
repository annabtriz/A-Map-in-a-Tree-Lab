#include "TreeMap.hpp"

void TreeMap::insert(const std::string& key, const std::string& value) {
    tree_.insert(KeyValuePair(key, value));
}

std::string TreeMap::get(const std::string& key) {
    KeyValuePair temp(key, "");
    auto* node = tree_.find(temp);
    if (node == nullptr)
        return "";
    return node->value.value();
}

void TreeMap::deleteKey(const std::string& key) {
    KeyValuePair temp(key, "");
    tree_.remove(temp);
}