/* cppsrc/main.cpp */
#include <napi.h> // node - api module includes the napi header file so that we can access all the helper macros (#define ls = x.y.z), classes and functions.
#include "src/bindings.h"
Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  
  
  return JsonSki::Init(env, exports);



}

NODE_API_MODULE(JSONSki, InitAll)
//InitAll and it takes two parameters which are passed by N-API. 
//First parameter env is the context that needs to be passed on to most N-API function and exports is the object used to set 
//the exported functions and classes via N-API.
// NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

/**
* This code defines the entry-point for the Node addon, it tells Node where to go
* once the library has been loaded into active memory. The first argument must
* match the "target" in our *binding.gyp*. Using NODE_GYP_MODULE_NAME ensures
* that the argument will be correct, as long as the module is built with
* node-gyp (which is the usual way of building modules). The second argument
* points to the function to invoke. The function must not be namespaced.
*/
