#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Resevoir
{
private:
	std::string name;
	size_t length;
	size_t width;
	size_t depth;

public:
	explicit Resevoir(std::string name = "Пруд", size_t lenght = 10, size_t width = 10, size_t depth = 5) :
		name{ name }, length{ lenght }, width{ width }, depth{ depth } {}

public:
	size_t get_volume() const { return length * width * depth; }
	size_t get_surface() const { return length * width; }
	std::string get_name() const { return name; }
	size_t get_lenght() const { return length; }
	size_t get_width() const { return width; }
	size_t get_depth() const { return depth; }
	friend bool is_equals_name (const Resevoir& r1, const Resevoir& r2);
	friend bool is_equals_surface(const Resevoir& r1, const Resevoir& r2);
	Resevoir& operator= (const Resevoir& copy);
	friend std::ostream& operator<< (std::ostream& out, const Resevoir& obj);
	friend std::istream& operator>> (std::istream& out, Resevoir& obj);
	friend bool Save(const std::vector<Resevoir>& arr, const char* path);
	friend bool SaveBin(const std::vector<Resevoir>& arr, const char* path);
	friend bool Load(std::vector<Resevoir>& arr, const char* path);
	friend bool LoadBin(std::vector<Resevoir>& arr, const char* path);
};


