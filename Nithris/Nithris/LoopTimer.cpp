////////////////////////////////////////////////////////////////////////////////
//																			  //
//	File: loopTimerSDL.cpp													  //
//																			  //
//	Original author: Tomas Sandnes / NITH / 2007-2011						  //
//	Changed by: Stig M. Halvorsen  / NITH / 2013							  //
//																			  //
//	Descr.: A helper class for gameLoop timing.								  //
//																			  //
//	Special notes: Requires the SDL library.								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

// I N C L U D E S
// ===============

#include "loopTimer.h"

// P U B L I C   F U N C T I O N S
// ===============================

LoopTimer::LoopTimer(unsigned short usWantedUpdatesPerInterval,    // Defaults to 60.
					 unsigned short usIntervalTimeInMilliSeconds)  // Defaults to 1000.
{
	// Calling own functions instead of setting variables directly to verify valid input.
	SetUpdatesPerInterval(usWantedUpdatesPerInterval);
	SetIntervalDuration(usIntervalTimeInMilliSeconds);

	// Setting the rest of the variables to default values.
	m_usUpdatesLastInt = 0;
	m_usUpdatesCurrInt = 0;
	m_ui32CurrIntStartTick = SDL_GetTicks();
	m_ui32NextIntStartTick = m_ui32CurrIntStartTick + m_usIntDur;
	m_ui32NextUpdateTick = m_ui32CurrIntStartTick + ((m_usUpdatesCurrInt + 1) * m_usIntDur / m_usWantedUPI);

}  // END LoopTimer

LoopTimer::~LoopTimer()
{
}  // END ~LoopTimer

void LoopTimer::SetUpdatesPerInterval(unsigned short usWantedUPI) 
{ 
	if ((1 > usWantedUPI))
	{
		m_usWantedUPI = 1;
	}
	else
	{
		m_usWantedUPI = usWantedUPI;
	}

}  // END SetUpdatesPerInterval

void LoopTimer::SetIntervalDuration(unsigned short usIntDurInMilliSecs) 
{ 
	if ((1 > usIntDurInMilliSecs))
	{
		m_usIntDur = 1;
	}
	else
	{
		m_usIntDur = usIntDurInMilliSecs;
	}

}  // END SetIntervalDuration

void LoopTimer::Start()
{
	m_usUpdatesLastInt = 0;
	m_usUpdatesCurrInt = 0;
	m_ui32CurrIntStartTick = SDL_GetTicks();
	m_ui32NextIntStartTick = m_ui32CurrIntStartTick + m_usIntDur;
	m_ui32NextUpdateTick = m_ui32CurrIntStartTick + ((m_usUpdatesCurrInt + 1) * m_usIntDur / m_usWantedUPI);

}  // END Start

void LoopTimer::SleepUntilUpdate()
{
	// Sleep until it's time for coming update.
	long lTicksRemaining = m_ui32NextUpdateTick - SDL_GetTicks();
	if (0 < lTicksRemaining)
	{
		SDL_Delay(lTicksRemaining);
	}

	// Sleep done - update variables so they're ready for the next update again.
	++m_usUpdatesCurrInt;
	m_ui32NextUpdateTick = m_ui32CurrIntStartTick + ((m_usUpdatesCurrInt + 1) * m_usIntDur / m_usWantedUPI);
	while (m_ui32NextUpdateTick > m_ui32NextIntStartTick)
	{
		m_ui32CurrIntStartTick = m_ui32NextIntStartTick;
		m_ui32NextIntStartTick += m_usIntDur;
		m_usUpdatesLastInt = m_usUpdatesCurrInt;
		m_usUpdatesCurrInt = 0;
	}

}  // END SleepUntilUpdate

bool LoopTimer::IsTimeForUpdate()
{
	bool r_bDoUpdate = false;

	if (SDL_GetTicks() >= m_ui32NextUpdateTick)
	{
		r_bDoUpdate = true;

		// Update variables so they're ready for the next update again.
		++m_usUpdatesCurrInt;
		m_ui32NextUpdateTick = m_ui32CurrIntStartTick + ((m_usUpdatesCurrInt + 1) * m_usIntDur / m_usWantedUPI);
		while (m_ui32NextUpdateTick > m_ui32NextIntStartTick)
		{
			m_ui32CurrIntStartTick = m_ui32NextIntStartTick;
			m_ui32NextIntStartTick += m_usIntDur;
			m_usUpdatesLastInt = m_usUpdatesCurrInt;
			m_usUpdatesCurrInt = 0;
		}
	}

	return r_bDoUpdate;

}  // END IsTimeForUpdate