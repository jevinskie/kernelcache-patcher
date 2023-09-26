#include <kernelcache-patcher/kernelcache-patcher.hpp>

#undef NDEBUG
#include <cassert>
#include <charconv>
#include <string_view>
#include <system_error>

#include <fmt/format.h>

int main(int argc, const char **argv) {
    assert(argc == 2);
    const auto strnum = std::string_view{argv[1]};
    int num{};
    const auto [_, ec] = std::from_chars(strnum.cbegin(), strnum.cend(), num);
    assert(ec == std::errc{});
    fmt::print("orig dummy: {:d}\n", get_dummy());
    set_dummy(num);
    fmt::print("new dummy: {:d}\n", get_dummy());
    return 0;
}
