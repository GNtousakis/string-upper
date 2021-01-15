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
NAN_METHOD (UpperString) {
  Isolate* isolate = info.GetIsolate();
  
  // Check the number of arguments passed.
  if (info.Length() == 0 || !info[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  if (info[0]->IsString()) {
    String::Utf8Value tmp(info[0]->ToString());
    // Change string to c++ type
    std::string str = std::string(*tmp); 

    // Make letters uppercase
    for (int inner = 0; inner < str.length(); inner++)
    {
      str[inner] = toupper(str[inner]);
    }
    // Revert to v8 string and return 
    v8::Local<v8::String> v8String = v8::String::NewFromUtf8(isolate, str.c_str(), v8::String::kNormalString);
    info.GetReturnValue().Set(v8String);
  }

}

NAN_MODULE_INIT(Init) 
{
  NAN_EXPORT(target, UpperString);
}

//to define entry point,first argument must match with target name in binding.gyp
NODE_MODULE(UpperCaseString, Init)
