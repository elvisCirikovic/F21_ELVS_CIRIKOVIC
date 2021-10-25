#pragma once

#include "MirageUtils.h"

namespace Mirage
{
	class MIRAGE_API MirageApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	protected:
		MirageApp();

	private:

	};
}
