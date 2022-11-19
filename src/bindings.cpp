#include "bindings.h"
#include "../src/RecordLoader.h"
#include "../src/QueryProcessor.h"

std::string JsonSki::JSONSkiParser(std :: string query, std :: string file_paths){
    char* file_path = const_cast<char*>(file_paths.c_str());  
    Record* rec = RecordLoader::loadSingleRecord(file_path);
    if (rec == NULL) {
        cout<<"record loading fails."<<endl;
        return "";
    }
    QueryProcessor processor(query);
    std::string output = processor.runQuery(rec);

    return output;
}






Napi::String JsonSki::JSONSkiParserWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::String first = info[0].As<Napi::String>();
  Napi::String second = info[1].As<Napi::String>();
  std::string returnValue = JsonSki::JSONSkiParser(first.Utf8Value(), second.Utf8Value());
  return Napi::String::New(env, returnValue);
}

Napi::Object JsonSki::Init(Napi::Env env, Napi::Object exports)
{
  exports.Set("JSONSkiParser", Napi::Function::New(env, JsonSki::JSONSkiParserWrapped));
  return exports;
}

