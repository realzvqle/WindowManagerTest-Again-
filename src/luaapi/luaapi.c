#include "luaapi.h"
#include "../task/tasks.h"
#include "../drawing/misc.h"




int LuaCreateTask(lua_State *L) {
    const char* text = luaL_checkstring(L, 1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    //ZiCreateTask(x, y, text);
    lua_pushnil(L);
    return 0;
}


int LuaDrawButton(lua_State *L) {
    const char* text = luaL_checkstring(L, 1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);
    int sizeX = luaL_checkinteger(L, 4);
    int sizeY = luaL_checkinteger(L, 5);
    Color baseColor = GetColor(luaL_checkinteger(L, 6));
    Color textColor = GetColor(luaL_checkinteger(L, 7));
    Color hoverColor = GetColor(luaL_checkinteger(L, 8));
    int textSize = luaL_optinteger(L, 9, 0);
    ButtonState state = ZiDrawButton((char*)text, x, y, sizeX, sizeY, baseColor, textColor, hoverColor, textSize);
    lua_pushinteger(L, state);
    return 1;
}




int LuaCreateColor(lua_State* L){
    int r = luaL_checkinteger(L, 1);
    int g = luaL_checkinteger(L, 2);
    int b = luaL_checkinteger(L, 3);
    int a = luaL_checkinteger(L, 4);
    Color color = ZiCreateColor(r,g,b,a);
    lua_pushinteger(L, ZiColorToHex(color));
    return 1;
}