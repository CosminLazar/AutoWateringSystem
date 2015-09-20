// 
// 
// 

#include "CpuSpinner.h"
CallbackRegistration* CpuSpinner::callbackRoot = NULL;

void CpuSpinner::RequestUpdate(const CallbackSetup &callbackSetup)
{
	CallbackRegistration* registration = new CallbackRegistration(callbackSetup);
	
	if (CpuSpinner::callbackRoot == NULL) {
		CpuSpinner::callbackRoot = registration;
	}
	else
	{
		CallbackRegistration* iterator = CpuSpinner::callbackRoot;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
		}
		iterator->next = registration;
	}
}

void CpuSpinner::Update()
{
	CallbackRegistration* iterator = CpuSpinner::callbackRoot;
	while (iterator != NULL)
	{
		iterator->callback.Invoke();
		iterator = iterator->next;
	}
}
