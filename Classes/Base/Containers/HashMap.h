#pragma once
#include <unordered_map>

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

template <typename Key>
using HashType = typename std::conditional<std::is_enum<Key>::value, EnumClassHash, std::hash<Key>>::type;

template <class K, class V>
class  GHashMap : public std::unordered_map<K, V, HashType<K>>{
public:
  bool Contains(K p_Key){
    return this->find(p_Key) != this->end();
  }

  std::vector<K> Keys(){
    std::vector<K> keys;
    for (auto it = this->begin(); it != this->end(); ++it) {
      keys.push_back(it->first);
    }
    return keys;
  }

  std::vector<V> Values(){
    std::vector<V> values;
    for (auto it = this->begin(); it != this->end(); ++it) {
      values.push_back(it->second);
    }
    return values;
  }
};