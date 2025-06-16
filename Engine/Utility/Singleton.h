#pragma once
template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}

	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;
};