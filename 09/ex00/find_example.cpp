#include <iostream>
#include <set>

class Data
{
	private:
		std::string	_str;
		double		_value;


	public:
	Data(std::string str, double value): _str(str), _value(value){}
	double	getValue() const {return (_value);}
	bool	operator<(const Data & rhs) const
	{
		if (_str < rhs._str)
			return (true);
		return (false);
	}
	bool	operator==(const Data & rhs) const
	{
		if (_str == rhs._str)
			return (true);
		return (false);
	}
};

int main()
{
	std::multiset<Data>	set;

	Data	element("string", 42);

	set.insert(element);

	Data	search("string", 0);

	if (set.find(search) != set.end())
		std::cout << "Found Data inside set! Value: " << set.find(search)->getValue() << std::endl;
	else
		std::cout << "Data not found in set" << std::endl;
	return (0);
}