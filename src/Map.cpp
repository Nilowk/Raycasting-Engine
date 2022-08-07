#include "../headers/Map.hpp"
#include "../headers/Variable.hpp"
#include <iostream>
#include <regex>
#include <windows.h>
#include <fstream>

Map::Map(sf::RenderWindow &window) : window(window) {

    generateMap();

}

void Map::generateMap() {

    system("py ../python/map_spliter.py");

    std::vector<std::string> lines;
    std::string line;
    std::ifstream file("../python/map-info.txt");

    if (file) {

        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        for (int i(0); i < lines.size(); ++i) {

            std::string l = lines[i];

            std::regex regex("\\-");

            std::vector<std::string> out(
                    std::sregex_token_iterator(l.begin(), l.end(), regex, -1),
                    std::sregex_token_iterator()
            );

            if (i <= 15 && i >= 0) {
                std::vector<Cell> vec;
                cells.push_back(vec);
            }

            sf::Vector2i coords(std::stoi(out[1]), std::stoi(out[0]));

            if (out[2] == "empty") {

                Cell cell(window, coords);
                cells[std::stoi(out[0])].push_back(cell);

            } else {

                sf::Texture texture;
                texture.loadFromFile("../textures/block.png");
                Cell cell(window, coords, texture);
                cells[std::stoi(out[0])].push_back(cell);

            }

        }

    } else {

        std::cout << "error: can't open file" << std::endl;

    }

    file.close();

    WinExec("python ../python/map_info_cleaner.py", 1);

}

void Map::draw() {

    for (auto& line : cells) {

        for (auto& cell : line) {

            cell.draw();

        }

    }

}

bool Map::isCollide(unsigned int x, unsigned int y) {

    return !(cells[y][x].isEmpty());

}