#pragma once
#include <string>

class KeyValuePair {
private:
    std::string key_;
    std::string value_;

public:
    KeyValuePair() = default;
    KeyValuePair(const std::string &k, const std::string &v)
        : key_(k), value_(v) {}

    const std::string& key() const { return key_; }
    const std::string& value() const { return value_; }

    void setValue(const std::string &v) { value_ = v; }

    bool operator<(const KeyValuePair &other) const { return key_ < other.key_; }
    bool operator>(const KeyValuePair &other) const { return key_ > other.key_; }
    bool operator==(const KeyValuePair &other) const { return key_ == other.key_; }
    bool operator!=(const KeyValuePair &other) const { return key_ != other.key_; }
};