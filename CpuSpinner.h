// CpuSpinner.h

#ifndef _CPUSPINNER_h
#define _CPUSPINNER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

typedef void(*CallbackFunc)(void *instance);

struct CallbackSetup {
	void *instance;
	CallbackFunc callbackFn;

	CallbackSetup(void *instance, CallbackFunc callbackFn)
		: instance(instance), callbackFn(callbackFn)
	{ }

	void Invoke() {
		this->callbackFn(this->instance);
	}
};

struct CallbackRegistration {
	CallbackSetup callback;
	CallbackRegistration *next;

	CallbackRegistration(const CallbackSetup& callbackSetup)
		: callback(callbackSetup), next(NULL)
	{ }
};

class CpuSpinner {
public:

	static void RequestUpdate(const CallbackSetup &callbackSetup);
	static void Update();
private:
	static CallbackRegistration* callbackRoot;
};

#endif

