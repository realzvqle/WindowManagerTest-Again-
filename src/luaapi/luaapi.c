#include "luaapi.h"
#include "../task/tasks.h"





int LuaCreateTask(lua_State *L) {
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3) + 90;
    const char* text = luaL_checkstring(L, 1);
    ZiCreateTask(x, y, text);
    lua_pushnil(L);
    return 0;
}
