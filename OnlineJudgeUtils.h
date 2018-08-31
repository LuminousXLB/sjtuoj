#pragma once

#ifndef ONLINE_JUDGE
#define _freopen(fn) freopen(fn, "r", stdin);
#define _log(format, ...)                                               \
    fprintf(stderr, "[%s:%d] <%s> ", __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, format, ##__VA_ARGS__);                             \
    fprintf(stderr, "\n");
#else
#define _freopen(fn)
#define _log(format, ...)
#endif
