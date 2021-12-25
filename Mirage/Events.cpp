#include "pch.h"
#include "Events.h"

namespace Mirage
{
	KeyPressedEvent::KeyPressedEvent(int keyCode) : mKeyCode(keyCode)
	{
	}
	int KeyPressedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
}