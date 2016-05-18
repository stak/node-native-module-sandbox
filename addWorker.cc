#include <nan.h>
#include "addWorker.h"

using v8::Local;
using v8::Handle;
using v8::Value;
using v8::Object;
using v8::Number;
using v8::String;
using v8::FunctionTemplate;
using v8::Function;
using Nan::HandleScope;
using Nan::GetFunction;
using Nan::New;
using Nan::Null;
using Nan::Set;
using Nan::Callback;
using Nan::AsyncWorker;
using Nan::AsyncQueueWorker;

class AddWorker : public AsyncWorker {
	public:
		AddWorker(Callback *callback, double a, double b)
		: AsyncWorker(callback), _a(a), _b(b), _sum(0) {}
		~AddWorker() {}

		// Executed inside the worker-thread
		// DO NOT ACCESS V8 HERE
		void Execute() {
			_sum = _a + _b;
		}

		// Executed when the async work is complete
		// It is safe to use V8
		void HandleOKCallback() {
			HandleScope scope;

			const int argc = 1;
			Local<Value> argv[argc] = {
				New<Number>(_sum)
			};

			callback->Call(argc, argv);
		}

	private:
		double _a;
		double _b;
		double _sum;
};

NAN_METHOD(AddAsync) {
	if (info.Length() < 3) {
		Nan::ThrowTypeError("Wrong number of arguments");
		return;
	}
	if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
		Nan::ThrowTypeError("Wrong type of arguments");
		return;
	}
	if (!info[2]->IsFunction()) {
		Nan::ThrowTypeError("Wrong type of arguments");
		return;
	}

	double arg0 = info[0]->NumberValue();
	double arg1 = info[1]->NumberValue();
	Callback *callback = new Callback(info[2].As<Function>());
	AsyncQueueWorker(new AddWorker(callback, arg0, arg1));
}

