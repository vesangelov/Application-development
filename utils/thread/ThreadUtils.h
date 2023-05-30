#ifndef UTILS_THREAD_THREADUTILS_H_
#define UTILS_THREAD_THREADUTILS_H_

#include <cstdint>

class Threading{
public:
  Threading() = delete;

  static void sleepFor(int64_t microseconds);
};

#endif /*UTILS_THREAD_THREADUTILS_H_*/