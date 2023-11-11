#include <I3ean.h>

class Sandbox : public I3ean::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

I3ean::Application* I3ean::CreateApplication() {
	return new Sandbox();
}