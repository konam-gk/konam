#ifndef OBJ_FILE_H
#define OBJ_FILE_H

#include <fstream>
#include <sstream>
#include <vector>
#include "vertex.h"
#include "line.h"

class OBJ_File
{
public:
    static void read_file(std::string filename, std::vector<Vertex>& vertices, std::vector<Line<2>>& lines)
    {
        lines.clear();
        vertices.clear();

        std::string line{};
        char c{};
        int i{}, j{};
        unsigned int numV{}, numL{};
        double x{}, y{}, z{};
        std::string si{}, sj{};

        std::ifstream in(filename);
        while (std::getline(in, line))                         // read whole line
        {
            if (line.find_first_of("vVlL") == std::string::npos) continue;     // skip pointless lines

            std::istringstream ss(line);                       // put line into a stream for input
            ss >> c;                                           // get first character
            switch (c) {
            case 'v':                                          // VERTICES
            case 'V':                                          //   (either case)
                ss >> x >> y >> z;                             // read from internal stream
                vertices.push_back({ ++numV, x, y, z });       // add to vector
                break;
            case 'l':                                          // LINES
            case 'L':                                          //   (either case)
                ss >> si >> sj;                                // FIRST, read into individual strings
                i = std::stoi(si);                             // Get the FIRST integer from each string
                j = std::stoi(sj);                   
                lines.push_back({ ++numL, vertices[i - 1], vertices[j - 1] });  // add to vector
                break;
            }
        }
        in.close();
    }
};


#endif // !OBJ_FILE_H