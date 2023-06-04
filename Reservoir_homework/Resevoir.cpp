#include "Resevoir.h"

bool is_equals_name(const Resevoir& r1, const Resevoir& r2)
{
	return (r1.name == r2.name);
}

bool is_equals_surface(const Resevoir& r1, const Resevoir& r2)
{
	if (is_equals_name(r1, r2))
		return r1.get_surface() == r2.get_surface();
	return false;
}

Resevoir& Resevoir::operator= (const Resevoir& copy)
{
	this->name = copy.name;
	this->length = copy.length;
	this->width = copy.width;
	this->depth = copy.depth;
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Resevoir& obj)
{
	out << "Тип: " << obj.name << std::endl;
	out << "Длина: " << obj.length << std::endl;
	out << "Ширина: " << obj.width << std::endl;
	out << "Глубина: " << obj.depth;
	return out;
}

std::istream& operator>> (std::istream& in, Resevoir& obj)
{
	in >> obj.name;
	in >> obj.length;
	in >> obj.width;
	in >> obj.depth;
	return in;
}

bool Save(const std::vector<Resevoir>& arr, const char* path)
{
	std::ofstream out;

	out.open(path);
	if (out.is_open())
	{
		for (int i{}; i < arr.size(); ++i)
		{
			out << arr[i];
			if (i != arr.size()-1)
				out << std::endl;
		}
		out.close();
		return true;
	}
	return false;
}

bool SaveBin(const std::vector<Resevoir>& arr, const char* path)
{
	std::fstream out;

	out.open(path, std::ios::out | std::ios::binary);
	if (out.is_open())
	{
		size_t temp = arr.size();
		out.write((char*)&temp, sizeof(size_t));
		for (int i{}; i < arr.size(); ++i)
		{
			size_t str_size = arr[i].name.size();
			out.write((char*)&str_size, sizeof(str_size));
			out.write(arr[i].name.c_str(), str_size);
			out.write((char*)&arr[i].length, sizeof(size_t));
			out.write((char*)&arr[i].width, sizeof(size_t));
			out.write((char*)&arr[i].depth, sizeof(size_t));
		}
		out.close();
		return true;
	}
	return false;
}

bool Load(std::vector<Resevoir>& arr, const char* path)
{
	std::ifstream in;
	
	in.open(path);
	if (in.is_open())
	{
		Resevoir temp;
		const unsigned short BUF = 256;
		arr.clear();
		while(!in.eof())
		{
			in.ignore(BUF, ' ');
			in >> temp.name;
			in.ignore(BUF, ' ');
			in >> temp.length;
			in.ignore(BUF, ' ');
			in >> temp.width;
			in.ignore(BUF, ' ');
			in >> temp.depth;
			arr.push_back(temp);
		}
		in.close();
		return true;
	}
	return false;
}

bool LoadBin(std::vector<Resevoir>& arr, const char* path)
{
	std::fstream in;

	in.open(path, std::ios::in | std::ios::binary);
	if (in.is_open())
	{
		Resevoir temp;
		size_t str_size{};
		const size_t BUF = 256;
		size_t count{};
		char str[BUF]{};
		

		arr.clear();
		in.read((char*)&count, sizeof(size_t));
		for (int i{}; i < count; ++i)
		{
			in.read((char*)&str_size, sizeof(size_t));
			in.read(str, str_size);
			temp.name = str;
			in.read((char*)&temp.length, sizeof(size_t));
			in.read((char*)&temp.width, sizeof(size_t));
			in.read((char*)&temp.depth, sizeof(size_t));
			arr.push_back(temp);
		}
		in.close();
		return true;
	}
	return false;
}
