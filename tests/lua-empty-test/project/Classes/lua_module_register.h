#ifndef __TEST_LUA_TESTS_PROJECT_CLASSES_LUA_MODULE_REGISTER_H__
#define __TEST_LUA_TESTS_PROJECT_CLASSES_LUA_MODULE_REGISTER_H__

#include "lua-bindings/manual/cocos2d/lua_cocos2dx_manual.hpp"


int lua_module_register(lua_State* L)
{
    register_all_cocos2dx_module_manual(L);
    return 1;
}

#endif  // __TEST_LUA_TESTS_PROJECT_CLASSES_LUA_MODULE_REGISTER_H__

