#include <nan.h>
#include "addWorker.h"

using v8::Local;
using v8::Handle;
using v8::Object;
using v8::Number;
using v8::String;
using v8::FunctionTemplate;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_METHOD(Add) {
	if (info.Length() < 2) {
		Nan::ThrowTypeError("Wrong number of arguments");
		return;
	}
	if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
		Nan::ThrowTypeError("Wrong type of arguments");
		return;
	}

	double arg0 = info[0]->NumberValue();
	double arg1 = info[1]->NumberValue();
	Local<Number> num = New(arg0 + arg1);

	info.GetReturnValue().Set(num);
}

NAN_MODULE_INIT(Init) {
	Set(target, New("add").ToLocalChecked(),
		GetFunction(New<FunctionTemplate>(Add)).ToLocalChecked());
	Set(target, New("addAsync").ToLocalChecked(),
		GetFunction(New<FunctionTemplate>(AddAsync)).ToLocalChecked());
}

NODE_MODULE(addAsync, Init)

