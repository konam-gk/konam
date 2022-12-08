#include <iostream>
#include "selements.h"
#include "kaNew.h"
#include "triangle.h"




int main()
{
    //auto gsd = GSDefinition::
    
    auto cs1 = Cross_Section::Circle();
    cs1->set_radius(20.5);
    cs1->get_area();
    auto const matNum = cs1->get_material_number();
    
    SPoint sp1(1, 0.0, 0.0, 0.0);
    SPoint sp2(2, 1.0, 0.0, 0.0);

    SLine sl1(1, sp1, sp2);
    sl1.length();

    auto test = kaNew<SLine>();
    test->set_number(3);
    test->add_start_point(sp1);
    test->add_end_point(sp2);
    test->add_section_at_start(matNum);
    test->add_section_at_end(matNum);
    

    //auto sp1 = SElements::SPoint();
    //sp1->add_coordinates(0.0, 0.0, 0.0);
    //sp1->add_number(1);

    //auto sp2 = SElements::SPoint();
    //sp2->add_coordinates(1.0, 0.0, 0.0);
    //sp2->add_number(2);

/*    auto sl1 = SElements::SLine();
    sl1->add_element_type(SLine::Type::BEAM);
    sl1->set_number(1);
    sl1->add_start_point(*sp1);
    sl1->add_end_point(*sp2);
    sl1->length(); */  

    Triangle3n tr();
    Triangle<3> tr2();

}