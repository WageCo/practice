#ifndef __MY_HELPER_VERSION_H__
#define __MY_HELPER_VERSION_H__

namespace helper {
namespace version {
constexpr int MAJOR_VERSION = 0;
constexpr int MINOR_VERSION = 1;
inline const int get_major_version() { return MAJOR_VERSION; }
inline const int get_minor_version() { return MINOR_VERSION; }
} // namespace version
} // namespace helper
#endif // __MY_HELPER_VERSION_H__