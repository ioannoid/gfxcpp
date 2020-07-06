#pragma once

#include <iostream>

class wtf {
public:
	wtf();

	std::function<void()> asdf = []() { printf("hello"); };
};

wtf::wtf() { }
