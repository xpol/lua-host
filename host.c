#include <lua.h>
#include <lauxlib.h>

#include "lj_arch.h"

#if LJ_ARCH_ENDIAN == LUAJIT_LE
#define ENDIAN "little"
#else
#define ENDIAN "big"
#endif

int luaopen_host(lua_State* L) {
    lua_newtable(L);

    lua_pushliteral(L, LJ_OS_NAME);
    lua_setfield(L, -2, "os");

    lua_pushliteral(L, LJ_ARCH_NAME);
    lua_setfield(L, -2, "arch");

    lua_pushinteger(L, LJ_ARCH_BITS);
    lua_setfield(L, -2, "bits");

    lua_pushliteral(L, ENDIAN);
    lua_setfield(L, -2, "endian");

    return 1;
}
