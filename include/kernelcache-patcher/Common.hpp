#pragma once

#include <cstdint>
#include <string>
#include <string_view>

#define KCPATCHER_EXPORT __attribute__((visibility("default")))
#define KCPATCHER_INLINE __attribute__((always_inline))
// #define KCPATCHER_INLINE
#define KCPATCHER_NOINLINE __attribute__((noinline))
#define KCPATCHER_LIKELY(cond) __builtin_expect((cond), 1)
#define KCPATCHER_UNLIKELY(cond) __builtin_expect((cond), 0)
#define KCPATCHER_BREAK() __builtin_debugtrap()
#define KCPATCHER_ALIGNED(n) __attribute__((aligned(n)))
#define KCPATCHER_ASSUME_ALIGNED(ptr, n) __builtin_assume_aligned((ptr), n)
#define KCPATCHER_UNREACHABLE() __builtin_unreachable()
