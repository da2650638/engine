#pragma once

#include "Action.h"
#include <functional>

namespace star
{
	class Object;

	class TimedAction : public Action
	{
	public:
		TimedAction(float32 seconds);
		TimedAction(
			const tstring & name,
			float32 seconds
			);

		virtual ~TimedAction();

		virtual void Initialize();

		virtual void Restart();
		virtual void Pause();
		virtual void Resume();

	protected:
		std::function<void()> m_Callback;

	private:
		static uint64 ID_COUNTER;
		tstring m_UniqueID;
		float32 m_Seconds;

		TimedAction & operator=(const TimedAction&);
		TimedAction & operator=(TimedAction&&);
		TimedAction(const TimedAction&);
		TimedAction(TimedAction&&);
	};
}
