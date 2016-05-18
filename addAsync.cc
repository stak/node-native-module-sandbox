#include <nan.h>

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
	v8::Local<v8::Number> num = Nan::New(arg0 + arg1);

	info.GetReturnValue().Set(num);
}

NAN_MODULE_INIT(Init) {
	Nan::Set(target, Nan::New("add").ToLocalChecked(),
			 Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Add)).ToLocalChecked());
}

NODE_MODULE(addAsync, Init)

