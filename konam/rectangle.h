#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <string>


class Rectangle
{
protected:

	Rectangle();	// ???

	//void calculator_of_properties(const double value, Cross_Section::Parameter dimension);
	void calculator_of_properties(const double value, const std::string& prop);


public:

	int get_cross_section_number() const;
	int get_material_number() const;
	double get_width() const;
	double get_height() const;
	//double get_radius() const;
	//double get_diameter() const;
	double get_perimeter() const;
	double get_area() const;
	double get_moment_of_inertia_y() const;
	double get_moment_of_inertia_z() const;
	double get_moment_of_inertia_yz() const;
	double get_torsion_moment_of_inertia() const;
	double get_shear_area_y() const;
	double get_shear_area_z() const;
	std::string get_title() const;

	void set_cross_section_number(unsigned int value);
	void set_material_number(int value);
	void set_width(double value);
	void set_height(double value);
	void set_title(std::string title);
	void set_all_parameters_to_default();


private:

	int m_cross_section_number;
	int m_material_number;
	double m_width;
	double m_height;
	double m_perimeter;
	double m_area;
	double m_moment_of_inertia_y;
	double m_moment_of_inertia_z;
	double m_moment_of_inertia_yz;
	double m_torsion_moment_of_inertia;
	double m_shear_area_y;
	double m_shear_area_z;
	std::string m_title;

	inline void save_in_container();

};


#endif // !RECTANGLE_H