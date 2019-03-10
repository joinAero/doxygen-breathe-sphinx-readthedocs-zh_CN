#pragma once

#include <algorithm>
#include <iterator>

namespace stream {

/**
 * 用于累加数据的函数对象。
 */
template <typename T>
struct Sum {
  /**
   * 构造函数。
   */
  Sum() : sum{Zero()} {}
  /**
   * 获取初始值。
   * @return 初始值。
   */
  T Zero() { return 0; }
  /**
   * 调用操作符，用于累加数据。
   * @param n 累加的数据。
   */
  void operator()(T n) { sum += n; }

  T sum;  /**< 和。 */
};

/**
 * 求给到数据的和。
 * @param first 数据起始。
 * @param last 数据结束。
 * @return 和。
 */
template <typename It,
          typename Result = typename std::iterator_traits<It>::value_type>
Result accumulate(It first, It last) {
  using value_type = typename std::iterator_traits<It>::value_type;
  return std::for_each(first, last, Sum<value_type>()).sum;
}

/**
 * 求给到数据的平均数。
 * @param first 数据起始。
 * @param last 数据结束。
 * @return 平均数。
 */
template <typename It,
          typename Result = typename std::iterator_traits<It>::value_type>
Result average(It first, It last) {
  typename std::iterator_traits<It>::difference_type n =
      std::distance(first, last);
  Result result = 1;
  return result * accumulate(first, last) / n;
}

/**
 * 求给到数据的平均数（浮点型）。
 * @param first 数据起始。
 * @param last 数据结束。
 * @return 平均数（浮点型）。
 */
template <typename It>
float average_float(It first, It last) {
  return average<It, float>(first, last);
}

}  // namespace stream
