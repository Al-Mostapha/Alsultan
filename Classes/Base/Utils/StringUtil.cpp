#include "String.Util.h"
#include <stdexcept>


GVector<GString> GStringUtils::Split(GString s, GString delimiter){
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  GString token;
  GVector<GString> res;
  while ((pos_end = s.find (delimiter, pos_start)) != GString::npos) {
      token = s.substr (pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back (token);
  }
  res.push_back (s.substr (pos_start));
  return res;
}

bool GStringUtils::Replace(GString& str, const GString& from, const GString& to) {
  size_t start_pos = str.find(from);
  if(start_pos == GString::npos)
      return false;
  str.replace(start_pos, from.length(), to);
  return true;
}