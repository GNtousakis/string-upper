#include <nan.h>
#include <string>
#include <cctype>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

/**
* simple function to be export from this c++ code
**/
void UpperString(const FunctionCallbackInfo<Value>& args){
  Isolate* isolate = args.GetIsolate();
  
  // Check the number of arguments passed.
  if (args.Length() == 0 || !args[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  if (args[0]->IsString()) {
    String::Utf8Value tmp(args[0]->ToString());
    // Change string to c++ type
    std::string str = std::string(*tmp); 

    // Make letters uppercase
    for (int inner = 0; inner < str.length(); inner++)
    {
      str[inner] = toupper(str[inner]);
    }
    // Revert to v8 string and return 
    v8::Local<v8::String> v8String = v8::String::NewFromUtf8(isolate, str.c_str(), v8::String::kNormalString);
    args.GetReturnValue().Set(v8String);
  }

}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "UpperString", UpperString);//NODE_SET_MET  HOD to export
}

//to define entry point,first argument must match with target name in binding.gyp
NODE_MODULE(UpperCaseString, Init)
