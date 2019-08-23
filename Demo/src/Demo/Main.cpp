#include <OvWindowing/Window.h>
#include <OvWindowing/Inputs/InputManager.h>

#include <Baguette/Foo.h>

int main()
{
	auto deviceSettings = OvWindowing::Settings::DeviceSettings{};
	auto windowSettings = OvWindowing::Settings::WindowSettings{};

	deviceSettings.contextMajorVersion = 4;
	deviceSettings.contextMinorVersion = 3;
	
	windowSettings.width = 1600;
	windowSettings.height = 900;
	windowSettings.title = "Baguette - Demo";

	auto device = OvWindowing::Context::Device(deviceSettings);
	auto window = OvWindowing::Window(device, windowSettings);
	auto inputManager = OvWindowing::Inputs::InputManager(window);

	while (!window.ShouldClose())
	{
		inputManager.ClearEvents();
		device.PollEvents();

		Baguette::SayFoo();

		window.SwapBuffers();
	}

	return EXIT_SUCCESS;
}