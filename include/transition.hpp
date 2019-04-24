#pragma once
#include <chrono>
#include <cmath>

namespace trn
{

template<typename T>
class Transition
{
public:
	using ChronoPoint = std::chrono::steady_clock::time_point;

	Transition()
		: m_start_value()
		, m_current_value()
		, m_target_value()
		, m_delta()
		, m_start_time(std::chrono::steady_clock::now())
		, m_speed(0.0f)
	{
		updateDelta();
	}

	Transition(const T& value, float speed = 1.0f)
		: m_start_value(value)
		, m_current_value(value)
		, m_target_value(value)
		, m_delta()
		, m_start_time(std::chrono::steady_clock::now())
		, m_speed(speed)
	{
		updateDelta();
	}

	template<typename... Args>
	explicit Transition(Args&&... args) :
		m_start_value(std::forward<Args>(args)...),
		m_current_value(m_start_value),
		m_target_value(m_start_value),
		m_start_time(std::chrono::steady_clock::now()),
		m_speed(1.0f)
	{
		updateDelta();
	}

	operator const T&() const
	{
		autoUpdate();
		return m_current_value;
	}

	void operator=(const T& value)
	{
		m_target_value = value;
		restart();
	}

	template<typename U>
	void operator+=(const U& value)
	{
		m_target_value += value;
		restart();
	}

	template<typename U>
	void operator-=(const U& value)
	{
		m_target_value -= value;
		restart();
	}

	void setValueInstant(const T& value)
	{
		m_current_value = value;
		m_target_value = value;
	}

	void setSpeed(float s)
	{
		m_speed = s;
	}

private:
	T m_start_value;
	T m_target_value;
	T m_delta;
	mutable T m_current_value;

	ChronoPoint m_start_time;
	float m_speed;

	void autoUpdate() const
	{
		ChronoPoint now(std::chrono::steady_clock::now());
		double t(static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(now - m_start_time).count()));
		if (t > 1.0f)
		{
			m_current_value = m_start_value + m_delta * ratio(t * 0.001f * m_speed);
		}
	}

	static float ratio(float t)
	{
		return 1.0f / (1.0f + std::expf(-(10.0f*t - 5.0f)));
	}

	void restart()
	{
		m_start_value = m_current_value;
		m_start_time = std::chrono::steady_clock::now();
		updateDelta();
	}

	void updateDelta()
	{
		m_delta = m_target_value - m_start_value;
	}
};



}




