#pragma once

#include <cstdint>
#include <vector>
#include <array>
#include <string>
#include <memory>
#include <map>

using std::array;
using std::make_shared;
using std::map;
using std::string;
using std::vector;

static constexpr unsigned int S_KEY_SIZE = 32;
static constexpr unsigned int S_BLOCK_SIZE = 16;

using byte = uint8_t;
using bytes = std::vector<uint8_t>;

template <class T>
using ptr = std::shared_ptr<T>;