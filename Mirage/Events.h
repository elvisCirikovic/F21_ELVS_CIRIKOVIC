#pragma once

#include "MirageUtils.h"

namespace Mirage
{
	class MIRAGE_API KeyPressedEvent
	{

	public:

		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:

		int mKeyCode{ -1 };
	};

}