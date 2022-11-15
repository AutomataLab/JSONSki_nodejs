#include <napi.h>
namespace JsonSki {
  using namespace JsonSki;
    std :: string JSONSkiParser(std :: string query, std :: string file_path);
    Napi::String JSONSkiParserWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
  } 