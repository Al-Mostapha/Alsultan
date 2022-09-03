#include <unordered_map>
template <class K, class V>
class GHashMap : public std::unordered_map<K, V>{

  bool Contains(K p_Key){
    return count(p_Key) != 0;
  }

};