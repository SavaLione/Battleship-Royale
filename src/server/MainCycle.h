#pragma once

namespace Cycle
{
	class MainCycle
	{
	public:
		MainCycle();
		~MainCycle();
		// Server start
		void Start();
		// Main server loop
		void Update();
		// Server shutdown
		void End();

		// True if you need to exit the server
		bool Exit;
	};
}