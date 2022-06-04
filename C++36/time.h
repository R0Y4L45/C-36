#pragma once



class Time
{
	typedef unsigned short ushort;
	ushort _hours = 0;
	ushort _minutes = 0;
	ushort _seconds = 0;

public:

	Time() = default;

	Time(ushort hours, ushort minutes, ushort seconds)
	{
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}


	void setHours(ushort hours)
	{
		if (hours >= 0)
		{
			_hours = hours;
		}
	}

	void setMinutes(ushort minutes)
	{
		if (minutes >= 0)
		{
			_minutes = minutes;
		}
	}

	void setSeconds(ushort seconds)
	{
		if (seconds >= 0)
		{
			_seconds = seconds;
		}
	}


	bool operator!() const
	{
		if (_hours == 0 && _minutes == 0 && _seconds == 0)
			return true;
		return false;
	}


	Time operator>(const Time& f) const
	{
		int sum = _hours + _minutes + _seconds;
		int sum1 = f._hours + f._minutes + f._seconds;
		return sum > sum1 ? *this : f;
	}

	Time operator<(const Time& f) const
	{
		int sum = _hours + _minutes + _seconds;
		int sum1 = f._hours + f._minutes + f._seconds;
		return sum < sum1 ? f : *this;
	}


	Time operator+(Time& other) const
	{
		Time res(_hours + other._hours, _minutes + other._minutes, _seconds + other._seconds);
		if ((_hours + other._hours) > 23)
			res._hours = 0;
		if ((_minutes + other._minutes) > 59)
			res._minutes = 0;
		if ((_seconds + other._seconds) > 59)
			res._seconds = 0;

		return res;
	}

	Time& operator++()
	{
		++_hours;
		++_minutes;
		++_seconds;
		if (1 + _hours > 23)
			_hours = 0;
		if (1 + _minutes > 59)
			_minutes = 0;
		if (1 + _seconds > 59)
			_seconds = 0;
		return *this;
	}

	Time operator++(int)
	{
		Time temp = *this;

		_hours++;
		_minutes++;
		_seconds++;

		if (1 + temp._hours > 23)
			_hours = 0;
		if (1 + temp._minutes > 59)
			_minutes = 0;
		if (1 + temp._seconds > 59)
			_seconds = 0;

		return temp;
	}


	void operator()()
	{
		cout << "Clock => " << _hours << ':' << _minutes << ':' << _seconds << endl;
	}

};

